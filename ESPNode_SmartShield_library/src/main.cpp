/*
 CURSO BASICO IOT DE LA COMUNIDAD SPAINLABS.COM
 Ejemplo basico para el hardware: ESP8266 IoT Nodo v1rA + Smart Sensors Shield
 Compatible con las versiones del modulo ESP8266: esp-07/12/12E.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabsIoT2018-Nodo-ESP8266-Smart-Sensors-Shield
 Firmware para el hardware desarrollado en el curso SpainLabsIoT2018.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabs-con-el-IoT-para-tod-s

 Este software realiza de forma esquematica lo siguiente:
 Usando la placa de expansión Smart Sensors Shield, el ejemplo va activando
 la alimentación de los diferentes sockets. Posteriormente, la apaga y se
 vuelve a repetir el proceso.

 Diseño: Grafisoft.
 Fecha: 21/6/2018.
 Version: 1 revA.
*/


#include <Arduino.h>
#include "SmartShield.h"

/**
 * CODIGO PARA TESTEAR LOS DIFERNTES BLOQUES DE LA SHIELD.
 */

// standard Arduino setup()

SmartShield Shield;
void setup()
{
  delay(5000);
  Serial.begin(115200);
  Serial.println("\nSmart Sensors Shield - API Development");
  Shield.Set();
}

void loop()
{
  delay(2000);

  Serial.println("\nInicio del Loop!");
  Shield.ON(BOARD);
  Shield.ON(SOCKET_A);
  delay(500);
  Shield.ON(SOCKET_B);
  delay(1000);
  Shield.OFF(SOCKET_A);
  delay(500);
  Shield.OFF(SOCKET_B);
  delay(500);
  Shield.OFF(BOARD);
  delay(2000);







  //mcp.digitalWrite(0b00011000, HIGH);
  //mcp.digitalWrite(6, HIGH);
  //mcp.digitalWrite(9, HIGH);
  //mcp.digitalWrite(24, HIGH);
  //mcp.digitalWrite(25, HIGH);
/*
  tcaselect(6);
  delay(500);
//  mcp.begin();      // use default address 0 - 0x20 I2C address
  Wire.begin(0x20);
  //Aliemntacion ON en socketA.
  mcp.pinMode(7, OUTPUT);
  mcp.pinMode(2, OUTPUT);
  mcp.digitalWrite(7, HIGH);
  mcp.digitalWrite(2, LOW);

  //uint16_t gpio2 = 0;
  //Serial.print("GPIO: ");
  //gpio2 = mcp.readGPIOAB();
  //Serial.println(gpio2, BIN);

  delay(2000);
  Serial.println("\nMCP23017 P28 OFF!");
//  mcp.digitalWrite(0b00011000, LOW);
//  mcp.digitalWrite(6, LOW);
//  mcp.digitalWrite(9, LOW);
//  mcp.digitalWrite(24, LOW);
//  mcp.digitalWrite(25, LOW);

mcp.digitalWrite(7, LOW);
mcp.digitalWrite(2, HIGH);

//  gpio2 = 0;
//  Serial.print("GPIO: ");
//  gpio2 = mcp.readGPIOAB();
//  Serial.println(gpio2, BIN);
  //Serial.println(gpio, byte);
delay(2000);

*/

}
