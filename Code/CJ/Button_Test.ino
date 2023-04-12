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
      Serial.println("Button 1 is pressed");
  }

  if (button2State == LOW) {
      Serial.println("Button 2 is pressed");
  }  
  
  delay(1000);
}