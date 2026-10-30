# Bluetooth Arcade Controls
Este código fue creado para una **ESP32 S3 N8R16**.  
La librería **BleKeyboard** es compatible con este modelo, pero es necesario modificar un archivo interno de la librería.

### Pasos a seguir

1. Abrí el archivo `BleKeyboard.cpp`, ubicado en la carpeta de la librería  
   `ESP32_BLE_Keyboard` (generalmente en `Documentos/Arduino/Libraries`).

2. Localizá las siguientes líneas que causan el error:

```cpp
pSecurity->setAuthenticationMode(ESP_LE_AUTH_REQ_SC_MITM_BOND);
```
por: 
```cpp
pSecurity->setAuthenticationMode(ESP_LE_AUTH_BOND);
```

--> URL de la libreria: https://github.com/T-vK/ESP32-BLE-Keyboard
