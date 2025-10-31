const int rLEDPin = 9;
const int gLEDPin = 10;
const int bLEDPin = 11;
const int pushButton = 2; 
const int ledPin = 3;

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pushButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(pushButton);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
    }
  }
//     // red
//   digitalWrite(rLEDPin, LOW);
//   digitalWrite(gLEDPin, HIGH);
//   digitalWrite(bLEDPin, HIGH); 
//   delay(8000); 
//   // turn off
//   digitalWrite(rLEDPin, HIGH);
//   digitalWrite(gLEDPin, HIGH);
//   digitalWrite(bLEDPin, HIGH);
//   delay(1000);  
// // green
//   digitalWrite(rLEDPin, HIGH);
//   digitalWrite(gLEDPin, HIGH);
//   digitalWrite(bLEDPin, LOW); 
//   delay(5000);
// // turn off
//   digitalWrite(rLEDPin, HIGH);
//   digitalWrite(gLEDPin, HIGH);
//   digitalWrite(bLEDPin, HIGH);
//   delay(1000);
// // yellow
//   digitalWrite(rLEDPin, LOW);
//   digitalWrite(gLEDPin, HIGH);
//   digitalWrite(bLEDPin, LOW); 
//   delay(1000);
// // turn off
//   digitalWrite(rLEDPin, HIGH);
//   digitalWrite(gLEDPin, HIGH);
//   digitalWrite(bLEDPin, HIGH);
//   delay(1000);
// }

  // digitalWrite(6, HIGH);
  // digitalWrite(8, HIGH);
  // delay(1000);
  // digitalWrite(6, LOW);
  // digitalWrite(8, LOW);
  // delay(1000);
