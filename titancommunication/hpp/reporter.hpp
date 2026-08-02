#pragma once

#include <iostream>
#include <vector>
#include <cstdint>
#include <chrono>
#include <thread>
#include <atomic>
#include <string>
#include <cstring>
#include <C:\Users\tjsda\source\repos\gtunerexternal\vcpkg_installed\x64-windows\include\hidapi\hidapi.h>
//this is the only library required by the titan reporter. you gotta link it urself.

#include "../header/constants.h"



struct TitanDeviceInfo {
    std::string manufacturer;
    std::string product;
    std::string serial_number;
};



class TitanReporter {
private:
    hid_device* handle;
    std::thread reader_thread;
    std::atomic<bool> thread_running;
    

    std::vector<uint8_t> construct_packet(const std::vector<float>& vals) {
        std::vector<uint8_t> pkt;
        pkt.reserve(65);

        pkt.insert(pkt.end(), { 0x00, 0x60, 0x00, 0x30, 0x00 });

        for (size_t i = 0; i < 48; ++i) {
            if (i < vals.size()) {
                float clamped = (std::max)(-100.0f, (std::min)(100.0f, vals[i]));
                int8_t signed_byte = static_cast<int8_t>(clamped);
                uint8_t raw_byte;
                std::memcpy(&raw_byte, &signed_byte, 1);
                pkt.push_back(raw_byte);
            }
            else {
                pkt.push_back(0x00);
            }
        }

        pkt.insert(pkt.end(), { 0, 0, 128, 231, 11, 55, 35, 1, 0, 0, 128 });
        pkt.push_back(0x00);

        return pkt;
    }


    static void static_thread_worker(TitanReporter* instance) {
        instance->read_printf_loop();
    }

public:
    TitanReporter() : handle(nullptr), thread_running(false) {}
    ~TitanReporter() { disconnect(); }

    bool connect() {
        if (hid_init() < 0) return false;
        handle = hid_open(TITAN_VENDOR_ID, TITAN_PRODUCT_ID, nullptr);
        if (!handle) { hid_exit(); return false; }

        if (thread_running) {
            thread_running = false;
            if (reader_thread.joinable()) reader_thread.join();
        }

        thread_running = true;
        reader_thread = std::thread(static_thread_worker, this);
        return true;
    }

    void disconnect() {
        if (thread_running) {
            thread_running = false;
            if (reader_thread.joinable()) reader_thread.join();
        }
        if (handle) {
            send_inputs(std::vector<float>(42, 0.0f));
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            hid_close(handle);
            handle = nullptr;
            hid_exit();
        }
    }

    bool send_inputs(const std::vector<float>& inputs) {
        if (!handle) return false;
        auto pkt = construct_packet(inputs);
        int res = hid_write(handle, pkt.data(), pkt.size());
        return (res >= 0);
    }
   std::vector<std::string> read_printf_loop() {
        uint8_t buffer[65];
        std::vector<std::string> message_list;
        message_list.reserve(128); 

        while (thread_running) {
            int bytes_read = hid_read_timeout(handle, buffer, sizeof(buffer), 5);
            if (bytes_read > 0 && buffer[0] == 0x16) {
                std::string parsed_msg;
                parsed_msg.reserve(bytes_read);

                for (int i = 2; i < bytes_read; ++i) {
                    if (buffer[i] >= 32 && buffer[i] < 127) {
                        parsed_msg += static_cast<char>(buffer[i]);
                    }
                }
                
                if (!parsed_msg.empty()) {
                    message_list.push_back(std::move(parsed_msg));
                }
            }
        }

        return message_list;
    }

    TitanDeviceInfo get_device_info() {
        TitanDeviceInfo info;
        if (!handle) return info;

        wchar_t wstr[256];

        if (hid_get_manufacturer_string(handle, wstr, 256) == 0) {
            std::wstring ws(wstr);
            info.manufacturer = std::string(ws.begin(), ws.end());
        }

        if (hid_get_product_string(handle, wstr, 256) == 0) {
            std::wstring ws(wstr);
            info.product = std::string(ws.begin(), ws.end());
        }

        if (hid_get_serial_number_string(handle, wstr, 256) == 0) {
            std::wstring ws(wstr);
            info.serial_number = std::string(ws.begin(), ws.end());
        }

        return info;
    }
  
};