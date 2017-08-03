
#include <Servo.h>
// sent to Git

Servo finger;  // create servo object to control a servo
Servo lid;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int val1 = 0;
int val2 = 0;
int val3 = 0;
int potpin = 0;

void setup() {
 finger.attach(5,740,2450);  // attaches the servo on pin 5 to the servo object - finger
 lid.attach(6,740,2450);  // attaches the servo on pin 6 to the servo object - lid
 pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {

val1=analogRead(potpin);
Serial.print ("Val1 =");
Serial.println (val1);
val2 = map(val1, 0, 1023, 0, 180);
val3 = map(val1, 0, 1023, 180, 0);
Serial.print ("Val2 =");
Serial.println (val2);
Serial.print ("Val3 =");
Serial.println (val3);
Serial.print("Switch Pin");
Serial.println(digitalRead(2));

if (val2 < 30) val2 = 30;
if (val2 > 120) val2 = 120;

if (val3 < 20) val3 = 20;
if (val3 > 100) val3 = 100;

finger.write(val2);
lid.write(val3);

delay (50);
}

