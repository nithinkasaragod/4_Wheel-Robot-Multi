#include <SoftwareSerial.h>

// Pin definitions for SoftwareSerial
#define RX_PIN 3  // Receive pin (for incoming data)
#define TX_PIN 4  // Transmit pin (for sending data)

#define enA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define enB 5

String voice;

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Create a SoftwareSerial object

void setup() {
  mySerial.begin(9600);  // Start SoftwareSerial communication
  Serial.begin(9600);    // Start default serial communication for debugging
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
  while (mySerial.available()) {  // Check if data is available from SoftwareSerial
    delay(10);
    char c = mySerial.read();  // Read the incoming byte
    if (c == '#') {
      break;  // End of command
    }
    voice += c;  // Add the character to the voice command
  }

  if (voice.length() > 0) {
    if (voice == "forward") {
      moveForward();
    }
    if (voice == "backward") {
      moveBackward();
    }
    if (voice == "stop") {
      stopMotors();
    }
    if (voice == "left") {
      turnLeft();
    }
    if (voice == "right") {
      turnRight();
    }
    voice = "";  // Clear the command after processing
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(enA, 180);  // Adjust speed as needed
  analogWrite(enB, 180);  // Adjust speed as needed
  mySerial.println("Moving Forward");
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(enA, 180);  // Adjust speed as needed
  analogWrite(enB, 180);  // Adjust speed as needed
  mySerial.println("Moving Backward");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(enA, 0);  // Stop motors
  analogWrite(enB, 0);  // Stop motors
  mySerial.println("Motors Stopped");
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(enA, 180);  // Adjust speed as needed
  analogWrite(enB, 180);  // Adjust speed as needed
  mySerial.println("Turning Left");
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(enA, 180);  // Adjust speed as needed
  analogWrite(enB, 180);  // Adjust speed as needed
  mySerial.println("Turning Right");
}
