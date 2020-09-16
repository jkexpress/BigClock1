//JK with clock working as well
// 2020 09 16 - 2pm
// Now on github
//
//
//


#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

int delayval = 100; // timing delay in milliseconds

void setup() {
  
  Serial.begin(9600);
  delay(1000);
  Serial.println("----------------------------");
  Serial.println("DHS Clock , press m for Menu");
  while (!Serial) ; // wait for serial
  delay(200);
  Serial.println("DS1307RTC Read Test");
  Serial.println("-------------------");
   
  
 }

void loop() {
  tmElements_t tm;
  int rx_byte = 0;   
  if (Serial.available()) {
    rx_byte = Serial.read();
  }
  if ((rx_byte == 'm') || (rx_byte == 'M')) {
    // set the time
    Menu();
  }
  else {


  if (RTC.read(tm)) {
    Serial.print("Ok, Time = ");
    print2digits(tm.Hour);
    Serial.write(':');
    print2digits(tm.Minute);
    Serial.write(':');
    print2digits(tm.Second);
    Serial.print(", Date (D/M/Y) = ");
    Serial.print(tm.Day);
    Serial.write('/');
    Serial.print(tm.Month);
    Serial.write('/');
    Serial.print(tmYearToCalendar(tm.Year));
    Serial.println();
  } else {
    if (RTC.chipPresent()) {
      Serial.println("The DS1307 is stopped.  Please run the SetTime");
      Serial.println("example to initialize the time and begin running.");
      Serial.println();
    } else {
      Serial.println("DS1307 read error!  Please check the circuitry.");
      Serial.println();
    }
    delay(9000);
  }
  delay(1000);
}
     
}

void Menu() {
    Serial.println("Clock Menu 1.0");
    Serial.println("1 to enter, 2 to set and 3 to exit");
    for (;;) {
        switch (Serial.read()) {
            case '1':   Serial.println("option 1 - please enter full yyyymmddhhmmss");  break;
            case '2':   Serial.println("option 2 - setting clock now");  break;
            case '3': Serial.println("option 3 - returning to menu"); return;
            default: continue;  // includes the case 'no input'
        }
    }
}



void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}




