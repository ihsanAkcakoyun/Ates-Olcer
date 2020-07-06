#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <DallasTemperature.h>

#include <OneWire.h>

#define DATA_PIN 3
OneWire oneWire (DATA_PIN);
DallasTemperature sensors (&oneWire);

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define buzzer 6





void setup() {
  sensors.begin();
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  display.display();

  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
  giris();
}

void loop() {
  sensors.requestTemperatures();
  float sicaklik = sensors.getTempCByIndex(0);

  if (sicaklik >= 34.00)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(20, 5);
    display.println("Ates");
    display.setTextSize(3);
    display.setCursor(10, 30);
    display.println(sicaklik, 1 );
    display.setTextSize(1);
    display.setCursor(90, 30);
    display.println("o");
    display.setTextSize(2);
    display.setCursor(100, 35);
    display.println("C");
    display.display();
    noTone(buzzer);
    if (sicaklik >= 38.30)
    {
      tone(buzzer, 1000);
      delay(100);
      noTone(buzzer);
      delay(1000);
    }
  }
  else if ( sicaklik < 0)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 15);
    display.println("Sensor");
    display.setTextSize(2);
    display.setCursor(0, 40);
    display.println("Hata...");
    display.display();
    noTone(buzzer);
  }

  else
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 15);
    display.println("OLCUM");
    display.setTextSize(2);
    display.setCursor(0, 40);
    display.println("YAPILIYOR...");
    display.display();
    delay(2000);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 15);
    display.println("LUTFEN");
    display.setTextSize(2);
    display.setCursor(0, 40);
    display.println("BEKLEYINIZ");
    display.display();
    delay(2000);
    noTone(buzzer);
  }

}
void giris()
{
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 5);
  display.println("Sensoru");
  display.display();
  delay(500);
  display.setCursor(0, 25);
  display.println("Hastanin");
  display.display();
  delay(500);
  display.setCursor(0, 45);
  display.println("Koltuk");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 5);
  display.println("Altina");
  display.display();
  delay(500);
  display.setCursor(0, 25);
  display.println("Yerlestir");
  display.display();
  delay(500);
  display.setCursor(0, 45);
  display.println("Bekle !!!");
  display.display();
  delay(5000);
  noTone(buzzer);

}
