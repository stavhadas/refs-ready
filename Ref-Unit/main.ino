
void setup() {
  
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2) == HIGH && led_state)
  {
    digitalWrite(13, HIGH);
    led_state=false;
  }
  else if (digitalRead(2) == LOW && !led_state)
  {
    digitalWrite(13, LOW);
    led_state=true;
  }
}