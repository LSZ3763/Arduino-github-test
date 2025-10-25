const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;
// the PM pin the Red LED is attached to
// the PWM pin the Green LED is attached to
// the PWM pin the Blue LED is attached to

int mood = 0;
const int neutralMood = 10;
int buttonState = 0;
bool ButtonPressed = false;
// the setup routine runs once when you press reset:
void setup(){
pinMode(buttonPin, OUTPUT);
pinMode(RledPin, OUTPUT);
pinMode(GledPin, OUTPUT);
pinMode(BledPin, OUTPUT);
//intialize the mood state
mood = neutralMood;
}

void loop() {
  showLEDState(mood);

  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH && ! ButtonPressed) {
  mood = mood + 1;
  if (mood > 20) mood = 20;
  }
  if (buttonState == LOW && ButtonPressed) {
  ButtonPressed = false;
  }
}

void showLEDState(int State){
  float brightnessInterval = 255 / 10.0;
  if(mood >= neutralMood){
    analogWrite(RledPin, 0);
    analogWrite(GledPin, 255 - brightnessInterval * (state - neutralMood));
    analogWrite(BledPin, brightnessInterval * (state - neutralMood));
  }
  else{
    analogWrite(RledPin, brightnessInterval * (neutralMood - state));
    analogWrite(GledPin, 255 -brightnessInterval * (neutralMood - state));
    analogWrite(BledPin, 0);
  }
}
  

//   unsigned long currentMillis = millis();
//   if(currentMillis - previousMillis > 1000){
//     mood = mood + fadingDirection;
//   if (mood >= 20 || mood <= 0)
//     fadingDirection -fadingDirection;
//   previousMillis = currentMillis;
//   }
// }