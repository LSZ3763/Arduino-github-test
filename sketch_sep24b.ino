const int rLEDPin = 3;
const int gLEDPin = 4;
const int bLEDPin = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(rLEDPin, OUTPUT);
  pinMode(gLEDPin, OUTPUT);
  pinMode(bLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    // red
  digitalWrite(rLEDPin, LOW);
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(bLEDPin, HIGH); 
  delay(1000); 
  // turn off
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(bLEDPin, HIGH);
  delay(1000);  
// green
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, LOW);
  digitalWrite(bLEDPin, HIGH); 
  delay(1000);
// turn off
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(bLEDPin, HIGH);
  delay(1000);
// blue
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(bLEDPin, LOW); 
  delay(1000);
// turn off
  digitalWrite(rLEDPin, HIGH);
  digitalWrite(gLEDPin, HIGH);
  digitalWrite(bLEDPin, HIGH);
  delay(1000);
}

  // digitalWrite(6, HIGH);
  // digitalWrite(8, HIGH);
  // delay(1000);
  // digitalWrite(6, LOW);
  // digitalWrite(8, LOW);
  // delay(1000);
