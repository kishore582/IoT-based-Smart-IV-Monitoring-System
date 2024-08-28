#include <Ultrasonic.h>
#include <Servo.h>
#include <PulseSensor.h>

/* D0 = 16
D1 = 5
D2 = 4
D3 = 0
D4 = 2
D5 = 14
D6 = 12
D7 = 13
D8 = 15 */

const int trigPin = 16;
const int echoPin = 5;
const int buzzerPin = 4;
const int servoPin = 12;
const int pulseSensorPin = 0;
int beatPerMinute;
int Threshold = 550;

Servo myservo;
Ultrasonic sonar(trigPin,echoPin);

void setup()
{
  Serial.begin(9600);
  pulseSensor.begin(pulseSensorPin);
  pinMode(buzzerPin,OUTPUT);
  delay(500);
  myservo.attach(14);
}

void loop()
{
  //PULSE SENSOR
  beatPerMinute = pulseSensor.getBeatsPerMinute();
  Serial.println(beatPerMinute);
  delay(10);

  //SONAR
  int duration = sonar.read();
  int distance = duration / 2.0;
  Serial.println(distance);

  //SONAR AND SERVO MOTOR
  if (distance<10)
  {
    digitalWrite(buzzerPin, LOW);
    myservo.write(0);
    delay(1000);
  }
  else
  { 
    digitalWrite(buzzerPin, HIGH);
    myservo.write(90);
    delay(1000);
  }
}