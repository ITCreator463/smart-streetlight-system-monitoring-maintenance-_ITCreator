#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseESP8266.h>
#include <ESP8266WebServer.h>
#include <time.h>
#include <ArduinoJson.h>
#include <stdlib.h>

 
// Set these to run example.
#define FIREBASE_HOST "street-light-fault-detection.firebaseio.com"
#define FIREBASE_AUTH "pHQ8pzi9PfWPnaDmL9IoB4Oh2s8ZgTGnzUK1P7LD"
#define WIFI_SSID "abc"
#define WIFI_PASSWORD "password"
float timezone = 5.5;
String myString1,myString2,myString3,myString4,myString5,myString6,myString7,myString8;
const int Sensor1=16;
const int Sensor2=5;
const int Sensor3=4;
const int Sensor4=14;
const int Sensor5=12;
const int Sensor6=13;
const int Sensor7=9;
const int Sensor8=10;
String a="1";
String b="2";
String c="3";
String d="4";
String e="5";
String f="6";
String g="7";
String h="8";
int flag1=0;
int flag11=0;
int flag2=0;
int flag22=0;
int flag3=0;
int flag33=0;
int flag4=0;
int flag44=0;
int flag5=0;
int flag55=0;
int flag6=0;
int flag66=0;
int flag7=0;
int flag77=0;
int flag8=0;
int flag88=0;
FirebaseData firebaseData;
void setup()
{
  // Debug console
  Serial.begin(9600);
  //pinMode(vr ,INPUT);
  // connect to wifi.
  pinMode(Sensor1,INPUT);
  pinMode(Sensor2,INPUT);
  pinMode(Sensor3,INPUT);
  pinMode(Sensor4,INPUT);
  pinMode(Sensor5,INPUT);
  pinMode(Sensor6,INPUT);
  pinMode(Sensor7,INPUT);
  pinMode(Sensor8,INPUT);
 
 
  //pinMode(D0,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  configTime(timezone * 3600, 0, "pool.ntp.org", "time.nist.gov");
    Serial.println("\nWaiting for time");
    while (!time(nullptr)) {
        Serial.print(".");
        delay(1000);
    }
}
 
void loop()
{
    long state1 = digitalRead(Sensor1);
    Serial.println(a);
    if(state1 == HIGH)    
    {  
      Serial.println(" light:1:Fault "+state1);
      setFirebaseData2(a);
      flag11=0;
      if(flag1==0){
        pushFirebaseData2(a);
        flag1=1;
        }
      }
    else{
    setFirebaseData1(a);
    flag1=0;
      if(flag11==0){
          pushFirebaseData1(a);
          flag11=1;
        }
    }
 
   
    long state2 = digitalRead(Sensor2);
   if(state2 == HIGH)    
    {  
      Serial.println(" light:2:Fault "+state2);
      setFirebaseData2(b);
      flag22=0;
      if(flag2==0){
        pushFirebaseData2(b);
        flag2=1;
        }
      }
  else{
    setFirebaseData1(b);
    flag2=0;
      if(flag22==0){
          pushFirebaseData1(b);
          flag22=1;
        }
    }
 
  long state3 = digitalRead(Sensor3);
   if(state3 == HIGH)    
    {  
    Serial.println(" light:3:Fault "+state3);
    setFirebaseData2(c);
    flag33=0;
      if(flag3==0){
        pushFirebaseData2(c);
        flag3=1;
        }
    }
   else{
    setFirebaseData1(c);
    flag3=0;
      if(flag33==0){
          pushFirebaseData1(c);
          flag33=1;
        }
    }
 
 
  long state4 = digitalRead(Sensor4);
   if(state4 == HIGH)    
    {  
    Serial.println(" light:4:Fault "+state4);
    setFirebaseData2(d);
    flag44=0;
      if(flag4==0){
        pushFirebaseData2(d);
        flag4=1;
        }
    }
  else{
    setFirebaseData1(d);
    flag4=0;
      if(flag44==0){
          pushFirebaseData1(d);
          flag44=1;
        }
    }
 
  long state5 = digitalRead(Sensor5);
   if(state5 == HIGH)    
    {  
    Serial.println(" light:5:Fault "+state5);
    setFirebaseData2(e);
    flag55=0;
      if(flag5==0){
        pushFirebaseData2(e);
        flag5=1;
        }
    }
  else{
    setFirebaseData1(e);
    flag5=0;
      if(flag55==0){
          pushFirebaseData1(e);
          flag55=1;
        }
    }
 
  long state6 = digitalRead(Sensor6);
   if(state6 == HIGH)    
    {  
    Serial.println(" light:6:Fault "+state6);
    setFirebaseData2(f);
    flag66=0;
      if(flag6==0){
        pushFirebaseData2(f);
        flag6=1;
        }
    }
     else{
    setFirebaseData1(f);
    flag6=0;
      if(flag66==0){
          pushFirebaseData1(f);
          flag66=1;
        }
    }
 
 
  long state7 = digitalRead(Sensor7);
   if(state7 == HIGH)    
    {  
    Serial.println(" light:7:Fault "+state7);
      setFirebaseData2(g);
      flag77=0;
      if(flag7==0){
        pushFirebaseData2(g);
        flag7=1;
        }
    }
   else{
   setFirebaseData1(g);
   flag7=0;
      if(flag77==0){
          pushFirebaseData1(g);
          flag77=1;
        }
  }
 
  long state8 = digitalRead(Sensor8);
   if(state8 == HIGH)    
    {  
    Serial.println(" light:8:Fault "+state8);
    setFirebaseData2(h);
   flag88=0;
      if(flag8==0){
        pushFirebaseData2(h);
        flag8=1;
        }
    }
    else{
    setFirebaseData1(h);
    flag8=0;
      if(flag88==0){
          pushFirebaseData1(h);
          flag88=1;
        }
    }
 
  delay(100);          

   
}
void setFirebaseData1(String x) {
    time_t now = time(nullptr);
   
    if (Firebase.setString(firebaseData, "/Variable/light"+x+"/status/", "Light is ready")) {
       
       
    } else {
        Serial.println(firebaseData.errorReason());
    }

}
void setFirebaseData2(String x) {
    time_t now = time(nullptr);
   
    if (Firebase.setString(firebaseData, "/Variable/light"+x+"/status/", "Light is faulty")) {
       
    } else {
        Serial.println(firebaseData.errorReason());
    }

}
void pushFirebaseData1(String x) {
    time_t now = time(nullptr); //ctime(&now)
    String ass = String(now);
    String data = "light_is_ready " + String(now);
    if (Firebase.pushString(firebaseData, "/Variable/light"+x+"/record/",data)) {
      Firebase.setString(firebaseData, "/Variable/light"+x+"/time/", ass);
        Serial.println(data);
    } else {
        Serial.print("__" + String(ctime( & now)));
        Serial.println(firebaseData.errorReason());
    }

}
void pushFirebaseData2(String x) {
    time_t now = time(nullptr); //ctime(&now)
    String ass = String(now);
    String data = "light_is_fault " + String(now);
    if (Firebase.pushString(firebaseData, "/Variable/light"+x+"/record/",data)) {
      Firebase.setString(firebaseData, "/Variable/light"+x+"/time/", ass);
        Serial.println(data);
    } else {
        Serial.print("__" + String(ctime( & now)));
        Serial.println(firebaseData.errorReason());
    }

}
