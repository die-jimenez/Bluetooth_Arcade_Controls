#include <BleKeyboard.h>

#ifndef __ARCADEBUTTON_H__
#define __ARCADEBUTTON_H__

#include <Arduino.h>
#include <BleKeyboard.h>


class ArcadeButton {
private:
  uint8_t pinButton;
  uint8_t pinLed;
  char key;

  


public:
  ArcadeButton(uint8_t _pinButton, uint8_t _pinLed, char _key);
  ~ArcadeButton();

  void Init(bool _ledState);
  void Press(BleKeyboard _bleKeyboard);
  void Release(BleKeyboard _bleKeyboard);
  bool isPressed();
  bool Read();
  void LedOn();
  void LedOff();
  
  //Se utiliza para que solo se ejecute una accion una sola vez, aunque se deje presioanada la tecla
  bool isKeyDown;
};




#endif
