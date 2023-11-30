const int irSensorPin = 2;   // Connect the signal pin of IR sensor to digital pin 2
const int buzzerPin = 3;     // Connect the buzzer to digital pin 3
const int ledPin = 4;        // Optional LED for visual indication

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int irValue = digitalRead(irSensorPin);

  if (irValue == LOW) {
    // IR sensor doesn't detect any object (gate open)
    digitalWrite(buzzerPin, HIGH);  // Turn on the buzzer
    digitalWrite(ledPin, HIGH);     // Optional: Turn on the LED
    Serial.println("Gate Open!");
  } else {
    // IR sensor detects an object (gate closed)
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
    digitalWrite(ledPin, LOW);      // Optional: Turn off the LED
    Serial.println("Gate Closed!");
  }

  delay(100);  // Adjust the delay as needed
}
