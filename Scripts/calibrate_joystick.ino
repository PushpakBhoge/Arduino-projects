// define pins
int xpin = A0;
int ypin = A1;

// inititalize hyperparameters
int xerror = 0;
int yerror = 0;
const int repetition = 500;


void setup() {
  // initialization settings
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
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

  if (x_reading < 0) {x_reading = 0;}
  if (y_reading < 0) {y_reading = 0;}
  if (x_reading > 1023) {x_reading = 1023;}
  if (y_reading > 1023) {y_reading = 1023;}

  // print reading
  Serial.println("x reading is " + String(x_reading));
  Serial.println("y reading is " + String(y_reading));

  delay(500);
}
