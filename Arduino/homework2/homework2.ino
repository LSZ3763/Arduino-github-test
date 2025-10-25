const int buttonPin = 2;
const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;

int mood = 0;
const int neutralMood = 10;
int buttonState = 0;
bool ButtonPressed = false;
unsigned long touchedTimer = 0;
unsigned long reducedTimer = 0;
const long unTouchInterval = 5000;
const long reducedInterval = 1000;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  mood = neutralMood;
}

void fadeToLEDState(int fromState, int toState) {
  int steps = 50;
  for (int i = 0; i <= steps; i++) {
    float t = (float)i / steps;
    float currentState = fromState + t * (toState - fromState);
    showLEDState(currentState);
    delay(20);
  }
}

void showLEDState(float state) {
  float brightnessInterval = 255 / 10.0;
  int r, g, b;

  if (state <= neutralMood) {
    r = 0 + brightnessInterval * state;
    g = 255 - brightnessInterval * state;
    b = 255;
  } else {
    r = 255;
    g = 0 + brightnessInterval * (state - neutralMood);
    b = 255 - brightnessInterval * (state - neutralMood);
  }

  analogWrite(RledPin, constrain(r, 0, 255));
  analogWrite(GledPin, constrain(g, 0, 255));
  analogWrite(BledPin, constrain(b, 0, 255));
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && !ButtonPressed) {
    int oldMood = mood;
    mood = mood + 1;
    if (mood > 20) mood = 20;
    fadeToLEDState(oldMood, mood);
    touchedTimer = millis();
    ButtonPressed = true;
  }

  if (buttonState == LOW && ButtonPressed) {
    ButtonPressed = false;
  }

  unsigned long currentTimer = millis();
  if (currentTimer - touchedTimer > unTouchInterval) {
    if (currentTimer - reducedTimer > reducedInterval) {
      int oldMood = mood;
      mood = mood - 1;
      if (mood < 0) mood = 0;
      fadeToLEDState(oldMood, mood);
      reducedTimer = currentTimer;
    }
  }
}
