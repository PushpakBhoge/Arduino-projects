// defines pins
#define echoPin 2
#define trigPin 4

// defines variables
long duration;
float distance;
float speed_of_sound = 331.5; // m/s
float room_temperetue = 31; // degree celecius
float speed_constant = 1.0;

void setup() {
  // initialize the pins
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // calculate speed_constant 
  speed_constant = speed_of_sound + 0.6 * room_temperetue; // get speed of sound speed at tempereture
  speed_constant = (speed_constant * 100.0) / 1000000.0; // convert speed from m/s into cm/microseconds
  
  // Calculating the distance
  distance = (duration/2) * speed_constant ;
  
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
