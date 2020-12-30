#include <SoftwareSerial.h>

SoftwareSerial SIM900(2,3); // RX | TX
// Connect the SIM900 TX to Arduino pin 2 RX. 
// Connect the SIM900 RX to Arduino pin 3 TX. 
//int i;

// Global initialization
    #define   deviceID          01           // deviceID its a dedicated number only for the device, DON'T change it! Serial Number or Lot number
    #define   Provider     "TELKOMSEL"       // You can change another Provider as "XL", "INDOSAT" etc depend your card
    #define   interval        60000         // Should be match with weather and sensor ISPU sampling time \
                                                The shortest interval which can be applied is 300 second
    String Status_simCom = "READY";          // Status SIMCOM "Ready or Not Ready" to communicate with mainBoard 2560
    String Status_GPRS = "OK";               // GPRS connection status
    String Respond = "{\"message\":\"Succes create Data\"}";
    String ActionResp = "1,201,33";

void setup()
{
  SIM900.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  initializeNetwork();
  delay(500);
  GPRSactivated();
  delay(500);

//------------------------------------dummies data------------------------------------//

   
  long randNumber=random(1000,1200);
  //  Serial.println(randNumber);
  delay(100);
  String a = String(randNumber);
  //  Serial.println(a);
  delay(100);
  String package = "{\"NO2\":" + a +"}";

//-----------------------------------------------------------------------------------//


//post data
  POSTdata(String(package.length()), package);
  
}


void loop()
{
  
}
