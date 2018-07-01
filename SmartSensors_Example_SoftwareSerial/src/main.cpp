/*
 CURSO BASICO IOT DE LA COMUNIDAD SPAINLABS.COM
 Ejemplo basico para el hardware: ESP8266 IoT Nodo v1rA + Smart Sensors Shield
 Compatible con las versiones del modulo ESP8266: esp-07/12/12E.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabsIoT2018-Nodo-ESP8266-Smart-Sensors-Shield
 Firmware para el hardware desarrollado en el curso SpainLabsIoT2018.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabs-con-el-IoT-para-tod-s

 Este software realiza de forma esquematica lo siguiente:
 Ejemplo donde se muestra como configurar el UART por Software
 para usarlo en el Socket G. Este Socket al igual que el H, son socket_sensor
 para ser usados con comunicación UART.

 En la shield podemos habilitar, soldando resistencias valor 0 ohm en
 la cara posterior donde se especifica SW_Uart_EN o HW_Uart_EN. De esta
 forma configuramos la shield para usar comunicacion UART nativa o la
 opción de simularla. De esta forma tendriamos el puerto UART nativo
 libre para otras cosas.

 Diseño: Grafisoft.
 Fecha: 1/7/2018.
 Version: 1 revA.
*/


#include <Arduino.h>
#include "SmartShield.h"

 //SoftwareSerial swSer(Rx=, Tx=, false, buffer=256);
 SoftwareSerial  swSer(15, 13, false, 256);

SmartShield Shield;

void setup()
{
  delay(5000);
  //Configuaración UART nativo.
  Serial.begin(115200);
  //Configuración UART simulado. Solo disponible en Socket G y H.
  swSer.begin(19200);

  Serial.println("\nSmart Sensors Shield - Features Examples");
  Serial.println("\nSocket G - UART por Software - example");
  Shield.Set();
}

void loop()
{

  Serial.println("\nInicio del Loop!");
  Shield.ON(BOARD);
  //Alimentamos el Socket G y habilitamos la comnunicación.
  //La comunuicación pasa por un aislador, que la Libreria
  //habilita para que este disponible en el conector.
  Shield.ON(SOCKET_G);
  delay(1000);
  //Mensaje que enviamos por el Socket G.
  //Este mensaje no se imprimira en la consola por el conector de programación.
  swSer.println("Probando Software Serial");
  Shield.OFF(SOCKET_G);
  delay(500);
  Shield.OFF(BOARD);
  delay(2000);

}
