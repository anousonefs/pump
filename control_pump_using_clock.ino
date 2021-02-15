#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#define RELAY 2

void setup () 
{
  pinMode(RELAY, OUTPUT);
  digitalWrite(RELAY, HIGH);
  
  Serial.begin(9600);
  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
  
  // Comment out below lines once you set the date & time.
    // Following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
    // Following line sets the RTC with an explicit date & time
    // for example to set January 27 2017 at 12:56 you would call:
//     rtc.adjust(DateTime(2021, 1, 23, 5, 34, 0));
  }
}

void loop () {
    DateTime now = rtc.now();
    
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    switch (now.hour()){
    case 16: //when the clock reads 6 AM seconds (Once every 24 hours)
      digitalWrite(RELAY, LOW);   // turn the Relay on (HIGH is the voltage level)
      Serial.println("pump ON");
      delay(40000);              // wait for 20 second
      digitalWrite(RELAY, HIGH);    // turn the Relay off by making the voltage LOW
      Serial.println("pump OFF");
      delay(3600000);              // wait for 3600 second
     
  }

    switch (now.hour()){
    case 23: //when the clock reads 8 PM seconds (Once every 24 hours)
      digitalWrite(RELAY, LOW);   // turn the Relay on (HIGH is the voltage level)
      Serial.println("pump ON");
      delay(40000);              // wait for 20 second
      digitalWrite(RELAY, HIGH);    // turn the Relay off by making the voltage LOW
      Serial.println("pump OFF");
      delay(3600000);              // wait for 3600 second
     
  }

  
    switch (now.hour()){
    case 7: //when the clock reads 8 PM seconds (Once every 24 hours)
      digitalWrite(RELAY, LOW);   // turn the Relay on (HIGH is the voltage level)
      Serial.println("pump ON");
      delay(40000);              // wait for 20 second
      digitalWrite(RELAY, HIGH);    // turn the Relay off by making the voltage LOW
      Serial.println("pump OFF");
      delay(3600000);              // wait for 3600 second
     
  }

    delay(1000);
}
