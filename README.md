# ofxThermalPrinter

[Thermal Printer](http://www.adafruit.com/products/597) class for openFrameworks (tested on oF v0.8.0)


# Usage
## Open port
### ofApp.h
`ofxThermalPrinter printer;`
### ofApp.cpp
If you connect a thermal printer to a mac by using FTDI's module, write

`printer.setup("dev/tty.xxxxxxx");`

and then you can use the printer.

## Print sequences
### sentences
`printer.writeString("string here...");`

### barcode
`printer.printBarcode("barcode text...", type);`

(supports: UPC_A, UPC_E,  EAN13, EAN8, CODE39, I25, CODEBAR, CODE93, CODE128, CODE11, MSI)

### justification
`printer.justify('char value');`

(Left align: 'L', Center align: 'C', Right align: 'R')

### character size
`printer.setSize('char value');`

('S', 'M', 'L')

### feed rows
`printer.feed();  // a row will be feeded on a paper`
`printer.feedRows(unsigned char value);`

## Extras
`printer.inverseSwitch(bool enableOrDisable);     // invert print pattern`

`printer.upsideDownSwitch(bool enableOrDisable);  // upside down`

`printer.doubleHeightSwitch(bool enableOrDisable);// enable double height`

`printer.doubleWidthSwitch(bool enableOrDisable);`

`printer.boldSwitch(bool enableOrDisable);        // enable bold type`

`printer.underlineOn(unsigned char weight = 1);   // set underline`

`printer.underlineOff();                          // disable underline`


# License
based on a library for Arduino [Adafruit_Thermal](https://github.com/adafruit/Adafruit-Thermal-Printer-Library)

### original description of the library

 This is an Arduino library for the Adafruit Thermal Printer.
 Pick one up at --> http://www.adafruit.com/products/597
 
 These printers use TTL serial to communicate, 2 pins are required.
 
 
 Adafruit invests time and resources providing this open source code.
 
 Please support Adafruit and open-source hardware by purchasing products
 from Adafruit!
 
 
 Written by Limor Fried/Ladyada for Adafruit Industries.
 
 MIT license, all text above must be included in any redistribution.
