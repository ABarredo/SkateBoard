/*

MinIMU-9-Arduino-AHRS
Pololu MinIMU-9 + Arduino AHRS (Attitude and Heading Reference System)

Copyright (c) 2011 Pololu Corporation.
http://www.pololu.com/

MinIMU-9-Arduino-AHRS is based on sf9domahrs by Doug Weibel and Jose Julio:
http://code.google.com/p/sf9domahrs/

sf9domahrs is based on ArduIMU v1.5 by Jordi Munoz and William Premerlani, Jose
Julio and Doug Weibel:
http://code.google.com/p/ardu-imu/

MinIMU-9-Arduino-AHRS is free software: you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your option)
any later version.

MinIMU-9-Arduino-AHRS is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for
more details.


*/

#include <L3G.h>
#include <LSM303.h>
#include <LPS.h>

LPS alti;
L3G gyro;
LSM303 compass;

void I2C_Init()
{
  Wire.begin();
}
void Alti_Init()
{
  alti.init();
  alti.enableDefault();
  alti.writeReg(LPS::CTRL_REG1,0xC2);
  alti.writeReg(LPS::RES_CONF,0xF);
  alti.writeReg(LPS::STATUS_REG,0x00);
  alti.writeReg(LPS::PRESS_OUT_XL,0x00);
  alti.writeReg(LPS::PRESS_OUT_L,0x00);
  alti.writeReg(LPS::PRESS_OUT_H,0x00);
  
  /*Reg1 = alti.readReg(0x8);
  Reg2 = alti.readReg(0x9);
  Reg3 = alti.readReg(0xA);
  Reg4 = alti.readReg(0xF);
  Reg5 = alti.readReg(0x10);
  Reg6 = alti.readReg(0x20);
  Reg7 = alti.readReg(0x21);
  Reg8 = alti.readReg(0x22);
  Reg9 = alti.readReg(0x23);
  Reg10 = alti.readReg(0x24);
  Reg11 = alti.readReg(0x25);
  Reg12 = alti.readReg(0x27);
  Reg13 = alti.readReg(0x28);
  Reg14 = alti.readReg(0x29);
  Reg15 = alti.readReg(0x2A);
  Reg16 = alti.readReg(0x2B);
  Reg17 = alti.readReg(0x2C);
  Reg18 = alti.readReg(0x2E);
  Reg19 = alti.readReg(0x2F);
  Reg20 = alti.readReg(0x30);
  Reg21= alti.readReg(0x31);
  Reg22= alti.readReg(0x39);
  Reg23= alti.readReg(0x3A);*/
  
}

void Read_Alti()
{
  pressure = alti.readPressureMillibars();
  AN[6] = alti.pressureToAltitudeMeters(pressure);
  altitude = (AN[6] - AN_OFFSET[6]);
}

void Gyro_Init()
{
  gyro.init();
  gyro.enableDefault();
  gyro.writeReg(L3G::CTRL_REG4, 0x20); // 2000 dps full scale
  gyro.writeReg(L3G::CTRL_REG1, 0x4F); // normal power mode, all axes enabled, 100 Hz
}

void Read_Gyro()
{
  gyro.read();
  
  AN[0] = gyro.g.x;
  AN[1] = gyro.g.y;
  AN[2] = gyro.g.z;
  gyro_x = SENSOR_SIGN[0] * (AN[0] - AN_OFFSET[0]);
  gyro_y = SENSOR_SIGN[1] * (AN[1] - AN_OFFSET[1]);
  gyro_z = SENSOR_SIGN[2] * (AN[2] - AN_OFFSET[2]);
}

void Accel_Init()
{
  compass.init();
  compass.enableDefault();

  switch (compass.getDeviceType())
  {
    case LSM303::device_D:
      compass.writeReg(LSM303::CTRL2, 0x18); // 8 g full scale: AFS = 011
      compass.writeReg(LSM303::CTRL1, 0x4F); // data rate set to 25hz
        //Reg1 = "Device D";
      break;
    case LSM303::device_DLHC:
      compass.writeReg(LSM303::CTRL_REG4_A, 0x28); // 8 g full scale: FS = 10; high resolution output mode
      //Reg1 = "Device DLHC";
      break;
    default: // DLM, DLH
      compass.writeReg(LSM303::CTRL_REG4_A, 0x30); // 8 g full scale: FS = 11
      //Reg1 = "Device Default";
  }
}

// Reads x,y and z accelerometer registers
void Read_Accel()
{
  compass.readAcc();
  
  AN[3] = compass.a.x >> 4; // shift left 4 bits to use 12-bit representation (1 g = 256)
  AN[4] = compass.a.y >> 4;
  AN[5] = compass.a.z >> 4;
  accel_x = SENSOR_SIGN[3] * (AN[3] - AN_OFFSET[3]);
  accel_y = SENSOR_SIGN[4] * (AN[4] - AN_OFFSET[4]);
  accel_z = SENSOR_SIGN[5] * (AN[5] - AN_OFFSET[5]);
}

void Compass_Init()
{
  // doesn't need to do anything because Accel_Init() should have already called compass.enableDefault()
}

void Read_Compass()
{
  compass.readMag();
  
  magnetom_x = SENSOR_SIGN[6] * compass.m.x;
  magnetom_y = SENSOR_SIGN[7] * compass.m.y;
  magnetom_z = SENSOR_SIGN[8] * compass.m.z;
}

