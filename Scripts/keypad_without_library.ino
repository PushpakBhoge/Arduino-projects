
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char button_pressed;

//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {13,12,11,10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7,6,5,4}; //connect to the column pinouts of the keypad

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i <= 3; i++) {
      pinMode(colPins[i], OUTPUT);
      pinMode(rowPins[i], INPUT_PULLUP);
    }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x = 0; x <= 3; x++){
      for (int y = 0; y <= 3; y++){
          digitalWrite(colPins[x], LOW);
          int reading = digitalRead(rowPins[y]);
          if (reading==0){
              button_pressed = hexaKeys[x][y];
              Serial.println(String(x)+ " " + String(y) + " " + button_pressed);
              delay(200);
            }
        }
        delay(200);
    }
}
