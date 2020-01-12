/*
 * ESP32_SOS flash SOS with Dev Kit LED (Pin 1)
 * 200111
 * Juergen Walter
 * modified: S.O.S Morse Code Arduino https://create.arduino.cc/projecthub/onyx/morse-code-s-o-s-flasher-c0d296
 * ESP32 and Morse Code internationally recognized by treaty  https://en.wikipedia.org/wiki/Morse_code
 */

int ledPin=1;       //Dev Kit ESP32

void setup() {
  // put your setup code here, to run once:
    
  pinMode(ledPin,OUTPUT);
                   
}

void loop() {
  // put your main code here, to run repeatedly:
  
  flash(200); flash(200); flash(200); // S --> unit = 200ms
  delay(600); /* not 300ms because the length of a dot is one unit
               * space between letters is three units
               * otherwise the flashes run together */
  flash(600); flash(600); flash(600); // O --> A dash is three units
                                      // space between letters is three units
  flash(200); flash(200); flash(200); // S
  delay(1300);
    
}

void flash(int duration)
{
  digitalWrite(ledPin,LOW);     //LED on
  delay(duration);
  digitalWrite(ledPin,HIGH);    //LED off
  delay(duration);
}
