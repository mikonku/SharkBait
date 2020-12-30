void checkFunc(){
  SIM900.println("AT");
  delay(200);

  ShowSerialData();
  delay(10);  
}


void checkBat(){
  /* DEBUG  */// Serial.println("==> AT+CBC");
  SIM900.println("AT+CBC");
  delay(200);
 
  /* DEBUG */ ShowSerialData();   // JANGAN NYALAKAN SAAT Serial.find masih ON
  delay(10);        // Avoiding debounce
}


void signalQuality(){
  /* DEBUG  */// Serial.println("==> AT+CSQ");
  SIM900.println("AT+CSQ");
  delay(200);

  /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
  delay(10);    // Avoiding debounce
}


void ConfigReg(){
  /* DEBUG  */// Serial.println("==> AT+CREG");
  SIM900.println("AT+CREG=1");
  delay(200);

  /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
  delay(10);    // Avoiding debounce
}

// Configure to GPRS Attach
void ConfigAttGPRS(){
  /* DEBUG  */// Serial.println("==> AT+CGATT");
  SIM900.println("AT+CGATT=1");
  delay(200);

  /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
}

// Configure Bearer Profile
void ConfigProfilOne(){
  /* DEBUG  */// Serial.println("==> AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  SIM900.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(200);
  ShowSerialData(); 
 
  SIM900.println("AT+SAPBR=3,1,\"APN\",\"Telkomsel\"");
  // SIM900.println("AT+SAPBR=3,1,\"USER\",\"wap\"");
  // SIM900.println("AT+SAPBR=3,1,\"PWD\",\"wap123\"");
  delay(200);
  /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
  delay(10);    // Avoiding debounce
}


void openGPRS(){
  /* DEBUG  */// Serial.println("==> AT+SAPBR=2,1");
  SIM900.println("AT+SAPBR=2,1"); /* Query the GPRS context */
  
  /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
  delay(10);    // Avoiding debounce
}


// Init HTTP or HTTPS Service
void InitRequest(){
  /* DEBUG  */// Serial.println("==> AT+HTTPINIT");
  SIM900.println("AT+HTTPINIT");
  delay(200);

  /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
  delay(10);    // Avoiding debounce
}

// CID Request
void CID(){
  /* DEBUG  */// Serial.println("==> AT+HTTPPARA=\"CID\",1");
  SIM900.println("AT+HTTPPARA=\"CID\",1");
  delay(200);

  /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
  delay(10);    // Avoiding debounce
}

// URL request
void UrlReq(){
  // Inputkan URL Back End, hit to AWS server ^-^....(yg AWS ini untuk POST DATA)
      /* DEBUG  */// Serial.println("==> AT+HTTPPARA=\"URL\",\"http://54.251.164.253:4000/dataAqm\"");
      SIM900.println("AT+HTTPPARA=\"URL\",\"3.0.87.5:4000/dataAqm\"");
      delay(1000);

      /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
      delay(10);    // Avoiding debounce
}

void httpdata(String panjang = "12", String data ="{\"NO2\":1000}" ){
      /* DEBUG  */// Serial.println("==> AT+HTTPDATA=" + lenPackage + "," + "15000");
     String a = "AT+HTTPDATA="+ panjang + ",10000"; 
     SIM900.println(a);
     delay(1000); 
     ShowSerialData();
     SIM900.println(data); //
     delay(10000);
      /* DEBUG */ ShowSerialData();
      
      // Seding package data
//          SIM900.println(package);
//          /* DEBUG */Serial.println(package);
//          /* DEBUG *///SIM900.println("{\"sampling_time\":\"2019-08-10T12-04-01Z\",\"Pm10\":0.10,\"CO\" : 0,\"NO2\" : 0,\"S02\" : 0,\"O3\" : 0,\"temp_ambien\":38.00,\"rh_ambien\":31.00,\"kec_angin\" : 4.75,\"mata_angin\" : \"barat\",\"batt_pwr\":1.83,\"deviceID\" : 1}");
        delay(20000);    // best recomm "dont less then timeout HTTPDATA" if you want get best respone (empirical, may be it'll diffent wiyh you)
//          delay(15000);
    }

//    void POST(){
//      
//      //POST package
//      /* DEBUG  */// Serial.println("==> AT+HTTPACTION=1");
//          SIM900.println("AT+HTTPACTION=1");
//          delay(20000);   // Should long, depend on how large your data signal quality and timeout, it impact to time respone
//
//      /* DEBUG  */  ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
//
//
//      delay(3000);    // delay before TERMINATE
//    }

// READ RESPONE HTTP
    void readResp(){
      /* DEBUG  */// Serial.println("==> AT+HTTPREAD");
      SIM900.println("AT+HTTPREAD");
      delay(5000);
      /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
      delay(10);    // Avoiding debounce
    }

// TERMINATE  HTTP Services
    void TERMhttp(){
      /* DEBUG  */// Serial.println("==> AT+HTTPTERM");
      SIM900.println("AT+HTTPTERM");
      delay(200);

      /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
      delay(10);    // Avoiding debounce
    }

