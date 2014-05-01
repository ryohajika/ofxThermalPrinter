//
//  ofxYahooWeather.h
//
//  Created by Ryo Hajika(imaginaryShort) on 2/6/14.
//
//  based on a library for Arduino "Adafruit_Thermal"
//  https://github.com/adafruit/Adafruit-Thermal-Printer-Library
//
//  original descriptions as follows:

/*************************************************************************
 This is an Arduino library for the Adafruit Thermal Printer.
 Pick one up at --> http://www.adafruit.com/products/597
 These printers use TTL serial to communicate, 2 pins are required.
 
 Adafruit invests time and resources providing this open source code.
 Please support Adafruit and open-source hardware by purchasing products
 from Adafruit!
 
 Written by Limor Fried/Ladyada for Adafruit Industries.
 MIT license, all text above must be included in any redistribution.
 *************************************************************************/


#pragma once

#include "ofMain.h"

// Barcode types
#define UPC_A   0
#define UPC_E   1
#define EAN13   2
#define EAN8    3
#define CODE39  4
#define I25     5
#define CODEBAR 6
#define CODE93  7
#define CODE128 8
#define CODE11  9
#define MSI    10

// Though most of these printers are factory configured for 19200 baud
// operation, a few rare specimens instead work at 9600.  If so, change
// this constant.  This will NOT make printing slower!  The physical
// print and feed mechanisms are the limiting factor, not the port speed.
#define BAUDRATE  19200

// Number of microseconds to issue one byte to the printer.  11 bits
// (not 8) to accommodate idle, start and stop bits.  Idle time might
// be unnecessary, but erring on side of caution here.
#define BYTE_TIME (11L * 1000000L / BAUDRATE)

class ofxThermalPrinter {
    
public:
    ofxThermalPrinter();
    ~ofxThermalPrinter();
    
    void setup(string serialPort, unsigned int baudrate = BAUDRATE);
    void begin(int heatTime);
    void reset();
    void setDefault();
    void test();
    void testPage();
    
    void normal();
    void inverseSwitch(bool enableOrDisable);
    void upsideDownSwitch(bool enableOrDisable);
    void doubleHeightSwitch(bool enableOrDisable);
    void doubleWidthSwitch(bool enableOrDisable);
    void boldSwitch(bool enableOrDisable);
    void underlineOn(unsigned char weight = 1);
    void underlineOff();
    void strikeSwitch(bool enableOrDisable);
    
    void justify(char value);
    void feed(unsigned char x = 1);
    void feedRows(unsigned char);
    void flush();
    void online();
    void offline();
    void sleep();
    void sleepAfter(unsigned char seconds);
    void wake();
    void listen();
    
    void setSize(char value);
    void setLineHeight(int val = 32);
    
    void printBarcode(char * text, unsigned char type);
    void setBarcodeHeight(int val = 50);
    
    //void printBitmap(ofDirectory bitmap);
    
    void timeoutSet(unsigned long x);
    void timeoutWait();
    void setTimes(unsigned long printTime, unsigned long feedTime);
    
    bool hasPaper();
    
    void write(unsigned char c);
    void writeStringReturn(bool enableOrDisable = true);
    void writeString(string sentence);
    
protected:
    ofSerial serial;
    unsigned char   prevByte,      // Last character issued to printer
                    column,        // Last horizontal column printed
                    maxColumn,     // Page width (output 'wraps' at this point)
                    charHeight,    // Height of characters, in 'dots'
                    lineSpacing,   // Inter-line spacing (not line height), in dots
                    barcodeHeight; // Barcode height in dots, not including text
    unsigned long   resumeTime,    // Wait until micros() exceeds this before sending byte
                    dotPrintTime,  // Time to print a single dot line, in microseconds
                    dotFeedTime;   // Time to feed a single dot line, in microseconds
    int printMode;
    unsigned char bufTwo[2];
    unsigned char bufThree[3];
    
    void setPrintMode(unsigned char mask);
    void unsetPrintMode(unsigned char mask);
    void writePrintMode();
    void writeByte(unsigned char a);
    void writeBytes(unsigned char a, unsigned char b);
    void writeBytes(unsigned char a, unsigned char b, unsigned char c);
    void writeBytes(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
    
    bool bReturnMode = true;
    
};