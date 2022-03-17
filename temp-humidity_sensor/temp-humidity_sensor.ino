

// Breakout Room 7

// Proper variable declaration and assigned value 
// based on digital pin connected to on the Arduino board

//Include necessary library
#include <LiquidCrystal.h>
#include "DHT.h"

LiquidCrystal lcd(3, 2, 4, 5, 6, 7);

#define DHT_PIN 9

#define DHTTYPE DHT11


DHT dht(DHT_PIN, DHTTYPE);

// float hum;
// float temp;

void setup() 
{
    Serial.begin (9600); 
    // Configuring declared pins are input or output
    lcd.begin(16,2);
    dht.begin();
   
}

void loop() 
{
    delay(3500);

    float hum = dht.readHumidity();
    float temp = dht.readTemperature(false);
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Humidity = ");
    lcd.print(hum);
    Serial.print("Humidity = ");
    Serial.println(hum);
    
    
    lcd.setCursor(0,1); //set the cursor to column 0 and line 1
    lcd.print("Temp = ");
    lcd.print(temp);
    Serial.print("Temp = ");
    Serial.println(temp);
    
    // Check if any reads failed and exit early (to try again).
    if (isnan(hum)) {
      Serial.println(F("Failed to read from DHT sensor!"));
      return;
    }
}
