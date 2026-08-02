#pragma once
// i only have a xbox, so i just had ai write the other numbered values for the other systems. THEY CAN BE WRONG.
#define TITAN_VENDOR_ID 0x2508
#define TITAN_PRODUCT_ID 0x0032

namespace XB {
    constexpr int Xbox = 0;
    constexpr int View = 1;
    constexpr int Menu = 2;
    constexpr int RB = 3;
    constexpr int RT = 4;
    constexpr int RS = 6;
    constexpr int LB = 7;
    constexpr int LT = 8;
    constexpr int LS = 5;
    constexpr int UP = 9;
    constexpr int DOWN = 10;
    constexpr int LEFT = 11;
    constexpr int RIGHT = 12;
    constexpr int Y = 13;
    constexpr int B = 14;
    constexpr int A = 15;
    constexpr int X = 16;
    constexpr int Share = 17;
    constexpr int Sync = 20;

    constexpr int RX = 21;
    constexpr int RY = 22;
    constexpr int LX = 23;
    constexpr int LY = 24;

    constexpr int P1 = 38;
    constexpr int P2 = 39;
    constexpr int P3 = 40;
    constexpr int P4 = 41;
}

namespace PS {
    constexpr int PS_Btn = 0;
    constexpr int TouchClick = 1; 
    constexpr int Options = 2;    
    constexpr int R1 = 3;
    constexpr int R2 = 4;
    constexpr int R3 = 5;
    constexpr int L1 = 6;
    constexpr int L2 = 7;
    constexpr int L3 = 8;
    constexpr int UP = 9;
    constexpr int DOWN = 10;
    constexpr int LEFT = 11;
    constexpr int RIGHT = 12;
    constexpr int Triangle = 13;
    constexpr int Circle = 14;
    constexpr int Cross = 15;
    constexpr int Square = 16;
    constexpr int Create = 17;    
    constexpr int TouchP1 = 18;
    constexpr int TouchP2 = 19;
    constexpr int Mute = 20;      

    constexpr int RX = 21;
    constexpr int RY = 22;
    constexpr int LX = 23;
    constexpr int LY = 24;

    constexpr int TouchP1_X = 25;
    constexpr int TouchP1_Y = 26;
    constexpr int TouchP2_X = 27;
    constexpr int TouchP2_Y = 28;

    constexpr int Accel_X = 29;
    constexpr int Accel_Y = 30;
    constexpr int Accel_Z = 31;
    constexpr int Gyro_X = 35;
    constexpr int Gyro_Y = 36;
    constexpr int Gyro_Z = 37;
}

namespace NS {
    constexpr int Home = 0;
    constexpr int Minus = 1;
    constexpr int Plus = 2;
    constexpr int R = 3;
    constexpr int ZR = 4;
    constexpr int RS = 5;
    constexpr int L = 6;
    constexpr int ZL = 7;
    constexpr int LS = 8;
    constexpr int UP = 9;
    constexpr int DOWN = 10;
    constexpr int LEFT = 11;
    constexpr int RIGHT = 12;
    constexpr int X = 13;
    constexpr int A = 14;
    constexpr int B = 15;
    constexpr int Y = 16;
    constexpr int Capture = 17;
    constexpr int SL = 18;
    constexpr int SR = 19;

    constexpr int RX = 21;
    constexpr int RY = 22;
    constexpr int LX = 23;
    constexpr int LY = 24;

    constexpr int Accel_X = 29;
    constexpr int Accel_Y = 30;
    constexpr int Accel_Z = 31;
    constexpr int JoyAcc_X = 32;
    constexpr int JoyAcc_Y = 33;
    constexpr int JoyAcc_Z = 34;
    constexpr int Gyro_X = 35;
    constexpr int Gyro_Y = 36;
    constexpr int Gyro_Z = 37;
}

namespace WII {
    constexpr int Home = 0;
    constexpr int Minus = 1;
    constexpr int Plus = 2;
    constexpr int R = 3;
    constexpr int ZR = 4;
    constexpr int SR_Two = 5;    
    constexpr int L_C = 6;       
    constexpr int ZL_Z = 7;      
    constexpr int SL_One = 8;    
    constexpr int UP = 9;
    constexpr int DOWN = 10;
    constexpr int LEFT = 11;
    constexpr int RIGHT = 12;
    constexpr int X = 13;
    constexpr int A = 14;
    constexpr int B = 15;
    constexpr int Y = 16;
    constexpr int InfraP1 = 18;
    constexpr int InfraP2 = 19;

    constexpr int RX = 21;
    constexpr int RY = 22;
    constexpr int LX = 23;
    constexpr int LY = 24;

    constexpr int InfraP1_X = 25;
    constexpr int InfraP1_Y = 26;
    constexpr int InfraP2_X = 27;
    constexpr int InfraP2_Y = 28;

    constexpr int Accel_X = 29;
    constexpr int Accel_Y = 30;
    constexpr int Accel_Z = 31;
    constexpr int NunchukAcc_X = 32;
    constexpr int NunchukAcc_Y = 33;
    constexpr int NunchukAcc_Z = 34;
    constexpr int MPlusGyro_X = 35;
    constexpr int MPlusGyro_Y = 36;
    constexpr int MPlusGyro_Z = 37;
}