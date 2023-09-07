#include <Arduino.h>

const int relayPin = PC13;
const int temperaturePin = PA5;
const int lowThresholdPotPin = PA0;
const int highThresholdPotPin = PA1;
const int redLedPin = PB7;    // PWM output pin for red LED
const int greenLedPin = PB6;  // PWM output pin for green LED
const int pwmFrequency = 1000;  // PWM frequency in Hz


int lowThreshold = 0;
int highThreshold = 0;
unsigned long previousMillis = 0;
int brightness = 0;
int fadeAmount = 5;  // Rate of brightness change
unsigned long delayInterval = 1000;  // Delay interval in milliseconds
const int numReadings = 5;  // Number of temperature readings for averaging
int temperatureReadings[numReadings];  // Array to store temperature readings
int currentReading = 0;  // Index of the current reading
int averageTemperature = 0;  // Average temperature value

void setup() {

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Set relay pin to LOW using internal pulldown resistor
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);


  pinMode(temperaturePin, INPUT_ANALOG);
  pinMode(lowThresholdPotPin, INPUT_ANALOG);
  pinMode(highThresholdPotPin, INPUT_ANALOG);

 
  Serial.begin(9600);
}

void loop() {
  // Current time
  unsigned long currentMillis = millis();

  // Check if the delay interval has passed
  if (currentMillis - previousMillis >= delayInterval) {
    previousMillis = currentMillis; // Update the previous time

    int temperatureValue = analogRead(temperaturePin);

    // Store the current reading in the array
    temperatureReadings[currentReading] = temperatureValue;

    // Move to the next reading index
    currentReading++;
    if (currentReading >= numReadings) {
      currentReading = 0;  // Reset the reading index
    }

    // Calculate the average temperature
    averageTemperature = 0;
    for (int i = 0; i < numReadings; i++) {
      averageTemperature += temperatureReadings[i];
    }
    averageTemperature /= numReadings;

    int mappedTemperature = map(averageTemperature, 0, 4095, 0, 100);
    lowThreshold = map(analogRead(lowThresholdPotPin), 0, 4095, 0, 100);
    highThreshold = map(analogRead(highThresholdPotPin), 0, 4095, 0, 100);

    Serial.print("Temperature Value: ");
    Serial.print(mappedTemperature);
    Serial.print("\tLow Threshold: ");
    Serial.print(lowThreshold);
    Serial.print("\tHigh Threshold: ");
    Serial.print(highThreshold);

    // Compare values and control relay
    if (mappedTemperature > highThreshold) {
      digitalWrite(relayPin, HIGH);  // Turn off the relay
      fadeAmount = -5;  // Decrease brightness
      Serial.println("\tRelay OFF");
    } else if (mappedTemperature <= lowThreshold) {
      digitalWrite(relayPin, LOW);  // Turn on the relay
      fadeAmount = 5;  // Increase brightness
      Serial.println("\tRelay ON");
    } else {
      digitalWrite(relayPin, LOW);  // Set relay pin to LOW using internal pulldown resistor
      Serial.println("\t");
    }

    // Update LED brightness
    brightness += fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      // Reverse the fade direction
      fadeAmount = -fadeAmount;
    }

    if (mappedTemperature >= lowThreshold && mappedTemperature <= highThreshold) {
      // Adjust brightness levels based on temperature
      int brightnessRed = map(mappedTemperature, lowThreshold, highThreshold, 0, 255);
      int brightnessGreen = map(mappedTemperature, lowThreshold, highThreshold, 255, 0);
      analogWrite(redLedPin, brightnessRed);
      analogWrite(greenLedPin, brightnessGreen);
    } else {
      // Use default brightness
      analogWrite(redLedPin, brightness);
      analogWrite(greenLedPin, 255 - brightness);
    }
  }
}
