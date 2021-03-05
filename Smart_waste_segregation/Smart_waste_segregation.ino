


#include <Servo.h>
//Servo lcd(8,9,10,11,12,13);//RS,EN,D4,D5,D6,D7
#define ir1 D1


int sen1 = A0; //#define sen1 A0 // moisture
int sensor2 = 4;
int onetime = 0, onetime1 = 0 ;
int distance = 0;
long duration;
int pos = 0;


int wet = 0, moisture = 0, object = 0, cabin2 = 0, c = 0, c2 = 0;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most board

void setup()
{

  pinMode(ir1, INPUT);
  pinMode(sen1, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  myservo.attach(D8, 500, 2500);  // attaches the servo on pin  to the servo object
  myservo.write(90);
  delay(3000);
}

void loop()


{


  object = digitalRead(ir1);
  moisture = analogRead(sen1);
  if (object == LOW)
  {
    moisture = analogRead(sen1);
    Serial.println("moisture = ");
    Serial.println(moisture);
    delay(500);


    sen1 = distance;
    delay(10);
    sensor2 = distance;
    delay(10);

    Serial.println(sen1);
    Serial.println(sensor2);

    int lvl1 = (16 - sen1) * 6.5;
    int lvl2 = (16 - sensor2) * 6.5;
    Serial.println(lvl1);
    Serial.println(lvl2);

    if (moisture > 10)
    {

      for (pos = 0; pos <= 135; pos += 1) { // goes from 0 degrees to 130 degrees
        // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }

   
    }

    else if (moisture <= 10)
    {

      for (pos = 180; pos >= 135; pos -= 1) { // goes from 180 degrees to 135 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
      }

    }

  }


}



//
//  }



//Blynk.virtualWrite(V6, lvl2); // Temperature for gauge}
