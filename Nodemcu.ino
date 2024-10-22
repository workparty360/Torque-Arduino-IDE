#include<ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);
#define ENA D0
#define IN1 D1
#define IN2 D2
#define IN3 D3
#define IN4 D4
#define ENB D5

void forward();
void backward();
void right();
void left();
void stop();
void turnr();
void turnl();

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  Serial.begin(115220);
  WiFi.softAP("Transformers","Amazon@051106");
  Serial.println();
  Serial.println("nodemcu success!");
  Serial.println(WiFi.softAPIP());

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
client=server.available();
String request;
if(client ==1)
{
  request = client.readStringUntil('\n');
 Serial.println(request);
 request.trim();
}
if(request=="GET /?dir=T HTTP/1.1")//carforward
{
  forward();
  delay(100);
}
if(request=="GET /?dir=S HTTP/1.1")//carstop
{
  stop();
}
if(request=="GET /?dir=R HTTP/1.1")//carright
{
  right();
  delay(100);
}
if(request=="GET /?dir=L HTTP/1.1")//carleft
{
  left();
  delay(100);
}
if(request=="GET /?dir=RAC HTTP/1.1")//carleft
{
  turnl();
}
if(request=="GET /?dir=RC HTTP/1.1")//carleft
{
  turnr();
}
if(request=="GET /?dir=B HTTP/1.1")//carleft
{
  backward();
  delay(100);
}
if(request=="GET /?dir=ON HTTP/1.1")
{
  digitalWrite(ENB,HIGH);
}
if(request=="GET /?dir=OFF HTTP/1.1")
{
  digitalWrite(ENB,LOW);
}
if(request=="GET /?dir=ON1 HTTP/1.1")
{
  digitalWrite(ENA,HIGH);
}
if(request=="GET /?dir=OFF1 HTTP/1.1")
{
  digitalWrite(ENA,LOW);
}
}
void forward() {
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}
void backward() {
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
}
void right() {
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
}
void left() {
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}
void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void turnr()
{
  right();
  delay(500);
}
void turnl()
{
  left();
  delay(500);
}


