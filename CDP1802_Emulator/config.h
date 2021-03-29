/**
 * @file  config.h
 * 
 */
 
#define RED_LED       13
#define TFT_RESET     24
#define TFT_BACKLIGHT 25
#define LIGHT_SENSOR  A2
#define SD_CS         32       
#define SPKR_SHUTDOWN 50

#define TFT_D0        34 // Data bit 0 pin (MUST be on PORT byte boundary)
#define TFT_WR        26 // Write-strobe pin (CCL-inverted timer output)
#define TFT_DC        10 // Data/command pin
#define TFT_CS        11 // Chip-select pin
#define TFT_RST       24 // Reset pin
#define TFT_RD         9 // Read-strobe pin
#define TFT_BACKLIGHT 25
// ILI9341 with 8-bit parallel interface:
Adafruit_ILI9341 tft = Adafruit_ILI9341(tft8bitbus, TFT_D0, TFT_WR, TFT_DC, TFT_CS, TFT_RST, TFT_RD);

Adafruit_FlashTransport_QSPI flashTransport(PIN_QSPI_SCK, PIN_QSPI_CS, PIN_QSPI_IO0, PIN_QSPI_IO1, PIN_QSPI_IO2, PIN_QSPI_IO3);
Adafruit_SPIFlash flash(&flashTransport);

Adafruit_ADT7410 tempsensor = Adafruit_ADT7410();

#define YP A4  // must be an analog pin, use "An" notation!
#define XM A7  // must be an analog pin, use "An" notation!
#define YM A6   // can be a digital pin
#define XP A5   // can be a digital pin
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
#define X_MIN  750
#define X_MAX  325
#define Y_MIN  840
#define Y_MAX  240

Adafruit_GFX_Button coin = Adafruit_GFX_Button();
Adafruit_GFX_Button apply = Adafruit_GFX_Button();
SdFat SD;
