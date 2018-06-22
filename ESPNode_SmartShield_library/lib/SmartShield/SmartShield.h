#ifndef SmartShield_h
#define SmartShield_h

/*******************************************************************************
 * Includes
 ******************************************************************************/
 #include <Arduino.h>
 #include "Wire.h"

 #include <Adafruit_MCP23017.h>

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
#define Power_5v0 8       //MCP23017, GPB0, Pin 8.
#define SocketA_PWR 2     //MCP23017, GPA2, Pin 2.
#define SocketB_PWR 3     //MCP23017, GPA3, Pin 3.

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

  private:

  Adafruit_MCP23017 mcp;		// object to manage internal circuitry

  //Variables


};

#endif
