// Define the pins for ultrasonic sensor
#define trig A1
#define echo A0

// Define motor pins
#define enA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define enB 5

// Define variables
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up the ultrasonic sensor pins
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Set up motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
  // Clear the trig pin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // Send a pulse to the sensor
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure the duration of the pulse
  duration = pulseIn(echo, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;

  // Print the distance to the object
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Adjust the motor speed based on the distance
  if (distance <= 10) {
    // If object is too close, stop
    stopMotors();
  } else if (distance > 10 && distance <= 50) {
    // If object is within medium range, move forward at full speed
    moveForward();
  } else if (distance > 50 && distance <= 100) {
    // If object is within far range, move forward at reduced speed
    moveForwardSlow();
  } else {
    // If object is too far, stop
    stopMotors();
  }

  // Delay before next reading
  delay(100);
}

// Function to stop both motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}

// Function to move both motors forward at full speed
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(enA, 180);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(enB, 180);
}

// Function to move both motors forward at reduced speed
void moveForwardSlow() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(enA, 110);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(enB, 110);
}
