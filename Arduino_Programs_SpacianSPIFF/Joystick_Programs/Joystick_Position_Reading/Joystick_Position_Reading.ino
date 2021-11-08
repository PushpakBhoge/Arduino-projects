int X=0,Y=0,K=0;
void setup() {
  pinMode(3,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  Serial.begin(9600);
}

void loop() {
  Y=analogRead(A0);
  X=analogRead(A1);
  K=digitalRead(3);
  Serial.print("X=");
  Serial.println(X);
  Serial.print("Y=");
  Serial.println(Y);
  Serial.print("K=");
  Serial.println(K);
  delay(300);
}
