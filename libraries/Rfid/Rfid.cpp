#include "Arduino.h"
#include "Rfid.h"
#include <SoftwareSerial.h>
Rfid::Rfid(){
	String respHex = "";
}

void Rfid::write(char c1,char c2,char c3,char c4,char c5,char c6,char c7,
					   char c8,char c9,char c10,char c11,char c12,char c13,
					   char c14,char c15,char c16,char checksum)
{
  
  SoftwareSerial mySerial(6, 7);
  mySerial.begin(19200);
  respHex = "";
  Serial.println("Write Block : ");
  mySerial.print((char)0xFF); //Header of the command
  mySerial.print((char)0x00); //Reserved
  mySerial.print((char)0x12); //the length of the frame
  mySerial.print((char)0x89); //Command
  mySerial.print((char)0x01); //Block
  
  mySerial.print((char)c1);
  mySerial.print((char)c2); 
  mySerial.print((char)c3);
  mySerial.print((char)c4); 
  mySerial.print((char)c5);
  mySerial.print((char)c6); 
  mySerial.print((char)c7); 
  mySerial.print((char)c8);
  mySerial.print((char)c9); 
  mySerial.print((char)c10); 
  mySerial.print((char)c11); 
  mySerial.print((char)c12); 
  mySerial.print((char)c13); 
  mySerial.print((char)c14); 
  mySerial.print((char)c15); 
  mySerial.print((char)c16);
  mySerial.print((char)checksum);
  delay(500); //a small delay is needed for giving the rfidreader time
  
  while (mySerial.available()) {
    
      String x = String(mySerial.read(),HEX);
      respHex = respHex + x;

  }
  Serial.println (respHex);
  Serial.println("");
  Serial.println("Done");
  while(repsHex.substring(8,10).equals("4E") || repsHex.substring(8,10).equals("55") || repsHex.substring(8,10).equals("58") || repsHex.substring(8,10).equals("46")){
	  respHex = "";
  Serial.println("Write Block : ");
  mySerial.print((char)0xFF); //Header of the command
  mySerial.print((char)0x00); //Reserved
  mySerial.print((char)0x12); //the length of the frame
  mySerial.print((char)0x89); //Command
  mySerial.print((char)0x01); //Block
  
  mySerial.print((char)c1);
  mySerial.print((char)c2); 
  mySerial.print((char)c3);
  mySerial.print((char)c4); 
  mySerial.print((char)c5);
  mySerial.print((char)c6); 
  mySerial.print((char)c7); 
  mySerial.print((char)c8);
  mySerial.print((char)c9); 
  mySerial.print((char)c10); 
  mySerial.print((char)c11); 
  mySerial.print((char)c12); 
  mySerial.print((char)c13); 
  mySerial.print((char)c14); 
  mySerial.print((char)c15); 
  mySerial.print((char)c16);
  mySerial.print((char)checksum);
  delay(500); //a small delay is needed for giving the rfidreader time
  
  while (mySerial.available()) {
    
      String x = String(mySerial.read(),HEX);
      respHex = respHex + x;

  }
  }
}
String Rfid::read()
{
	SoftwareSerial mySerial(6, 7);
  mySerial.begin(19200);
  Serial.println("Read : ");
  respHex = "";
  mySerial.print((char)0xFF); //Header of the command
  mySerial.print((char)0x00); //Reserved byte
  mySerial.print((char)0x02); //Byte length (Command + data)
  mySerial.print((char)0x86); //Command "Authenticate"
  mySerial.print((char)0x01); //Block
  mySerial.print((char)0x89); //Checksum

  delay(500); //a small delay is needed for giving the rfid reader time
  
  while (mySerial.available()) {
    
      String x = String(mySerial.read(),HEX);
      respHex = respHex + x;
  }
  Serial.println (respHex);
  Serial.println("");
  Serial.println("Done");
  while(repsHex.substring(8,10).equals("4E") || repsHex.substring(8,10).equals("46")){
	  respHex = "";
  mySerial.print((char)0xFF); //Header of the command
  mySerial.print((char)0x00); //Reserved byte
  mySerial.print((char)0x02); //Byte length (Command + data)
  mySerial.print((char)0x86); //Command "Authenticate"
  mySerial.print((char)0x01); //Block
  mySerial.print((char)0x89); //Checksum

  delay(500); //a small delay is needed for giving the rfid reader time
  
  while (mySerial.available()) {
    
      String x = String(mySerial.read(),HEX);
      respHex = respHex + x;
  }
  }
  return respHex.substring(10,42);
}
void Rfid::authenticate()
{
  SoftwareSerial mySerial(6, 7);
  mySerial.begin(19200);
  Serial.println("Aunthenticate : ");
  respHex = "";
  mySerial.print((char)0xFF); //Header of the command
  mySerial.print((char)0x00); //Reserved byte
  mySerial.print((char)0x03); //Byte length (Command + data)
  mySerial.print((char)0x85); //Command "Authenticate"
  mySerial.print((char)0x01); //Block
  mySerial.print((char)0xFF); //Key
  mySerial.print((char)0x88); //Checksum

  delay(500); //a small delay is needed for giving the rfid reader time
  
  while (mySerial.available()) {
    
      String x = String(mySerial.read(),HEX);
      respHex = respHex + x;
  }
  Serial.println (respHex);
  Serial.println("");
  Serial.println("Done");
  while(repsHex.substring(8,10).equals("4E") || repsHex.substring(8,10).equals("55") || repsHex.substring(8,10).equals("45")){
	  respHex = "";
	  mySerial.print((char)0xFF); //Header of the command
	  mySerial.print((char)0x00); //Reserved byte
	  mySerial.print((char)0x03); //Byte length (Command + data)
	  mySerial.print((char)0x85); //Command "Authenticate"
	  mySerial.print((char)0x01); //Block
	  mySerial.print((char)0xFF); //Key
	  mySerial.print((char)0x88); //Checksum

	  delay(500); //a small delay is needed for giving the rfid reader time 
	while (mySerial.available()) {
		
		  String x = String(mySerial.read(),HEX);
		  respHex = respHex + x;
  }	  
  }
}
void Rfid::seek()
{
	SoftwareSerial mySerial(6, 7);
	mySerial.begin(19200);
  respHex = "";
  Serial.println("Select : ");
  mySerial.print((char)0xFF); //Header of the command
  mySerial.print((char)0x00); //Reserved byte
  mySerial.print((char)0x01); //Byte length (Command + data)
  mySerial.print((char)0x83); //Command "Authenticate"
  mySerial.print((char)0x84); //Checksum

  delay(500); //a small delay is needed for giving the rfidreader time
  
  while (mySerial.available()) {
      String x = String(mySerial.read(),HEX);
      respHex = respHex + x;
  }
  Serial.println (respHex);
  Serial.println("");
  Serial.println("Done");
  while(repsHex.substring(8,10).equals("4E") || repsHex.substring(8,10).equals("55")){
	  respHex = "";
	  Serial.println("Select : ");
	  mySerial.print((char)0xFF); //Header of the command
	  mySerial.print((char)0x00); //Reserved byte
	  mySerial.print((char)0x01); //Byte length (Command + data)
	  mySerial.print((char)0x83); //Command "Authenticate"
	  mySerial.print((char)0x84); //Checksum

	  delay(500); //a small delay is needed for giving the rfidreader time
	  while (mySerial.available()) {
		String x = String(mySerial.read(),HEX);
		respHex = respHex + x;
	  }
  }
  }
  void Rfid::halt()
{
	SoftwareSerial mySerial(6, 7);
	mySerial.begin(19200);
  respHex = "";
  Serial.println("Halt : ");
  mySerial.print((char)0xFF); //Header of the command
  mySerial.print((char)0x00); //Reserved byte
  mySerial.print((char)0x01); //Byte length (Command + data)
  mySerial.print((char)0x93); //Command "Authenticate"
  mySerial.print((char)0x94); //Checksum

  delay(500); //a small delay is needed for giving the rfidreader time
   while (mySerial.available()) {
		String x = String(mySerial.read(),HEX);
		respHex = respHex + x;
	  }
Serial.println (respHex);
  Serial.println("");
  Serial.println("Done");
  while(repsHex.substring(8,10).equals("55")){
	 respHex = "";
  Serial.println("Halt : ");
  mySerial.print((char)0xFF); //Header of the command
  mySerial.print((char)0x00); //Reserved byte
  mySerial.print((char)0x01); //Byte length (Command + data)
  mySerial.print((char)0x93); //Command "Authenticate"
  mySerial.print((char)0x94); //Checksum

  delay(500); //a small delay is needed for giving the rfidreader time
   while (mySerial.available()) {
		String x = String(mySerial.read(),HEX);
		respHex = respHex + x;
	  }
  }
}
