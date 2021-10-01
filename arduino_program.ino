String data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (13,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    data = Serial.readString();
    if (data == "ON")
    {
      digitalWrite(13, HIGH);
    }
    else if (data == "ON2")
    {
      digitalWrite(12, HIGH);
    }
    else if (data == "ON3")
    {
      digitalWrite(11, HIGH);
    }
    else if (data == "OFF")
    {
      digitalWrite(13, LOW);
    }
    else if (data == "OFF2")
    {
      digitalWrite(12, LOW);
    }
    else if (data == "OFF3")
    {
      digitalWrite(11, LOW);
    }
  }

}
