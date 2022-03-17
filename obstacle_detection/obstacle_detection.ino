// C++ code
//

int ledPin = 3
;
int alarmPin = 4;

#define echoPin 9
#define trigPin 10

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(alarmPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop()
{
  long timer, centimeters;

  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  timer = pulseIn(echoPin, HIGH);
  
  // Convert time to distance
  centimeters = microsecondsToCentimeters(timer);
  
  // Print distance result in centimeters
  Serial.print(centimeters);
  Serial.print("centimeters");
  Serial.println();
  
  // If distance between sensor and obstacle is < 60
  if(centimeters<60){
    // Set Alarm on
    digitalWrite(alarmPin,HIGH);
    // Flick LED light on and off
    digitalWrite(ledPin,HIGH);
    delay(1000);               
    digitalWrite(ledPin, LOW);   
    delay(1000);
  }
  // Turn LED off if distance is > or = 60
  else if (centimeters>=60){
    digitalWrite(ledPin,LOW);
    digitalWrite(alarmPin,LOW);
  }
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
