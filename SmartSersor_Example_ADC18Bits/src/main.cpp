/*
 CURSO BASICO IOT DE LA COMUNIDAD SPAINLABS.COM
 Ejemplo basico para el hardware: ESP8266 IoT Nodo v1rA + Smart Sensors Shield
 Compatible con las versiones del modulo ESP8266: esp-07/12/12E.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabsIoT2018-Nodo-ESP8266-Smart-Sensors-Shield
 Firmware para el hardware desarrollado en el curso SpainLabsIoT2018.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabs-con-el-IoT-para-tod-s

 Este software realiza de forma esquematica lo siguiente:
 Usando la placa de expansión Smart Sensors Shield, el ejemplo realiza una
 lectura del ADC en configuración 18Bits y ganancia 1. La propia función ya
 realiza la gestion de los diferentes componentes de la Sensor Shield.

 El modo DEBUG_SS se encuentra activado en la libreria para obtener mas
 datos en la ejecución del ejemplo.

 Diseño: Grafisoft.
 Fecha: 28/6/2018.
 Version: 1 revA.
*/

#include <Arduino.h>
#include "SmartShield.h"

SmartShield Shield; //Libreria para la gestion de la Shield.

void setup()
{
  Serial.begin(115200);
  Serial.println("\nSmart Sensors Shield - Features Examples");
  Serial.println("\nMCP3421 18Bits ADC example");
  //Configuramos la shield.
  Shield.Set();

}

void loop()
{
  //Encendemos la Shield.
  Shield.ON(BOARD);
  delay(500);
  Serial.println("\nStart ADC - 18Bits & Gain 1");
  long valuefun = Shield.OneADCRead18bits();
  Serial.print("Value ADC 18Bits: ");
  Serial.println(valuefun);

  //Apagamos la Shield.
  Shield.OFF(BOARD);
  delay(2000);

}
