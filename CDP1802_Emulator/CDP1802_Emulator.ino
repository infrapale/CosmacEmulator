// This program does a test of all the hardware so you can get an example of how to read
// sensors, touchscreen, and display stuff!

#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <Adafruit_SPIFlash.h>
#include "Adafruit_ADT7410.h"
#include "TouchScreen.h"
#include <SdFat.h>
#include <WiFiNINA.h>
#include "test1.h"
#include "config.h"
#include "registers.h"
#include "emulate.h"
#include "storage.h"

extern uint8_t mem[MEM_SIZE]; 

void setup() {
  uint16_t code_addr;
  
  Serial.begin(9600);
  delay(4000);
  while (!Serial);

  Serial.println("All Test!");

  pinMode(RED_LED, OUTPUT);
  pinMode(TFT_BACKLIGHT, OUTPUT);
  digitalWrite(TFT_BACKLIGHT, HIGH);

  pinMode(TFT_RESET, OUTPUT);
  digitalWrite(TFT_RESET, HIGH);
  delay(10);
  digitalWrite(TFT_RESET, LOW);
  delay(10);
  digitalWrite(TFT_RESET, HIGH);
  delay(10);

  tft.begin();

  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_GREEN);
  tft.setTextWrap(true);
  tft.setCursor(0, 0);
  tft.print("CDP1802 Emulator");
  tft.setCursor(0, 24);
  tft.print("infrapale@gmail.com");
  if (!flash.begin()){
    Serial.println("Could not find flash on QSPI bus!");
    while (1);
  }
  Serial.println("Reading QSPI ID");
  Serial.print("JEDEC ID: 0x"); Serial.println(flash.getJEDECID(), HEX);

  emulate_initialize();
  storage_load_direct(test_code, 3, 0x0000);
  for (code_addr = 0; code_addr < 0; code_addr++){
      Serial.print(mem[code_addr],HEX);
      Serial.print(" ");
      Serial.println("");
  }
  emulate_reset_cpu();
  emulate_run();

}

void loop() 
{
  
}
