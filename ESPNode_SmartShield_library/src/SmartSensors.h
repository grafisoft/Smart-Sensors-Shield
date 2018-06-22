//API PARA LA SHIELD "SMART SENSORS SHIELD"

// Comentarios para hacer la API.
//  GPIOA0 = PIN 0 -> ES DECIR, EL NUMERO AL QUE CORRESPONDE SI LO QUEREMOS USAR.
//  GPIOA7 = PIN 7

//  GPIOB0 = PIN 8
//  GPIOB7 = PIN 16
#include <Arduino.h>
#include "Wire.h"

#include <Adafruit_MCP23017.h>

#define TCAADDR 0x70      //I2C Adress for I2CMUX.

#define Power_Board_3v3 7 //MCP23017, GPA7, Pin 7.
#define Power_5v0 8       //MCP23017, GPB0, Pin 8.
#define SocketA_PWR 2     //MCP23017, GPA2, Pin 2.

// Definicion de los sockets.
#define SOCKET_A 1
#define SOCKET_B 2
#define SOCKET_C 3
#define SOCKET_D 4
#define SOCKET_E 5
#define SOCKET_F 6
#define SOCKET_G 7
#define SOCKET_H 8
#define SOCKET_I 9
#define SOCKET_J 10
#define BOARD    11

Adafruit_MCP23017 mcp;

//Funcion para comunicarse con el MUX I2C y configurarlo.
void tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
  }

// Funcion para conectar la alimentacion a los sockets
void ON(uint8_t socket_sensor)
{
  switch(socket_sensor)
  {
    case SOCKET_A:
      tcaselect(6);
      delay(500);
      //mcp.begin();      // use default address 0 - 0x20 I2C address
      //Aliemntacion ON en socketA.
      //mcp.pinMode(SocketA_PWR, OUTPUT);
      mcp.digitalWrite(SocketA_PWR, LOW);
      break;

    case SOCKET_H:
      tcaselect(6);
      delay(500);
      //mcp.begin();      // use default address 0 - 0x20 I2C address
      //Aliemntacion ON en socketA.
      //mcp.pinMode(Power_5v0, OUTPUT);
      mcp.digitalWrite(Power_5v0, HIGH);
      break;

    case BOARD:
      tcaselect(6);
      delay(500);
    //  mcp.begin();      // use default address 0 - 0x20 I2C address
      //Aliemntacion ON en regulador general.
      mcp.pinMode(Power_Board_3v3, OUTPUT);
      mcp.pinMode(SOCKET_A, OUTPUT);
      mcp.pinMode(Power_5v0, OUTPUT);
      delay(100);
      mcp.digitalWrite(SOCKET_A, HIGH);
      mcp.digitalWrite(Power_Board_3v3, HIGH);
      mcp.digitalWrite(Power_5v0, LOW);
      break;
  }
}

// Funcion para desconectar la alimentacion a los sockets
void OFF(uint8_t socket_sensor)
{
  switch(socket_sensor)
  {
    case SOCKET_A:
      tcaselect(6);
      delay(500);
      //mcp.begin();      // use default address 0 - 0x20 I2C address
      //Aliemntacion ON en socketA.
      //mcp.pinMode(SocketA_PWR, OUTPUT);
      mcp.digitalWrite(SocketA_PWR, HIGH);
      break;

    case SOCKET_H:
      tcaselect(6);
      delay(500);
      //mcp.begin();      // use default address 0 - 0x20 I2C address
      //Aliemntacion ON en socketA.
      //mcp.pinMode(Power_5v0, OUTPUT);
      mcp.digitalWrite(Power_5v0, LOW);
      break;

    case BOARD:
      tcaselect(6);
      delay(500);
      //mcp.begin();      // use default address 0 - 0x20 I2C address
      //Aliemntacion OFF en Regulador general.
      //mcp.pinMode(Power_Board_3v3, OUTPUT);
      //mcp.pinMode(SOCKET_A, OUTPUT);
      //mcp.pinMode(Power_5v0, OUTPUT);
      delay(100);
      mcp.digitalWrite(SOCKET_A, HIGH);
      mcp.digitalWrite(Power_Board_3v3, LOW);
      mcp.digitalWrite(Power_5v0, LOW);
      break;
  }
}
