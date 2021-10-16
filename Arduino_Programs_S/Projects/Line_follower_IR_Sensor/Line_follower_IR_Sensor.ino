int ir1;
int ir2;

void setup() {
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  Serial.begin(9600);
}

void loop() {
  ir1 = 1 - digitalRead(9);
  ir2 = 1 - digitalRead(10);
  if (ir1 == 0 && ir2 == 0) {
    CarControl(1, 0, 1, 0); // Go forward
  }
  if (ir1 == 1 && ir2 == 0) { // Turn left
    CarControl(0, 0, 1, 0);
  }
  if (ir1 == 0 && ir2 == 1) { // Turn right
    CarControl(1, 0, 0, 0);
  }
  if (ir1 == 1 && ir2 == 1) { // Black square for stop
    CarControl(0, 0, 0, 0);
  }
}

void CarControl(int a, int b, int c, int d) {
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
}
