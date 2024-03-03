// LM35 Temperature Sensor interface with Arduino Uno
// Onboard LED control based on temperature readings

const int analogPin = A0;  // Analog pin for LM35 temperature sensor
const int ledPin = 13;     // Onboard LED pin

float temperatureC = 0.0;
int counter = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read temperature from LM35 sensor
  int sensorValue = analogRead(analogPin);
  temperatureC = (sensorValue * 5.0 / 1024.0) * 100.0;

  // Print temperature to Serial Monitor (optional)
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Check temperature and control onboard LED
  if (temperatureC < 30.0) {
    blinkLED(250, 4);  // Blink every 250 milliseconds, repeat 4 times
  } else {
    blinkLED(500, 2);  // Blink every 500 milliseconds, repeat 2 times
  }
}

// Function to blink the onboard LED
void blinkLED(int interval, int repeats) {
  static int counterValue = 0;
  
  if (counterValue < (interval / 2)) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  counterValue++;
  
  if (counterValue >= interval) {
    counterValue = 0;
    repeats--;

    if (repeats <= 0) {
      delay(1000);  // Pause for 1 second before the next cycle
    }
  }
}

