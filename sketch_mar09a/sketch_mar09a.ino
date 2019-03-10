#include <Servo.h>. 
const int trigPin = 11;
const int echoPin = 12;

long duration;
int distance;
Servo myServo; //created an object of class servo in servo.h header file
void setup() {
  Serial.begin(57600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  
  myServo.attach(13); 
}
void loop() {
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(5);
  distance = calculateDistance();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print(".");
  }
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(5);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
int calculateDistance(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
