/*
 * ESP32_SOS flash SOS with LED (Pin 1)
 * 200111
 * Juergen Walter
 * modified: S.O.S Morse Code Arduino https://create.arduino.cc/projecthub/onyx/morse-code-s-o-s-flasher-c0d296
 * ESP32
 */

#include <Wire.h>                 // I2C
#include <Adafruit_GFX.h>         // OLED
#include <Adafruit_SSD1306.h>     // Graphic

#define OLED_RESET 4 // not used nicht genutzt bei diesem Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int ledPin=1;       //Dev Kit ESP32

void setup() {
  // put your setup code here, to run once:
    
  pinMode(ledPin,OUTPUT);
 // Dev Kit doesn't work! TxD=LED=Pin1   Serial.begin(115200); // Initialize hardware serial:

// initialize with the I2C addr 0x3C
// mit I2C-Adresse 0x3c initialisieren
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(3000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(INVERSE); 
                 
}
    unsigned int TextS=0;         // Textgroesse


void loop() {
  // put your main code here, to run repeatedly:
  display.println("new SOS ");
  display.display(); 
  flash(200); flash(200); flash(200); // S
  delay(300); // otherwise the flashes run together
  flash(500); flash(500); flash(500); // O
  flash(200); flash(200); flash(200); // S
  delay(3000);
    
}

void flash(int duration)
{
  digitalWrite(ledPin,LOW);     //LED on
  delay(duration);
  digitalWrite(ledPin,HIGH);    //LED off
  delay(duration);
}
