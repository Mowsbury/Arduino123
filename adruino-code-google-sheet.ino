#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
unsigned long time2;
String readString;
const char* ssid = "MyNET";
const char* password = "MyPassword";
const char* host = "script.google.com";
const int httpsPort = 443;
WiFiClientSecure client;
const char* fingerprint = "46 B2 C3 44 9C 59 09 8B 01 B6 F8 BD 4C FB 00 74 91 2F EF F6";
String APP_ID = "YOUR WEB APP ID";  

void setup()
{
 WiFi.mode(WIFI_STA);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) 
 delay(500); 
}

void loop()
{
 float time2 = micros();
 sendData(time2);
 delay(3000);
}

void sendData(float time2)
{
 String s_time2= String(time2);
 String url = "/macros/s/" + APP_ID + "/exec?time2=" + s_time2;
 
 client.setInsecure();
 client.connect(host, httpsPort);
 client.verify(fingerprint, host);
 client.print(String("GET ") + url + " HTTP/1.1\r\n" +
        "Host: " + host + "\r\n" +
        "User-Agent: BuildFailureDetectorESP8266\r\n" +
        "Connection: close\r\n\r\n");
}
