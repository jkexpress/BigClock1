//JK Menu to get time date and set clock 2020 10 8 9 22
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup() {
  // initialize serial:
  Serial.begin(115200);
  Serial.println("Please enter yy,mm,dd,hh,mm,ss");
  rtc.begin();
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int yy = Serial.parseInt();
    // do it again:
    int mm = Serial.parseInt();
    // do it again:
    int dd = Serial.parseInt();
    // do it again:
    int hr = Serial.parseInt();
    // do it again:
    int min = Serial.parseInt();
    // do it again:
    int sec = Serial.parseInt();  
    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      yy =  2000+constrain(yy, 1, 90);
      mm =  constrain(mm, 1, 12);
      dd =  constrain(dd, 1, 31);
      hr =  constrain(hr, 1, 24);
      min =  constrain(min, 1, 60);
      sec =  constrain(sec, 1, 60);
      Serial.println("------------------");
      Serial.print(yy,DEC );
      Serial.print("\t");
      Serial.print(mm, DEC );
      Serial.print("\t");
      Serial.println(dd, DEC);
      Serial.print(hr,DEC );
      Serial.print("\t");
      Serial.print(min, DEC );
      Serial.print("\t");
      Serial.println(sec, DEC);
      rtc.adjust(DateTime(yy, mm, dd, hr, min, sec));  
    }
  }
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(1000);
     
}
