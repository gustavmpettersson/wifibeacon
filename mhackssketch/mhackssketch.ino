#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

//Alarm page: https://raw.githubusercontent.com/xyllian/wifibeacon/master/alarmpage.html

#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel leds = Adafruit_NeoPixel(2, 15, NEO_GRB + NEO_KHZ800);

int state = 0;
unsigned long tlast = millis();
unsigned long tcheck = millis();
int blinktime = 200;
int ii = 0;
int button = 0;
int buzzer = 2;
int nwmode; //mode 0 wifi mode 1 serial
int active = 1;

const char* ssid = "MhacksGuest";
const char* pwd = "mhackshype";
const char* host = "35.0.121.215:3000";
const char* path = "/index.html";


void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
  leds.begin();
  leds.setBrightness(10); //Increase to 255 for real
  leds.show();
  digitalWrite(buzzer,LOW);

  delay(500);
  Serial.println();
  
  Serial.print("Connecting to WiFi ");
  Serial.println(ssid);

  WiFi.begin(ssid, pwd);

  unsigned long starttime = millis();
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if ((millis()-starttime)>20000) {
      Serial.println("Could not connect to WiFi, abandoning.");
      break;
    }
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    nwmode = 0;
    leds.setPixelColor(0,0,30,0);
    leds.show();
    
  } else {
    Serial.println("Starting in Serial mode. Send 'alarm' to start alarm. Press button to stop alarm.");
    nwmode = 1;
    leds.setPixelColor(0,30,0,0);
    leds.show();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (nwmode == 1) { //serial mode
    while (Serial.available() > 0) {
      delay(100);
      String input = Serial.readString();
      if (input.substring(0,5).equalsIgnoreCase("alarm")) {
        state = 1;
      }
    }
    if (!digitalRead(button)) { //Button pressed
      state = 0;
    }
  } else { //wifi mode!!!

    if ((millis()-tcheck) > 5000) {
      tcheck = millis();
    
  
      Serial.print("connecting to ");
      Serial.println(host);
    
      // Use WiFiClient class to create TCP connections
      WiFiClient client;
      const int httpPort = 80;
      if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        leds.setPixelColor(1,30,0,0);
        leds.show();
        return;
      } else {
        leds.setPixelColor(1,0,30,0);
        leds.show();
      }
    
      // This will send the request to the server
      client.print(String("GET ") + path + " HTTP/1.1\r\n" +
                   "Host: " + host + "\r\n" +
                   "Connection: close\r\n\r\n");
  
      delay(100);
    
      // Read all the lines of the reply from server and print them to Serial
      while (client.available()) {
        const String data = client.readStringUntil('\r');
        if ((data.indexOf("alarm") >= 0) && active) { // alarm time!
          state = 1;
        } else {
          state = 0;
          active = 1;
        }
      }  
    }
  }


  if ((state == 1) && ((millis()-tlast) >= blinktime) ) {
    tlast = millis();
    leds.setPixelColor(ii %2,255,0,0);
    leds.setPixelColor(++ii %2,0,255,0);
    leds.show();
    digitalWrite(buzzer,HIGH);
  } else if (state == 0) {
    leds.setPixelColor(0,0,0,0);
    leds.setPixelColor(1,0,0,0);
    leds.show();
    digitalWrite(buzzer,LOW);
  }

  if (!digitalRead(button)) {
    active = 0;
    state = 0;
  }
}
