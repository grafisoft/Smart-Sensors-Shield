#ifndef SmartShield_h
#define SmartShield_h

/*******************************************************************************
 * Includes
 ******************************************************************************/
 #include <Arduino.h>
 #include "Wire.h"

 #include <Adafruit_MCP23017.h> //Libreria para el I/O Expansor.
 #include <MCP342x.h> //Libreria para el ADC de 18Bits. MCP3421.
 #include <SoftwareSerial.h>

 /*******************************************************************************
 * Definitions
 ******************************************************************************/
 /*!
 * \def DEBUG_SS
 * \brief Possible values:
 * 	0: No debug mode enabled
 * 	1: debug mode enabled for error output messages
 * 	2: debug mode enabled for both error and ok messages
 */
#define DEBUG_SS 		3

//Definiciones genericas.
#define TCAADDR 0x70      //I2C Adress for I2CMUX.

#define Power_Board_3v3 7 //MCP23017, GPA7, Pin 7.
#define Power_5v0 8       //MCP23017, GPB0, Pin 8.Socket H.
#define SocketA_PWR 2     //MCP23017, GPA2, Pin 2.
#define SocketB_PWR 3     //MCP23017, GPA3, Pin 3.
#define SocketF_PWR 14     //MCP23017, GPB6, Pin 7.
#define SocketG_UART_EN 12     //MCP23017, GPB4, Pin 5.
#define SocketG_PWR 13     //MCP23017, GPB5, Pin 6.

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

/*******************************************************************************
 * Class
 ******************************************************************************/

 /*!
 * \class SmartShield
 * \brief class for Smart Sensor Shield
 */
class SmartShield
{
 	public:
    //Variables

	 	//! Constructor
	 	SmartShield();

    void tcaselect(uint8_t i);
    void Set();
    void ON(uint8_t socket_sensor);
    void OFF(uint8_t socket_sensor);
    void Test();
    long OneADCRead18bits();
    
    // 0x68 is the default address for all MCP342x devices
    uint8_t addressADC = 0x68;  //0x68 default Address. 0x68 to 0x6F.
    MCP342x adc;

  private:

  Adafruit_MCP23017 mcp;		// object to manage internal circuitry

  //Variables


};

#endif
