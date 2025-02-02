#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
float ledPin = A7;
float sensorValue = 0;
float sensorValue1 = 0;

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, INPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
    display.clearDisplay();
  }
}
void loop() {
  display.clearDisplay();
  sensorValue = analogRead(ledPin);
  sensorValue1 = sensorValue * (5) / 1024;
  sensorValue1 = sensorValue1 * 1000;

 if ( sensorValue1> 3200) {
 display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10, 01);
  // Display static text
  display.println("TESTER");
  display.display();

   
    display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(25, 29);
  // Display static text

  display.println(" Open      Probe");
  display.display();
  delay(1000);
    }
else { 
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10, 01);
  // Display static text
  display.println("TESTER");
  display.display();


  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(18, 50);
  // Display static text
  display.println("Milliohm");
  display.display();





  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(25, 29);
  // Display static text
  display.println(sensorValue1);
  display.display();

 
     delay(2000);
    }

 

}
