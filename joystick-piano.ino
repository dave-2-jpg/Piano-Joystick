int red = 12;
int yellow = 11;
int blue = 10;
int green = 8;
//frequencies
int buzzer = 6;
//A4, B4, C4, D4, pressed
int frequency[] = {440, 494, 523, 587, 1000};

//directions
int xDir = A0;
int yDir = A1;
int sW = 7;

void setup() {
  //leds
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  //buzzer
  pinMode(buzzer, OUTPUT);
  //joystick
  pinMode(xDir, INPUT);
  pinMode(yDir, INPUT);
  pinMode(sW, OUTPUT);
  digitalWrite(sW, HIGH);

  Serial.begin(9600);

}

void loop() {
  //read values
  int sVal = digitalRead(sW);
  int xVal = analogRead(xDir);
  int yVal = analogRead(yDir);
 
 //x direction
  if (xVal < 400) {
    digitalWrite(green, HIGH);
    tone(buzzer, frequency[2]);
    noTone(buzzer);
  }
  else if (xVal > 600) {
    digitalWrite(yellow, HIGH);
    tone(buzzer, frequency[0]);
    noTone(buzzer);
  }
  else {
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    
  }

  //y direction
   if (yVal < 400) {
    digitalWrite(blue, HIGH);
    tone(buzzer, frequency[3]);
    noTone(buzzer);
  }
  else if (yVal > 600) {
    digitalWrite(red, HIGH);
    tone(buzzer, frequency[2]);
    noTone(buzzer);
  }
  else {
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
  }

  //buzzer
  if (sVal == 0) {
    tone(buzzer, frequency[0]);
    noTone(buzzer);
  }
}
