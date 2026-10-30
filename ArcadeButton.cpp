#include "HardwareSerial.h"
#include "esp32-hal-gpio.h"
#include "ArcadeButton.h"

ArcadeButton::ArcadeButton(uint8_t _pinButton, uint8_t _pinLed, char _key) {
  pinButton = _pinButton;
  pinLed = _pinLed;
  key = _key;
}

ArcadeButton::~ArcadeButton() {
}

void ArcadeButton::Init(bool _ledState) {
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  if (_ledState == HIGH) LedOn();
  else LedOff();
}

void ArcadeButton::Press(BleKeyboard _bleKeyboard) {
  _bleKeyboard.press(key);
  // _bleKeyboard.release(key);
  // Serial.print(key);
  // Serial.println(" fue presionada");
}

void ArcadeButton::Release(BleKeyboard _bleKeyboard) {
  _bleKeyboard.release(key);
}

void ArcadeButton::LedOn() {
  digitalWrite(pinLed, HIGH);
}

void ArcadeButton::LedOff() {
  digitalWrite(pinLed, LOW);
}

bool ArcadeButton::Read() {
  return digitalRead(pinButton);
}

bool ArcadeButton::isPressed() {
  if (Read() == LOW) return true;
  else return false;
}
