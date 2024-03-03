const int sensorPin = A0;  // LM35 sensor connected to analog pin A0
const int ledPin = 13;    // Onboard LED connected to digital pin 13

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read temperature from LM35 sensor
  int sensorValue = analogRead(sensorPin);
  float temperatureC = (sensorValue * 5.0 / 1024) * 100;

  // Print temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println("°C");

  // Check temperature conditions and control onboard LED
  if (temperatureC < 30) {
    customDelay(250);  // Blink every 250 milliseconds
  } else {
    customDelay(500);  // Blink every 500 milliseconds
  }
}

// Custom delay function using a for loop
void customDelay(int milliseconds) {
  for (int i = 0; i < milliseconds / 10; i++) {
    for (int j = 0; j < 1000; j++) {
      // Wasting time to create the delay
    }
    digitalWrite(ledPin, HIGH);
    for (int j = 0; j < 1000; j++) {
      // Wasting time to create the delay
    }
    digitalWrite(ledPin, LOW);
  }
}

