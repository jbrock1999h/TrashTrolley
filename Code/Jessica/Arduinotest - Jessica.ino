
#include <SoftwareSerial.h>
SoftwareSerial mySerial(11,10); //(rx,tx) Connection ports for the arduino
unsigned char data[4]={};
float distance;

void setup()
{
  Serial.begin(57600);
  mySerial.begin(9600);
}

void loop()
{
  
  do{
    for(int i=0;i<4;i++)
    {
      data[i]=mySerial.read();
    }
  }while(mySerial.read()==0xff);
  
  mySerial.flush();
  
  if(data[0]==0xff)
  {
    int sum;
    sum=(data[0]+data[1]+data[2])&0x00FF;
    if(sum==data[3])
    {
      distance=(data[1]<<8)+data[2];
      if(distance>280)
      {
        Serial.print("distance=");
       
        Serial.print(distance*(0.39370079/10));
        //Serial.print(distance/10);
        Serial.print("inches");
       // Serial.print('\n');
       Serial.println();

      }else
      {
        Serial.println("Below the lower limit");
      }
    }

    else Serial.println("ERROR");

  }
 
  delay(150);   
  

 }