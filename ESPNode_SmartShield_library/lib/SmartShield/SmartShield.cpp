
/*
 CURSO BASICO IOT DE LA COMUNIDAD SPAINLABS.COM
 Libreria para la placa de expansión Smart Sensors Shield
 Compatible con las versiones del modulo ESP8266: esp-07/12/12E.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabsIoT2018-Nodo-ESP8266-Smart-Sensors-Shield
 Firmware para el hardware desarrollado en el curso SpainLabsIoT2018.
 Enlace: https://www.spainlabs.com/foros/tema-SpainLabs-con-el-IoT-para-tod-s

 Esta libreria realiza lo siguiente:
 Gestión de la placa de expansión Smart Sensors Shield.

 Diseño: Grafisoft.
 Fecha: 21/6/2018.
 Version: 1 revA.
*/

#include "SmartShield.h"

//Colocar constates etc, etc aqui.

//! class constructor
SmartShield::SmartShield()
{

  #if DEBUG_SS > 2
    Serial.begin(115200);
    Serial.println("Configuracion shield");
  #endif

Wire.begin(); //Inicializamos el bus I2C.
Set(); //Configuramos la shield.
}

// Private Methods /////////////////////////////////////////////////////////////


// Public Methods //////////////////////////////////////////////////////////////

//Funcion para comunicarse con el MUX I2C y configurarlo.
//Parametro de entrada: Canal del MUX que queremos usar.
void SmartShield::tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
  }

//Configuración de la shield.
void SmartShield::Set()
{
  #if DEBUG_SS > 2
    //Serial.begin(115200);
    Serial.print("Configuracion shield...");
  #endif
  tcaselect(6);
  delay(500);
  Wire.begin();
  //delay(100);
  mcp.pinMode(Power_Board_3v3, OUTPUT);
  mcp.digitalWrite(Power_Board_3v3, LOW);
  delay(100);
  mcp.pinMode(SocketA_PWR, OUTPUT);
  mcp.digitalWrite(SocketA_PWR, HIGH);
  mcp.pinMode(SocketB_PWR, OUTPUT);
  mcp.digitalWrite(SocketB_PWR, HIGH);
  mcp.pinMode(Power_5v0, OUTPUT);
  mcp.digitalWrite(Power_5v0, LOW);

  #if DEBUG_SS > 2
    //Serial.begin(115200);
    Serial.println("OK");
  #endif

}
//Funcion para el control de la alimentación ON en los diferentes sockets
void SmartShield::ON(uint8_t socket_sensor)
{
  //Seleccion del canal 6 en el MUX del I2C.
  tcaselect(6);
  delay(500);

  switch(socket_sensor)
  {
    //Aliemntacion ON en socketA.
    case SOCKET_A:
      #if DEBUG_SS > 2
        Serial.println("Socket A ON");
      #endif
      //tcaselect(6);
      //delay(500);
      mcp.digitalWrite(SocketA_PWR, LOW);
      break;

      //Aliemntacion ON en socketB.
      case SOCKET_B:
        #if DEBUG_SS > 2
          Serial.println("Socket B ON");
        #endif
        //tcaselect(6);
        //delay(500);
        mcp.digitalWrite(SocketB_PWR, LOW);
        break;

    //Aliemntacion ON en socketH.
    case SOCKET_H:
      #if DEBUG_SS > 2
        Serial.println("Socket B ON");
      #endif
      //tcaselect(6);
      //delay(500);
      mcp.digitalWrite(Power_5v0, HIGH);
      break;

    //Aliemntacion ON en Board.
    case BOARD:
      #if DEBUG_SS > 2
        Serial.println("Board ON");
      #endif
      //tcaselect(6);
      //delay(500);
      //Aliemntacion ON en regulador general.
      mcp.digitalWrite(Power_Board_3v3, HIGH);
      delay(100);
      break;
  }
}

//Funcion para el control de la alimentación a OFF en los sockets
void SmartShield::OFF(uint8_t socket_sensor)
{
  //Seleccion del canal 6 en el MUX del I2C.
  tcaselect(6);
  delay(500);

  switch(socket_sensor)
  {
    //Aliemntacion ON en socketA.
    case SOCKET_A:
      #if DEBUG_SS > 2
        Serial.println("Socket A OFF");
      #endif
      //tcaselect(6);
      //delay(500);
      mcp.digitalWrite(SocketA_PWR, HIGH);
      break;

      //Aliemntacion OFF en socketB.
      case SOCKET_B:
        #if DEBUG_SS > 2
          Serial.println("Socket B OFF");
        #endif
        //tcaselect(6);
        //delay(500);
        mcp.digitalWrite(SocketB_PWR, HIGH);
        break;

    //Aliemntacion ON en socketH.
    case SOCKET_H:
      #if DEBUG_SS > 2
        Serial.println("Socket B OFF");
      #endif
      //tcaselect(6);
      //delay(500);
      mcp.digitalWrite(Power_5v0, LOW);
      break;

    //Aliemntacion ON en Board.
    case BOARD:
      #if DEBUG_SS > 2
        Serial.println("Board OFF");
      #endif
      //tcaselect(6);
      //delay(500);
      //Aliemntacion ON en regulador general.
      mcp.digitalWrite(Power_Board_3v3, LOW);
      delay(100);
      break;
  }

}
//Bloque para testeo.
void SmartShield::Test()
{
  tcaselect(6);
  delay(500);
  mcp.begin();
  mcp.pinMode(7, OUTPUT);
  mcp.pinMode(2, OUTPUT);
  mcp.digitalWrite(7, HIGH);
  mcp.digitalWrite(2, LOW);
  delay(5000);
  mcp.digitalWrite(7, LOW);
  mcp.digitalWrite(2, HIGH);
  delay(5000);

}
