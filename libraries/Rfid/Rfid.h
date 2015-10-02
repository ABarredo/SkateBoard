/*
	This library implements the ways to read write authenticate and seek with SM130 RFID 
	reader. Solving for us all the problem of calculating the headers and the UART commands.
	Created by Alejandro Barredo, February 2015.
	Released into the public domain.
*/
#ifndef Rfid_h
#define Rfid_h
#include <SoftwareSerial.h>
#include "Arduino.h"
class Rfid
{
	public:
	Rfid();
	String read();
	void write(char c1,char c2,char c3,char c4,char c5,char c6,char c7,
					   char c8,char c9,char c10,char c11,char c12,char c13,
					   char c14,char c15,char c16,char checksum);
	void authenticate();
	void seek();
	void halt();
	private:
	String respHex;
};

#endif