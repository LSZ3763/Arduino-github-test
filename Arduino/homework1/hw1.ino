const int buttonPin = 2;
const int RledPin = 3;
const int GledPin = 5;
const int BledPin = 6;

int buttonState = 0;
bool ButtonPressed = false;
int ledcolor = 0;
String currentcolor = "LED off";

int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && !ButtonPressed) {
    ledcolor++;
    ButtonPressed = true;
  }
  if (buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }
  if (ledcolor > 7) ledcolor = 0;

  brightness += fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  if (ledcolor == 0) {
    currentcolor = "LED off";
    analogWrite(RledPin, 0);
    analogWrite(GledPin, 0);
    analogWrite(BledPin, 0);
  }
  else if (ledcolor == 1) {
    currentcolor = "Red";
    analogWrite(RledPin, brightness);
    analogWrite(GledPin, 0);
    analogWrite(BledPin, 0);
  }
  else if (ledcolor == 2) {
    currentcolor = "Green";
    analogWrite(RledPin, 0);
    analogWrite(GledPin, brightness);
    analogWrite(BledPin, 0);
  }
  else if (ledcolor == 3) {
    currentcolor = "Blue";
    analogWrite(RledPin, 0);
    analogWrite(GledPin, 0);
    analogWrite(BledPin, brightness);
  }
  else if (ledcolor == 4) {
    currentcolor = "Yellow";
    analogWrite(RledPin, brightness);
    analogWrite(GledPin, brightness);
    analogWrite(BledPin, 0);
  }
  else if (ledcolor == 5) {
    currentcolor = "Purple";
    analogWrite(RledPin, brightness);
    analogWrite(GledPin, 0);
    analogWrite(BledPin, brightness);
  }
  else if (ledcolor == 6) {
    currentcolor = "Cyan";
    analogWrite(RledPin, 0);
    analogWrite(GledPin, brightness);
    analogWrite(BledPin, brightness);
  }
  else if (ledcolor == 7) {
    currentcolor = "White";
    analogWrite(RledPin, brightness);
    analogWrite(GledPin, brightness);
    analogWrite(BledPin, brightness);
  }
  
  Serial.print("Current Color: ");
  Serial.println(currentcolor);

  delay(30);
}
