/*RC Cat Using Relay
4 channel relay
esp8266
1k resister (for esp'gnd'--> resister --> relay(gnd))
buzzer 

*/
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ==== Enter your Mobile Hotspot Wi-Fi Credentials ====
const char* ssid = "aaa";            // Your hotspot name
const char* password = "1234567800"; // Your hotspot password

// ==== Relay Pins ====
#define RELAY_LF D1   // Left Motor Forward
#define RELAY_LB D2   // Left Motor Backward
#define RELAY_RF D3   // Right Motor Forward
#define RELAY_RB D4   // Right Motor Backward

// ==== Buzzer Pin ====
#define BUZZER D5     // Active buzzer

ESP8266WebServer server(80);

// ==== Stop All Motors ====
void stopMotors() {
  digitalWrite(RELAY_LF, HIGH);
  digitalWrite(RELAY_LB, HIGH);
  digitalWrite(RELAY_RF, HIGH);
  digitalWrite(RELAY_RB, HIGH);
}

// ==== Beep Function ====
void beepBuzzer() {
  digitalWrite(BUZZER, HIGH);
  delay(200);
  digitalWrite(BUZZER, LOW);
}

// ==== Web Page ====
String htmlPage() {
  String page = "<!DOCTYPE html><html><head>";
  page += "<meta name='viewport' content='width=device-width, initial-scale=1.0'>";
  page += "<style>";
  page += "body{background:#111;color:white;text-align:center;font-family:Arial;}";
  page += "h2{color:#00e5ff;}";
  page += "button{width:120px;height:70px;font-size:20px;font-weight:bold;";
  page += "margin:10px;border:none;border-radius:12px;box-shadow:0 4px 6px rgba(0,0,0,0.3);cursor:pointer;}";
  page += ".forward{background:#4CAF50;color:white;}";   // Green
  page += ".backward{background:#f44336;color:white;}";  // Red
  page += ".left{background:#2196F3;color:white;}";      // Blue
  page += ".right{background:#FF9800;color:white;}";     // Orange
  page += ".stop{background:#9C27B0;color:white;}";      // Purple
  page += ".buzzer{background:#FFD700;color:black;}";    // Gold
  page += "</style></head><body>";
  page += "<h2>🚗 NodeMCU RC Car</h2>";
  page += "<div><a href='/forward'><button class='forward'>⬆ Forward</button></a></div>";
  page += "<div>";
  page += "<a href='/left'><button class='left'>⬅ Left</button></a>";
  page += "<a href='/stop'><button class='stop'>⏹ Stop</button></a>";
  page += "<a href='/right'><button class='right'>➡ Right</button></a>";
  page += "</div>";
  page += "<div><a href='/backward'><button class='backward'>⬇ Backward</button></a></div>";
  page += "<div><a href='/buzzer'><button class='buzzer'>🔔 Buzzer</button></a></div>";
  page += "</body></html>";
  return page;
}

// ==== Routes ====
void handleRoot() { server.send(200, "text/html", htmlPage()); }

void handleForward() {
  stopMotors();
  digitalWrite(RELAY_LF, LOW);  // LOW = ON
  digitalWrite(RELAY_RF, LOW);
  beepBuzzer();
  server.send(200, "text/html", htmlPage());
  Serial.println("Forward");
}

void handleBackward() {
  stopMotors();
  digitalWrite(RELAY_LB, LOW);
  digitalWrite(RELAY_RB, LOW);
  beepBuzzer();
  server.send(200, "text/html", htmlPage());
  Serial.println("Backward");
}

void handleLeft() {
  stopMotors();
  digitalWrite(RELAY_LB, LOW);
  digitalWrite(RELAY_RF, LOW);
  beepBuzzer();
  server.send(200, "text/html", htmlPage());
  Serial.println("Left");
}

void handleRight() {
  stopMotors();
  digitalWrite(RELAY_LF, LOW);
  digitalWrite(RELAY_RB, LOW);
  beepBuzzer();
  server.send(200, "text/html", htmlPage());
  Serial.println("Right");
}

void handleStop() {
  stopMotors();
  beepBuzzer();
  server.send(200, "text/html", htmlPage());
  Serial.println("Stop");
}

void handleBuzzer() {
  beepBuzzer();
  server.send(200, "text/html", htmlPage());
  Serial.println("🔔 Buzzer Pressed");
}

void setup() {
  Serial.begin(115200);

  // Relay pins as output (default HIGH = OFF for LOW-trigger relays)
  pinMode(RELAY_LF, OUTPUT);
  pinMode(RELAY_LB, OUTPUT);
  pinMode(RELAY_RF, OUTPUT);
  pinMode(RELAY_RB, OUTPUT);
  stopMotors();

  // Buzzer pin
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  // Connect to Mobile Hotspot
  Serial.println();
  Serial.print("Connecting to "); Serial.println(ssid);
  WiFi.begin(ssid, password);

  int timeout = 0;
  while (WiFi.status() != WL_CONNECTED && timeout < 20) {
    delay(500);
    Serial.print(".");
    timeout++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi connected!");
    Serial.print("IP Address: "); Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ Failed to connect. Check hotspot settings.");
  }

  // Routes
  server.on("/", handleRoot);
  server.on("/forward", handleForward);
  server.on("/backward", handleBackward);
  server.on("/left", handleLeft);
  server.on("/right", handleRight);
  server.on("/stop", handleStop);
  server.on("/buzzer", handleBuzzer);

  server.begin();
  Serial.println("✅ HTTP server started!");
}

void loop() {
  server.handleClient();
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
