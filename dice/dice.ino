/*
  aaa  
 f   b
  ggg
 e   c
  ddd
*/
const int g = 12;
const int f = 11;
const int a = 10;
const int b = 9;
const int c = 8;
const int d = 7;
const int e = 6;

const int button = 2;
const int animationDelay = 90;

int number = 0;
boolean pressed = false;
long time = 0;


void setup() {    
  //pins for 7 segment display
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  //input for switch
  pinMode(button, INPUT);

  //creates more randomness
  randomSeed(analogRead(0));
}

void loop() {

  if(digitalRead(button) == HIGH && !pressed){
    showAnimation();
    number = random(1, 7);
    displayNumber(number);
    time = millis();
    pressed = true;
  }

  if(time + 3000 < millis() && pressed){
    pressed = false;
    setElements(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
  }
}

void showAnimation(){
  setElements(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
  delay(animationDelay);
  setElements(HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
  delay(animationDelay);
  setElements(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
  delay(animationDelay);
  setElements(HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW);
  delay(animationDelay);
  setElements(HIGH, HIGH, HIGH, HIGH, HIGH, LOW, LOW);
  delay(animationDelay);
  setElements(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);
  delay(animationDelay);
  setElements(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);
  delay(1000);
}

void displayNumber(int num){
  if(num == 0){
    setElements(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);
  }else if(num == 1){
    setElements(LOW, HIGH, HIGH, LOW, LOW, LOW, LOW);
  }else if(num == 2){
    setElements(HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH);
  }else if(num == 3){
    setElements(HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH);
  }else if(num == 4){
    setElements(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH);
  }else if(num == 5){
    setElements(HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH);
  }else if(num == 6){
    setElements(HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH);
  }else if(num == 7){
    setElements(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
  }else if(num == 8){
    setElements(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);
  }else if(num == 9){
    setElements(HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH);
  }
}

void setElements(int aOut, int bOut,int cOut,int dOut,int eOut,int fOut,int gOut){
  digitalWrite(a, aOut);
  digitalWrite(b, bOut);
  digitalWrite(c, cOut);
  digitalWrite(d, dOut);
  digitalWrite(e, eOut);
  digitalWrite(f, fOut);
  digitalWrite(g, gOut);
}

