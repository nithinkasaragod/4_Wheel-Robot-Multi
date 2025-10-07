#include<SoftwareSerial.h>

#define enA 10
#define IN1 9
#define IN2 8
#define IN3 7
#define IN4 6
#define enB 5

// adjust speed accordingly (1-255)
#define speed 200

SoftwareSerial bt(4, 3); // RX, TX

char data;

void setup() { 
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  bt.begin(9600);
}
void loop()
{
   while (bt.available())
   { 
      { data = bt.read();
        Serial.println(data);}
      switch (data)
       {
          case 'F':                               
            Serial.println("Forward");
            forward();
            break;
          case 'B':                
           Serial.println("Reverse");
            reverse();
            break;
          case 'L':        
           Serial.println("Left");
            left();
            break;         
          case 'R':                    
            Serial.println("Right");
            right();
            break;
          case 'S':                                           
            Serial.println("Stop");
            stoprobot();
            break;     
          }
      }                                                             
       if (bt.available() < 0)                             
        {
         Serial.println("No Bluetooth Data ");         
        }
  delay(100); 
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(enA,speed);
  analogWrite(enB,speed);
  // Serial.println(speedenA);
  // Serial.println(speedenB);
  delay(20);
}
void reverse() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(enA,speed);
  analogWrite(enB,speed);
  delay(20);
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(enA,speed);
  analogWrite(enB,speed);
  delay(20);
}
void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(enA,speed);
  analogWrite(enB,speed);
  delay(20);
}
void stoprobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(20);
}