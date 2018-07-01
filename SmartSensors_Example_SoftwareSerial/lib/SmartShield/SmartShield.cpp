
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
 Version: 2 revA.
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
  mcp.pinMode(SocketF_PWR, OUTPUT);
  mcp.digitalWrite(SocketF_PWR, HIGH);
  mcp.pinMode(SocketG_PWR, OUTPUT);
  mcp.digitalWrite(SocketG_PWR, HIGH);
  mcp.pinMode(SocketG_UART_EN, OUTPUT);
  mcp.digitalWrite(SocketG_UART_EN, LOW);
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

    //Aliemntacion ON en socketF.
    case SOCKET_F:
      #if DEBUG_SS > 2
        Serial.println("Socket F ON");
      #endif
      //tcaselect(6);
      //delay(500);
      mcp.digitalWrite(SocketF_PWR, LOW);
      break;

      case SOCKET_G:
        #if DEBUG_SS > 2
          Serial.println("Socket G ON");
        #endif
        //tcaselect(6);
        //delay(500);
        mcp.digitalWrite(SocketG_PWR, LOW);
        mcp.digitalWrite(SocketG_UART_EN, HIGH);
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

        //Aliemntacion OFF en socketF.
        case SOCKET_F:
          #if DEBUG_SS > 2
            Serial.println("Socket F OFF");
          #endif
          //tcaselect(6);
          //delay(500);
          mcp.digitalWrite(SocketF_PWR, HIGH);
          break;

    //Aliemntacion OFF en socketG.
    //Es necesario configurar el SoftwarSerial en el código.
    case SOCKET_G:
        #if DEBUG_SS > 2
          Serial.println("Socket G OFF");
        #endif
        //tcaselect(6);
        //delay(500);
        mcp.digitalWrite(SocketG_UART_EN, LOW);
        mcp.digitalWrite(SocketG_PWR, HIGH);

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


//Funciona para una lectura unica del ADC a 18bits y ganancia 1.
long SmartShield::OneADCRead18bits()
{
  //Alimentacion en Socket F ON.
  ON(SOCKET_F);
  delay(500);
  //I2CMUX set canal del ADC.
  tcaselect(5);
  delay(100);

  Wire.begin(); //0x68 - No seria necesario.
  //MCP342x::generalCallReset();
  delay(1); // MC342x needs 300us to settle

  #if DEBUG_SS > 2
  // Check device present
    Wire.requestFrom(addressADC, (uint8_t)1);
    if (!Wire.available()) {
      Serial.print("No device found at address ");
      Serial.println(addressADC, HEX);
      while (1)
        ;
    }
    #endif

    // Configuration settings
    //MCP342x::Config config(MCP342x::channel1, MCP342x::oneShot,
  	//	       MCP342x::resolution18, MCP342x::gain1);

    // Configuration/status read back from the ADC
    MCP342x::Config status;

    long value = 0;
    //Lectura del ADC.
    uint8_t err = adc.convertAndRead(MCP342x::channel1, MCP342x::oneShot,
  				   MCP342x::resolution18, MCP342x::gain1,
  				   1000000, value, status);
    #if DEBUG_SS > 2
    if (err) {
      Serial.print("Convert error: ");
      Serial.println(err);
    }
    else {
      Serial.print("Value: ");
      Serial.println(value);
    }
    #endif
    //Alimentacion en Socket F OFF.
    OFF(SOCKET_F);

    delay(1000);
    return(value);
}
