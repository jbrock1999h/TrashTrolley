#define BUTTON1_PIN 4
#define BUTTON2_PIN 5

void setup()
{
  Serial.begin(9600);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
}

void loop()
{
  byte button1State = digitalRead(BUTTON1_PIN);
  byte button2State = digitalRead(BUTTON2_PIN);
  
  if (button1State == LOW) {
  Serial.print("AT\r");
  delay(500);
  Serial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(500);
  // send sms message, the phone number needs to include the country code e.g. For an Indian contact such as 9876543210 then the string     must be:
  // +919876543210
  Serial.println("AT+CMGS = \"+12282163723\"");
  delay(500);
  Serial.println("Button 1 is pressed"); //the content of the message
  delay(500);
  Serial.print((char)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(500);
  }

  if (button2State == LOW) {
  Serial.print("AT\r");
  delay(500);
  Serial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(500);
  // send sms message, the phone number needs to include the country code e.g. For an Indian contact such as 9876543210 then the string     must be:
  // +919876543210
  Serial.println("AT+CMGS = \"+12282163723\"");
  delay(500);
  Serial.println("Button 2 is pressed"); //the content of the message
  delay(500);
  Serial.print((char)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(500);
  }  
  
  delay(1000);
}
