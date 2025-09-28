/*
  Digital Tachometer using IR Sensor
  Counts motor RPM using interrupt on IR sensor
*/

const int irPin = 2;   // IR sensor output pin
volatile int count = 0; // Pulse count
unsigned long lastTime = 0;
int rpm = 0;

void setup() {
  Serial.begin(9600);
  pinMode(irPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(irPin), pulseCounter, RISING);
  Serial.println("Digital Tachometer Ready...");
}

void loop() {
  if (millis() - lastTime >= 1000) {  // Every 1 second
    rpm = count * 60;  // Pulses per second * 60 = RPM
    Serial.print("RPM: ");
    Serial.println(rpm);

    count = 0;              // Reset count
    lastTime = millis();    // Reset timer
  }
}

void pulseCounter() {
  count++; // Increase count on each pulse
}
