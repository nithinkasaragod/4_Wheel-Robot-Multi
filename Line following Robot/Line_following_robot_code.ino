#define LS A1    // left sensor
#define RS A0    // right sensor
#define speed 150  // speed of motors

/*-------defining Outputs------*/
#define ENA 10   // enA pin (left motor enable)
#define IN1 9    // left motor control pin 1
#define IN2 8    // left motor control pin 2
#define IN3 7    // right motor control pin 1
#define IN4 6    // right motor control pin 2
#define ENB 5    // enB pin (right motor enable)

void setup()
{
  pinMode(LS, INPUT);     // Set left sensor pin as input
  pinMode(RS, INPUT);     // Set right sensor pin as input
  pinMode(IN1, OUTPUT);   // Set left motor control pin 1 as output
  pinMode(IN2, OUTPUT);   // Set left motor control pin 2 as output
  pinMode(IN3, OUTPUT);   // Set right motor control pin 1 as output
  pinMode(IN4, OUTPUT);   // Set right motor control pin 2 as output
  pinMode(ENA, OUTPUT);   // Set left motor enable pin as output
  pinMode(ENB, OUTPUT);   // Set right motor enable pin as output
}

void loop()
{
  if (!digitalRead(LS) && !digitalRead(RS))  // Move Forward
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }
  else if (digitalRead(LS) && !digitalRead(RS))  // Turn right
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }
  else if (!digitalRead(LS) && digitalRead(RS))  // Turn left
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }
  else if (digitalRead(LS) && digitalRead(RS))  // Stop
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
