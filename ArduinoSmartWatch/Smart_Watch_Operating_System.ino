/*
    Smart Watch Arduino is a part of open source smart watch project.
    Copyright (C) 2014  Gabriel Krivian
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see [http://www.gnu.org/licenses/].
*/
/*
SmartWatch Arduino v1.0
 
Written by Gabriel Krivian (gabekrivian@gmail.com)
All text above, and the first splash screen(Adafruit) must be included in any redistribution
*/



#include <Time.h>


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int a = 60;
int b = 40;
double RAD=3.141592/180;
double LR = 89.99;
int centerX = 31;
int centerY = 31;
int iRadius = 29;

void setup()   {
  Serial.begin(9600);
  // randomSeed(analogRead(0));
  setTime(5, 23, 0, 30, 8, 2015);
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  display.display();
  delay(2000);
  // Clear the buffer.
  display.clearDisplay();

}


void loop() {

  while (1) {

    startPage();
    if (digitalRead(8) == HIGH) {
      break;
    }
  }



  for(int z = 0; z < 1000; z++){
  
    movement();

    homePage();

    if ( a > 128) {
      a = 1;

      while (1) {
        movement();
        appsPage();
        if (a < 0) {
          a = 128;
          z = 0;
          break;

        }

      }
    }



    if ( a < 0) {
      a = 128;

      while (1) {
        movement();
        newsPage();
        if (a > 128) {
          a = 1;
          z=0;
          break;

        }

      }
    }
    if ( b < 0) {

      b = 64;
      while (1) {
        movement();
        notesPage();
        if (b > 64) {
          b = 1;
         z = 0;
          break;

        }

      }
    }
    if ( b > 64) {

      b = 1;
      while (1) {
        movement();
        settingsPage();
        if (b < 0) {
          b = 64;
         z = 0;
          break;

        }

      }
    }

}
  }

void mouseCursor(int x, int y) {

  display.drawPixel(x, y + 1, WHITE);
  display.drawPixel(x, y + 2, WHITE);
  display.drawPixel(x, y + 3, WHITE);
  display.drawPixel(x, y + 4, WHITE);
  display.drawPixel(x, y + 5, WHITE);
  display.drawPixel(x, y + 6, WHITE);
  display.drawPixel(x, y + 7, WHITE);
  display.drawPixel(x, y + 8, WHITE);
  display.drawPixel(x, y + 9, WHITE);
  display.drawPixel(x, y + 10, WHITE);
  display.drawPixel(x, y + 11, WHITE);
  display.drawPixel(x, y + 12, WHITE);
  display.drawPixel(x, y + 13, WHITE);
  display.drawPixel(x + 1, y + 1, WHITE);
  display.drawPixel(x + 2, y + 2, WHITE);
  display.drawPixel(x + 3, y + 3, WHITE);
  display.drawPixel(x + 4, y + 4, WHITE);
  display.drawPixel(x + 5, y + 5, WHITE);
  display.drawPixel(x + 6, y + 6, WHITE);
  display.drawPixel(x + 7, y + 7, WHITE);
  display.drawPixel(x + 8, y + 8, WHITE);
  display.drawPixel(x + 9, y + 9, WHITE);
  display.drawPixel(x + 8, y + 9, WHITE);
  display.drawPixel(x + 7, y + 9, WHITE);
  display.drawPixel(x + 6, y + 9, WHITE);
  display.drawPixel(x + 6, y + 10, WHITE);
  display.drawPixel(x + 7, y + 11, WHITE);
  display.drawPixel(x + 7, y + 12, WHITE);
  display.drawPixel(x + 7, y + 13, WHITE);
  display.drawPixel(x + 7, y + 14, WHITE);
  display.drawPixel(x + 6, y + 14, WHITE);
  display.drawPixel(x + 5, y + 13, WHITE);
  display.drawPixel(x + 4, y + 12, WHITE);
  display.drawPixel(x + 4, y + 11, WHITE);
  display.drawPixel(x + 3, y + 10, WHITE);
  display.drawPixel(x + 2, y + 11, WHITE);
  display.drawPixel(x + 1, y + 12, WHITE);

}

void homePage(void) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(42, 10);
  display.print(hour());
  display.print(":");
  display.print(minute());
  display.print(":");
  display.print(second());
  display.setCursor(35, 20);
  display.print(day());
  display.print("/");
  display.print(month());
  display.print("/");
  display.print(year());
  display.setCursor(100,0);
 // if using 3.7v Lipo
 int Y = 0.0833 * batteryLife() + -250;
 
 
  display.print(Y);
  display.print("%");

  mouseCursor(a, b);
  display.display();
  display.clearDisplay();
}

void appsPage(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(41, 0);
  display.print("APPS");
  display.drawLine(3,42,124,42,WHITE);
  display.drawLine(42,22,42,81,WHITE);
  display.drawLine(85,22,85,81,WHITE);
  display.setCursor(9,27);
  display.setTextSize(1);
  display.print("Coin");
  mouseCursor(a, b);
  display.display();
  display.clearDisplay();
}
void newsPage(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(38, 0);
  display.print("NEWS");
  mouseCursor(a, b);
  display.setTextSize(1);
 display.setCursor(0,20);
 display.print("No news is currently avaliable at this time, check back later");
  display.display();
  display.clearDisplay();
}

void settingsPage(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 0);
  display.print("SETTINGS");
  mouseCursor(a, b);
  display.display();
  display.clearDisplay();
}

void notesPage(void) {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30, 0);
  display.print("NOTES");
  mouseCursor(a, b);
  display.display();
  display.clearDisplay();
}


  
  
void showTimePin(int center_x, int center_y, double pl1, double pl2, double pl3) {
 
 double x1 = center_x + (iRadius * pl1) * cos((6 * pl3 + LR) * RAD);
 double y1 = center_y + (iRadius * pl1) * sin((6 * pl3 + LR) * RAD);
 double x2 = center_x + (iRadius * pl2) * cos((6 * pl3 - LR) * RAD);
 double y2 = center_y + (iRadius * pl2) * sin((6 * pl3 - LR) * RAD);
  
  display.drawLine(x1,y1,x2,y2, WHITE);
}

void startPage(void) {
  int r;
  if(hour() > 9){
    r = 68;
  }
  else {
    r = 75;
  }
 display.setCursor(r,16);
display.setTextSize(2);
display.setTextColor(WHITE);
display.print(hour());
display.print(":");
display.print(minute());
display.setCursor(72,34);
display.setTextSize(1);
display.setTextColor(WHITE);
display.print(month());
display.print("/");
display.print(day());
display.print("/");
display.print(year());
  display.drawCircle(centerX, centerY, 31, WHITE);

 
    showTimePin(centerX, centerY, 0.1, 0.6, hour()*5 + (minute()*5/60));
    showTimePin(centerX, centerY, 0.1, 0.75, minute());
    showTimePin(centerX, centerY, 0.1, 0.9, second());
   
  
  display.display();
  display.clearDisplay();
}

void movement(void) {

  if ( digitalRead(5) == HIGH) {
    b = b - 3;
  }
  if (digitalRead(6) == HIGH) {
    a = a - 3;
  }
  if (digitalRead(7) == HIGH) {
    a = a + 3;
  }
  if (digitalRead(9) == HIGH) {
    b = b + 3;
  }
}

int batteryLife() {
  int result;
  // Read 1.1V reference against AVcc
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(5); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Convert
  while (bit_is_set(ADCSRA,ADSC));
  result = ADCL;
  result |= ADCH<<8;
  result = 1126400L / result; // Back-calculate AVcc in mV
 
  return result;
}
