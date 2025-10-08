// const int buttonPin = 2;
// const int RledPin = 3;
// const int GledPin = 4;
// const int BledPin = 5;

// int ledcolor = 0;
// int buttonState = 0;
// bool ButtonPressed = false;
// unsigned long previousMillis = 0;
// const long interval = 1000;
// bool ledColorOrder = true;

// void setup() {
//   // put your setup code here, to run once:
//     pinMode(RledPin, OUTPUT);
//     pinMode(GledPin, OUTPUT);
//     pinMode(BledPin, OUTPUT);
//     pinMode(buttonPin, INPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   buttonState = digitalRead(buttonPin);
//   if (buttonState == HIGH && !ButtonPressed) {
//     ledcolor = ledcolor + 1;
//     ButtonPressed = true;
//   }
//   if (buttonState == LOW && ButtonPressed) {
//     ButtonPressed = false;
//   }

//   unsigned long currentMillis = millis();
//   if (currentMillis - previousMillis >= interval) {
//     previousMillis = currentMillis;
//     if (ledColorOrder == true) {
//       ledcolor = ledcolor + 1;
//       if (ledcolor > 3)
//         ledcolor = 0;
//     } else {
//         ledcolor = ledcolor - 1;
//         if (ledcolor < 0)
//         ledcolor = 3;
//     }
//   }

//   if (ledcolor == 0) {
//     // RED
//     digitalWrite(RledPin, LOW);
//     digitalWrite(GledPin, HIGH);
//     digitalWrite(BledPin, HIGH);
//   }
//   else if(ledcolor == 1) {
//     //Green
//     digitalWrite(RledPin, HIGH);
//     digitalWrite(GledPin, LOW);
//     digitalWrite(BledPin, HIGH);
//   }
//   else if(ledcolor == 2) {
//     //BLUE
//     digitalWrite(RledPin, HIGH);
//     digitalWrite(GledPin, HIGH);
//     digitalWrite(BledPin, LOW);
//   }
//   else if(ledcolor == 3) {
//     //WHITE
//     digitalWrite(RledPin, LOW);
//     digitalWrite(GledPin, LOW);
//     digitalWrite(BledPin, LOW);
//   }
// }

const int RledPin = 9;
// the Pw
const int GledPin = 10;
// the P
const int BledPin = 11;
// the P
int brightness = 0;
int fadeAmount = 5;
int ledcolor = 0;

void setup() {
pinMode(RledPin, OUTPUT);
pinMode(GledPin, OUTPUT);
pinMode(BledPin, OUTPUT);
}

void loop() {
  if (ledcolor == 0){
  analogWrite(RledPin, brightness);
  analogWrite(GledPin, 255);
  analogWrite(BledPin, 255);
  }
  if (ledcolor == 1){
  analogWrite(RledPin, 255);
  analogWrite(GledPin, brightness);
  analogWrite(BledPin, 255);
  }
  if (ledcolor == 2){
  analogWrite(RledPin, 255);
  analogWrite(GledPin, 255);
  analogWrite(BledPin, brightness); 
  }

  brightness = brightness + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount -fadeAmount;
    if (brightness >= 255) {
      ledcolor = ledcolor + 1;
      if(ledcolor > 2)
        ledcolor = 0;
    }
  }
  delay (30);
}