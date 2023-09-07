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
unsigned long delayInterval = 1000;  // Delay interval in milliseconds
const int numReadings = 20;  // Number of temperature readings for averaging
int temperatureReadings[numReadings];  // Array to store temperature readings
int lowThresholdReadings[numReadings];  // Array to store lowThresholdPot readings
int highThresholdReadings[numReadings];  // Array to store highThresholdPot readings
int currentReading = 0;  // Index of the current reading
int averageTemperature = 0;  // Average temperature value
int averageLowThreshold = 0;  // Average lowThresholdPot value
int averageHighThreshold = 0;  // Average highThresholdPot value

// Morse code lookup table
const String morseCode[] = {
  "-----",  // 0
  ".----",  // 1
  "..---",  // 2
  "...--",  // 3
  "....-",  // 4
  ".....",  // 5
  "-....",  // 6
  "--...",  // 7
  "---..",  // 8
  "----."   // 9
};

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

void blinkLEDs(String sequence) {
  for (int i = 0; i < sequence.length(); i++) {
    char c = sequence.charAt(i);
    if (c == '.') {
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      delay(200);  // Dot duration
    } else if (c == '-') {
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      delay(600);  // Dash duration
    } else if (c == ' ') {
      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      delay(400);  // Gap between elements within a character
    }
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    delay(200);  // Gap between characters
  }
}

void loop() {
  // Current time
  unsigned long currentMillis = millis();

  // Check if the delay interval has passed
  if (currentMillis - previousMillis >= delayInterval) {
    previousMillis = currentMillis; // Update the previous time

    // Read analog values
    int temperatureValue = analogRead(temperaturePin);

    // Store the current readings in the arrays
    temperatureReadings[currentReading] = temperatureValue;
    lowThresholdReadings[currentReading] = analogRead(lowThresholdPotPin);
    highThresholdReadings[currentReading] = analogRead(highThresholdPotPin);

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

    // Calculate the average lowThresholdPot value
    averageLowThreshold = 0;
    for (int i = 0; i < numReadings; i++) {
      averageLowThreshold += lowThresholdReadings[i];
    }
    averageLowThreshold /= numReadings;

    // Calculate the average highThresholdPot value
    averageHighThreshold = 0;
    for (int i = 0; i < numReadings; i++) {
      averageHighThreshold += highThresholdReadings[i];
    }
    averageHighThreshold /= numReadings;

    int mappedTemperature = map(averageTemperature, 0, 4095, 0, 100);
    lowThreshold = map(averageLowThreshold, 0, 4095, 0, 100);
    highThreshold = map(averageHighThreshold, 0, 4095, 0, 100);

    
    Serial.print("Temperature Value: ");
    Serial.print(mappedTemperature);
    Serial.print("\tLow Threshold: ");
    Serial.print(lowThreshold);
    Serial.print("\tHigh Threshold: ");
    Serial.print(highThreshold);

    // Compare values and control relay
    if (mappedTemperature > highThreshold) {
      digitalWrite(relayPin, HIGH);  // Turn off the relay
      Serial.println("\tRelay OFF");
    } else if (mappedTemperature <= lowThreshold) {
      digitalWrite(relayPin, LOW);  // Turn on the relay
      Serial.println("\tRelay ON");
    } else {
      //digitalWrite(relayPin, LOW);  // Set relay pin to LOW using internal pulldown resistor
      Serial.println("\t");
    }

    // Blink LEDs to represent temperature in Morse code
    String temperatureSequence = morseCode[mappedTemperature / 10] + " " + morseCode[mappedTemperature % 10];
    blinkLEDs(temperatureSequence);
  }
}
