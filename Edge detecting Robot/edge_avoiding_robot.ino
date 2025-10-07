// Define speed variable
int speed = 180; // Adjust as needed

// Define motor control pins
const int ENA = 10;  // Enable pin for left motor
const int IN1 = 9;  // Left motor input 1
const int IN2 = 8;  // Left motor input 2
const int IN3 = 7; // Right motor input 1
const int IN4 = 6; // Right motor input 2
const int ENB = 5;  // Enable pin for right motor

// Define sensor pins
const int sl = 13; // Sensor 1 input (left)
const int sr = 12; // Sensor 2 input (right)

// Sensor values
int SlV = 0;
int SrV = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(sl, INPUT);
  pinMode(sr, INPUT);

  stopMotors();
}

void loop() {
  SlV = digitalRead(sl);
  SrV = digitalRead(sr);

  if (SrV == LOW && SlV == LOW) {
    moveForward();
  } else {
    moveBackward();
    delay(400);

    if (SrV == HIGH && SlV == HIGH) {
      turnRight();
    } else if (SrV == LOW && SlV == HIGH) {
      turnRight();
    } else if (SrV == HIGH && SlV == LOW) {
      turnLeft();
    }

    delay(550);
    moveForward();
    delay(200);
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
