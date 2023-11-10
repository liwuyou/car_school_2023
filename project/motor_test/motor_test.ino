void setup() {
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
}

void loop() {
  analogWrite(5, 30);     //  0-255
  analogWrite(6, 120);     //  0-255
}
