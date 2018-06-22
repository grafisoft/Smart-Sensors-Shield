/*
 CURSO BASICO IOT DE LA COMUNIDAD SPAINLABS.COM
 Ejemplo basico para la lectura del sensor BME280 usando la placa de
 expansión Smart Sensors Shield.
 Compatible con las versiones del modulo ESP8266: esp-07/12/12E.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabsIoT2018-Nodo-ESP8266-Smart-Sensors-Shield
 Firmware para el hardware desarrollado en el curso SpainLabsIoT2018.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabs-con-el-IoT-para-tod-s

 Este ejemplo realiza lo siguiente:
  - Gestión de la placa de expansión Smart Sensors Shield.
  - Lee el sensor BME280. Envia los datos al monitor serie (115200).
  - Alimenta el Socket B, durante 1s, donde tenemos colocado un led.
  - Apagado de todos los socket y de la shield.

 Diseño: Grafisoft.
 Fecha: 21/6/2018.
 Version: 1 revA.
*/
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "SmartShield.h"

Adafruit_BME280 bme; // Sensor BME280 I2C.
//#define BME280_ADDRESS  0x76  // Otra posible direccion I2C del sensor BME.
SmartShield Shield; //SmartSensorShield library.
#define SEALEVELPRESSURE_HPA (1034.9)

void setup() {
  Serial.begin(115200);
  Serial.println("\nSmart Sensors Shield - API Development");
  Serial.println("\nSmart Sensors Shield - BME280 example");
  //Configuración de la shield.
  Shield.Set();

}

void loop() {

  Shield.ON(BOARD);
  Shield.ON(SOCKET_A);
  delay(500);

  //Configuramos el I2CMUX en el canal 7 (SD7/SC7).
  Shield.tcaselect(7);
  delay(500);

  //Inicializamos el sensor bme280.
  bool status;
  status = bme.begin(0x77);
  if (!status) {
      Serial.println("Could not find a valid BME280 sensor, check wiring!");
      while (1);
  }
  delay(100); // let sensor boot up

  //Lectura del sensor y envio de datos al monitor serie.
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  Serial.print("Pressure = ");

  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.println();

  //Alimentamos el Socket B durante 1 segundo.
  Shield.ON(SOCKET_B);
  delay(1000);
  //Apagamos todo
  Shield.OFF(SOCKET_B);
  Shield.OFF(SOCKET_A);
  Shield.OFF(BOARD);
  delay(1000);

  //ESP.deepSleep(15000000, WAKE_RF_DEFAULT);
}
