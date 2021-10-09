// define pins
int xpin = A0;
int ypin = A1;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;

// inititalize hyperparameters
int offset = 100;
int xerror = 0;
int yerror = 0;
const int repetition = 500;


void setup() {
  // initialization settings
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  
  // calculate error accumulate reading for {repetition}
  for (int i=1; i<=repetition; i++){
      // calculare error
      int temp_xerror = 512 - analogRead(xpin);
      int temp_yerror = 512 - analogRead(ypin);
      
      // acuumulate error
      xerror += temp_xerror;
      yerror += temp_yerror;
    }

  // average the error and cast to integer
  xerror = (int) xerror / repetition;
  yerror = (int) yerror / repetition;

  // print out errors
  Serial.println("xerror is " + String(xerror));
  Serial.println("yerror is " + String(yerror));
}

void loop() {
  // Get reading
  int x_reading = analogRead(xpin) + xerror;
  int y_reading = analogRead(ypin) + yerror;
  
  // handle edge cases
  if (x_reading < 0) {x_reading = 0;}
  if (y_reading < 0) {y_reading = 0;}
  if (x_reading > 1023) {x_reading = 1023;}
  if (y_reading > 1023) {y_reading = 1023;}

  // turn on led on the each corner and all 0 if not in corner
  if (x_reading < offset && y_reading < offset){light_those_LEDS(1,0,0,0);}
  else if (x_reading < offset && y_reading > 1023-offset){light_those_LEDS(0,1,0,0);}
  else if (x_reading > 1023-offset && y_reading > 1023-offset){light_those_LEDS(0,0,1,0);}
  else if (x_reading > 1023-offset && y_reading < offset){light_those_LEDS(0,0,0,1);}
  else {light_those_LEDS(0,0,0,0);}
  
}

// function for turning on light
void light_those_LEDS(bool led1_state, bool led2_state, bool led3_state, bool led4_state){
    digitalWrite(led1, led1_state);
    digitalWrite(led2, led2_state);
    digitalWrite(led3, led3_state);
    digitalWrite(led4, led4_state);
  }
