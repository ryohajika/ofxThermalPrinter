#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //printer.setup("serial port address");       // address is like : /dev/tty.usbserial-ABCD
    
    //gui setup
    gui.setup();
    gui.add(feedARow.setup("Feed a row"));
    gui.add(printTestString.setup("Test Sentence"));
    gui.add(testBarcode.setup("Test Barcode"));
    
    feedARow.addListener(this, &testApp::printARow);
    printTestString.addListener(this, &testApp::printString);
    testBarcode.addListener(this, &testApp::printBarcode);
}

/****************/
void testApp::printARow(){
    ofLogNotice("feed a row!");
    printer.feed();
}
void testApp::printString(){
    ofLogNotice("print test sentences!");
    printer.justify('L');
    printer.writeString("The future is to predict it, but to invent it.");
    printer.feed();
    printer.justify('R');
    printer.boldSwitch(true);
    printer.writeString("- Alan Kay");
    printer.feedRows(2);
    printer.setDefault();
}
void testApp::printBarcode(){
    ofLogNotice("print test barcode pattern!");
    printer.printBarcode("1234567890", UPC_A);
}
/*****************/

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    gui.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
