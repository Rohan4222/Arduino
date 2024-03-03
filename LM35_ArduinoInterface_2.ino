// LM35 Temperature Sensor interface with Arduino Uno
// Onboard LED control based on temperature readings

const int analogPin = A0;  // Analog pin for LM35 temperature sensor
const int ledPin = 13;     // Onboard LED pin

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read temperature from LM35 sensor
  int sensorValue = analogRead(analogPin);
  
  // Convert the analog reading to temperature in degrees Celsius
  float temperatureC = (sensorValue * 5.0 / 1024.0) * 100.0;

  // Print temperature to Serial Monitor (optional)
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Check temperature and control onboard LED
  if (temperatureC < 30.0) {
    blinkLED(250000);  // Blink every 250 milliseconds
  } else {
    blinkLED(500000);  // Blink every 500 milliseconds
  }
}

// Function to blink the onboard LED
void blinkLED(int interval) {
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(interval);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(interval);
}
