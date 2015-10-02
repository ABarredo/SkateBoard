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

void printdata(void)
{    
      /*Serial1.print("REG1 ");
      Serial1.println(Reg1);
      Serial1.print("REG2 ");
      Serial1.println(Reg2);
      Serial1.print("REG3 ");
      Serial1.println(Reg3);
      Serial1.print("REG4 ");
      Serial1.println(Reg4);
      Serial1.print("REG5 ");
      Serial1.println(Reg5);
      Serial1.print("REG6 ");
      Serial1.println(Reg6);
      Serial1.print("REG7 ");
      Serial1.println(Reg7);
      Serial1.print("REG8 ");
      Serial1.println(Reg8);
      Serial1.print("REG9 ");
      Serial1.println(Reg9);
      Serial1.print("REG10 ");
      Serial1.println(Reg10);
      Serial1.print("REG11 ");
      Serial1.println(Reg11);
      Serial1.print("REG12 ");
      Serial1.println(Reg12);
      Serial1.print("REG13 ");
      Serial1.println(Reg13);
      Serial1.print("REG14 ");
      Serial1.println(Reg14);
      Serial1.print("REG15 ");
      Serial1.println(Reg15);
      Serial1.print("REG16 ");
      Serial1.println(Reg16);
      Serial1.print("REG17 ");
      Serial1.println(Reg17);
      Serial1.print("REG18 ");
      Serial1.println(Reg18);
      Serial1.print("REG19 ");
      Serial1.println(Reg19);
      Serial1.print("REG20 ");
      Serial1.println(Reg20);
      Serial1.print("REG21 ");
      Serial1.println(Reg21);
      Serial1.print("REG22 ");
      Serial1.println(Reg22);
      Serial1.print("REG23 ");
      Serial1.println(Reg23);*/
      #if PRINT_EULER == 1
      //Serial1.print("r");
      Serial1.print(ToDeg(roll));
      Serial1.print(",");
      //Serial1.print("p");
      Serial1.print(ToDeg(pitch));
      Serial1.print(",");
      //Serial1.print("y");
      Serial1.print(ToDeg(yaw));
      Serial1.print(",");
      //Serial1.print("a");
      Serial1.print(altitude);
      Serial1.print(",");
      //Serial1.print("e");
      #endif      
      Serial1.println();    
      
}

long convert_to_dec(float x)
{
  return x*10000000;
}

