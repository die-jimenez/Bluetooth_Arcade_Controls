#include <BleKeyboard.h>
#include "ArcadeButton.h"
#include "Joystick.h"
BleKeyboard bleKeyboard;
bool bluetoothConectado;

//Pines de Leds
#define GPIO_RED_LED 4
#define GPIO_BLUE_LED 5
#define GPIO_GREEN_LED 6
#define GPIO_YELLOW_LED 7

//Pines de Botones
#define GPIO_RED_BUTTON 15
#define GPIO_BLUE_BUTTON 16
#define GPIO_GREEN_BUTTON 17
#define GPIO_YELLOW_BUTTON 18

//Pines del Joystick
#define GPIO_FRONT_RED 8
#define GPIO_DOWN_ORANGE 9
#define GPIO_LEFT_YELLOW 10
#define GPIO_RIGHT_GREEN 11


//Keys de botones
const char RED_KEY = ' ';
const char BLUE_KEY = '1';
const char GREEN_KEY = '2';
const char YELLOW_KEY = '3';



//Declaracion de botones
ArcadeButton redButton(GPIO_RED_BUTTON, GPIO_RED_LED, RED_KEY);
ArcadeButton blueButton(GPIO_BLUE_BUTTON, GPIO_BLUE_LED, BLUE_KEY);
ArcadeButton greenButton(GPIO_GREEN_BUTTON, GPIO_GREEN_LED, GREEN_KEY);
ArcadeButton yellowButton(GPIO_YELLOW_BUTTON, GPIO_YELLOW_LED, YELLOW_KEY);
//Declaracion de Joystick
Joystick joystick(GPIO_FRONT_RED, GPIO_DOWN_ORANGE, GPIO_LEFT_YELLOW, GPIO_RIGHT_GREEN);


void setup() {
  //inicializa la libreria
  bleKeyboard.begin();
  Serial.begin(115200);
  delay(2000);

  Serial.println("La libreria de bluetooth se inicio");
  Serial.println("Si la luz azul del ESP32 esta encendida, se conecto por bluetooth");

  //Inicializar botones
  redButton.Init(HIGH);
  blueButton.Init(HIGH);
  greenButton.Init(HIGH);
  yellowButton.Init(HIGH);

  //InitButtons();
  // joystick.Init();
  EncenderLedIntegrado();
  bleKeyboard.setDelay(0);
}

void loop() {

  //Aviso de que se desconecto del dispositivo
  if (!bleKeyboard.isConnected() && bluetoothConectado == true) {
    ApagarLedIntegrado();
    bluetoothConectado = false;
    Serial.println("Es ESP32 fue desconectado");
  }

  //Cuando esta conectado
  if (bleKeyboard.isConnected()) {
    //Aviso de que el ESP32 se conecto por bluetooth a algun dispositivo
    if (bluetoothConectado == false) {
      Serial.println("El ESP32 se conecto como teclado");
      bluetoothConectado = true;
      digitalWrite(2, HIGH);
    }

    //Joystick
    // joystick.Loop(bleKeyboard);

    if (redButton.isPressed()) {
        redButton.Press(bleKeyboard);
        redButton.isKeyDown = true;
        Serial.print(".");
    } else {
      if (redButton.isKeyDown) {
        redButton.Release(bleKeyboard);
        Serial.println("");
        Serial.println("solto la tecla");
        redButton.isKeyDown = false;
      }
    }

    //Botones
    // if (redButton.isPressed()) {
    //   if (!redButton.isKeyDown) {
    //     redButton.Press(bleKeyboard);
    //     redButton.isKeyDown = true;
    //   }
    //   //delay(50);
    // } else redButton.isKeyDown = false;

    if (blueButton.isPressed()) {
      if (!blueButton.isKeyDown) {
        blueButton.Press(bleKeyboard);
        blueButton.isKeyDown = true;
      }
      //delay(50);
    } else blueButton.isKeyDown = false;

    if (greenButton.isPressed()) {
      if (!greenButton.isKeyDown) {
        greenButton.Press(bleKeyboard);
        greenButton.isKeyDown = true;
      }
      //delay(50);
    } else greenButton.isKeyDown = false;

    if (yellowButton.isPressed()) {
      if (!yellowButton.isKeyDown) {
        yellowButton.Press(bleKeyboard);
        yellowButton.isKeyDown = true;
      }
      //delay(50);
    } else yellowButton.isKeyDown = false;
  }
  delay(10);
}


// void InitButtons() {
//   pinMode(greenButton, INPUT_PULLUP);
// }

void ApagarLedIntegrado() {
  neopixelWrite(48, 0, 0, 0);  // apagado
}

void EncenderLedIntegrado() {
  neopixelWrite(48, 0, 0, 20);  // azul, valores de 0 a 255
}
