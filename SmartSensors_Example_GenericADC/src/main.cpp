/*
 CURSO BASICO IOT DE LA COMUNIDAD SPAINLABS.COM
 Ejemplo basico para el hardware: ESP8266 IoT Nodo v1rA + Smart Sensors Shield
 Compatible con las versiones del modulo ESP8266: esp-07/12/12E.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabsIoT2018-Nodo-ESP8266-Smart-Sensors-Shield
 Firmware para el hardware desarrollado en el curso SpainLabsIoT2018.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabs-con-el-IoT-para-tod-s

 Este software realiza de forma esquematica lo siguiente:
 Usando la placa de expansión Smart Sensors Shield, el ejemplo muestra
 como ir gestionando la Sensors Shield para realizar una lectura con el ADC.
 En este caso, el ADC se configura en el ejemplo, con lo que se puede variar
 su configuración segun las necesidades del usuario.

 Diseño: Grafisoft.
 Fecha: 21/6/2018.
 Version: 1 revA.
*/


#include <Arduino.h>
#include "SmartShield.h"

SmartShield Shield;

void setup()
{
  delay(5000);
  Serial.begin(115200);
  Serial.println("\nSmart Sensors Shield - Features Examples");
  Serial.println("\nMCP3421 Generic ADC example");
  //Configuramos la shield.
  Shield.Set();


}

void loop()
{
  Shield.ON(BOARD);
  delay(500);

  Shield.ON(SOCKET_F);
  delay(500);
  Shield.tcaselect(5);
  delay(100);

  Wire.begin(); //0x68
  delay(1); // MC342x needs 300us to settle

  // Check device present
    Wire.requestFrom(Shield.addressADC, (uint8_t)1);
    if (!Wire.available()) {
      Serial.print("No device found at address ");
      Serial.println(Shield.addressADC, HEX);
      while (1)
        ;
    }

  // Configuration/status read back from the ADC
  MCP342x::Config status;

  long value = 0;
  Serial.println("\nStart ADC!");
  uint8_t err = Shield.adc.convertAndRead(MCP342x::channel1, MCP342x::oneShot,
				   MCP342x::resolution18, MCP342x::gain1,
				   1000000, value, status);
  if (err) {
    Serial.print("Convert error: ");
    Serial.println(err);
  }
  else {
    Serial.print("Value ADC: ");
    Serial.println(value);
  }

  Shield.OFF(SOCKET_F);
  Shield.OFF(BOARD);
  delay(1000);

}