// Disconnect GPRS
    void DiscGPRS(){
      /* DEBUG  */// Serial.println("==> AT+SAPBR=0,1");
      SIM900.println("AT+SAPBR=0,1");
      delay(200);

      /* DEBUG  */ ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON
      delay(10);    // Avoiding debounce
    }



String POST(){
  boolean b;

  SIM900.println("AT+HTTPACTION=1");
          delay(200);  


  if(SIM900.available()>0){
    b = SIM900.find("1,201,33");
  }


  if(b == true){
            Serial.println("1,201,33");
            return "1,202,33";
          }else{
            Serial.println("\n Waiting... \n");
            return "Error";
          }
}

String checkCpin(){
  boolean b;

  SIM900.println("AT+CPIN?");
  delay(200);


  if(SIM900.available()>0){
    b = SIM900.find("READY");
  }


  if(b == true){
            Serial.println("\nSIMCom : READY");          // SIMCom ready to use
            Serial.println("\nOK \n");
            return "READY";
          }else{
            Serial.println("\nSIMCom : NOT READY");      // SIMCom not ready to use
            Serial.println("\nERROR \n");
            Serial.println("\nPlease restart or Check Your SIMCOM \n");
            return "Error";
          }
}

String checkProvider(){
  boolean b;

  SIM900.println("AT+COPS?");
  delay(200);

  if(SIM900.available()>0){
     b = SIM900.find("TELKOMSEL");
  }

  if(b == true){
            Serial.println("\nProvider : TELKOMSEL");      // Provider founnd
            Serial.println("\nOK \n");
            return "TELKOMSEL";
          }else{
            Serial.println("\nProvider : UNKNOWN");    // Provider is not find
            Serial.println("\nError \n");
            return "UNKNOWN";
          }
          delay(10);    // Avoiding debounce

}
String ConnGPRS(){
      boolean b;
      /* DEBUG  */// Serial.println("==> AT+SAPBR=1,1");
      SIM900.println("AT+SAPBR=1,1");
      delay(200);

      /* DEBUG  */// ShowSerialData();  // JANGAN NYALAKAN SAAT Serial.find masih ON

      // Check weather are Provider Services or not
          if(SIM900.available()>0){
             b = SIM900.find("OK");
          }

          if(b == true){
              Serial.println("\nGPRS : OK");      // Provider founnd
              Serial.println("\nOK \n");
              return "OK";
            }else{
              Serial.println("\nGPRS : ERROR");      // Provider founnd
              Serial.println("\nERROR \n");
              return "ERROR";
            }
          
      delay(10);    // Avoiding debounce
    }

void initializeNetwork(){
  checkFunc();
  int i=0;
  while(checkCpin() != Status_simCom && i<5){
      if(checkCpin() ==Status_simCom){
        i=10;
        delay(10);
      }
      else{
              i++;
              /* DEBUG */ Serial.println("Re-Check CPIN . . .");
              Serial.println(i);
              delay(2000);
              
      }
            }
  checkBat();
  // Check Provider
        i=0;
            while(checkProvider() != Provider && i<5){
                if(checkProvider() == Provider ){
                    i=10;
                    delay(10);
    
                }
            else{
              i++;   
              Serial.println(i);
              /* DEBUG */ Serial.println("Searching . . . ");
              delay(1000);
            }

            }
        // Check Signal Quality
            signalQuality();
}

void GPRSactivated(){
      // Configure to return unsolicited result
          ConfigReg();

      // Configure to GPRS Attach
          ConfigAttGPRS();
      
      // Configure Bearer Profile
          ConfigProfilOne();
          
      // Diconnect GPRS first, before activate
          DiscGPRS();
      
      //Connect to GPRS 
         //SIM900.println(ConnGPRS());
         int i = 0 ; 
         while(ConnGPRS()!="OK" && i < 5){
          if(checkProvider() == Provider ){
                    i=10;
                    delay(10);
          }
          else{
              i++;   
              Serial.println(i);
           SIM900.println(ConnGPRS());
           Serial.println("Re-connecting to GPRS . . .");
           delay(100);
         }
         }
         
      // OPEN to GPRS
          openGPRS();

    }


// Sending or POST Data package
    void POSTdata(String a, String b){
      // Init HTTP or HTTPS Service
          InitRequest();

      // CID Request
          CID();

      // URL request
          UrlReq();

      // Defining size data package
          httpdata(a, b);

      // POST session
           int i = 0 ; 
           POST();
         while(POST()!= ActionResp && i < 5){
          if(POST() == ActionResp ){
                    i=10;
                    delay(10);
          }
          else{
              i++;   
              Serial.println(i);
           SIM900.println(POST());
           Serial.println("Re-action . . .");
           delay(100);
          
          }
         }
         readResp();
         delay(2000);
    

      // TERMINATE  HTTP Services
          TERMhttp();

      // Disconnect GPRS
          DiscGPRS();
    }


void ShowSerialData()
{
  while(SIM900.available()!=0)  /* If data is available on serial port */
  Serial.write(char (SIM900.read())); /* Print character received on to the serial monitor */
}
