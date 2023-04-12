void setup()
{
  Serial.begin(9600);   
  delay(500);
}
 
void loop()
{
  Serial.print("AT\r");
  delay(500);
  Serial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(500);
  // send sms message, the phone number needs to include the country code e.g. For an Indian contact such as 9876543210 then the string     must be:
  // +919876543210
  Serial.println("AT+CMGS = \"+12282163723\"");
  delay(500);
  Serial.println("Test Message"); //the content of the message
  delay(500);
  Serial.print((char)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(500);
  while(1);
}
