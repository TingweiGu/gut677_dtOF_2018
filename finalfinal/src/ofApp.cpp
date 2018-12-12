#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetFrameRate(30);
    ofBackground(15);
    
    ofEnableDepthTest();
    ofSetLineWidth(0);
    
    cap.setup(320, 180);
    cap_size = cv::Size(320, 180);
    face_cascade.load("/usr/local/Cellar/opencv/3.4.3/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml");
    gap = ofPoint(0, 0);
    
    //screen
    next.load("next.png");
    list.load("list.png");
    
    //typewriter
    fullText = "Hi, I am Timer X. \n\nNice to meet you! \n\nWelcome to [Countdown For Keeps] Storage Space. \n\nI am going to help you manage your items and \n\nkeep them for long. \n\n\nLet's get start!";
    Text = "Let's draw a portrait for your selected item.";
    text = "How long do you plan to use it in terms of \nmonth?";
    textToDraw = "";
    TextToDraw = "";
    drawtext = "";
    timeBeginWait = ofGetElapsedTimeMillis();
    
    //draw
    fbo.allocate(ofGetWidth(), ofGetHeight());
    fbo.begin();
    ofClear(255);
    fbo.end();
    img.load("portrait.png");
    clean.load("clean.png");
    save.load("save.png");
    key.load("key.png");
    
    
}

//--------------------------------------------------------------
void ofApp::update() {
//credit to https://junkiyoshi.com/
    cap.update();
    if(cap.isFrameNew()){
        Mat src = ofxCv::toCv(cap.getPixels());
        cv::resize(src, mini_src, cap_size);
    }
    
    vector<cv::Rect> faces;
    face_cascade.detectMultiScale(mini_src, faces);
    
    if(faces.size() > 0){
        gap = ofPoint(ofMap(faces[0].x + faces[0].width / 2, 0, cap_size.width, 5, -5), ofMap(faces[0].y, 0, cap_size.height, 5, -5));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
    
    //draw rectangles
    for (int z = 0; z > -600; z += -20) {
        
        ofFill();
        ofSetColor(255, ofMap(z, 0, -600, 255, 0));

        ofBeginShape();
        ofVertex(ofGetWidth() * 0.7, ofGetHeight() * 0.7, z);
        ofVertex(-ofGetWidth() * 0.7, ofGetHeight() * 0.7, z);
        ofVertex(-ofGetWidth() * 0.7, -ofGetHeight() * 0.7, z);
        ofVertex(ofGetWidth() * 0.7, -ofGetHeight() * 0.7, z);

        ofNextContour(true);

        ofVertex(ofGetWidth() * 0.67, ofGetHeight() * 0.67, z);
        ofVertex(-ofGetWidth() * 0.67, ofGetHeight() * 0.67, z);
        ofVertex(-ofGetWidth() * 0.67, -ofGetHeight() * 0.67, z);
        ofVertex(ofGetWidth() * 0.67, -ofGetHeight() * 0.67, z);

        ofEndShape(true);
        
        ofTranslate(gap.x, gap.y);
    }
    ofPopMatrix();
    
    ofSetColor(255);
    ofFill();
    
    if(s == 1){
        screen1();
    }else if(s == 2){
        screen2();
    }else if(s == 3){
        screen3();
    }else if(s == 4){
        screen4();
    }else if(s == 5){
        screen5();
    }
}

//--------------------------------------------------------------
void ofApp::screen1(){
    bool isTime = (ofGetElapsedTimeMillis() - timeBeginWait) >= 100;
    if( (fullText.size() > textToDraw.size() ) & isTime ){
        // add one letter to the text to draw
        textToDraw += fullText[textToDraw.size()];
        //reset the time to wait
        timeBeginWait = ofGetElapsedTimeMillis();
    }
//    type.loadFont("type.otf", 12);
    ofSetColor(255);
    ofDrawBitmapString(textToDraw, 215, 150);
    next.draw(760, 230);
}

//--------------------------------------------------------------
void ofApp::screen2(){
    //    ofDrawBitmapString(ofGetMouseY(), 100, 100);
    bool IsTime = (ofGetElapsedTimeMillis() - TimeBeginWait) >= 100;
    if( (Text.size() > TextToDraw.size() ) & IsTime ){
        // add one letter to the text to draw
        TextToDraw += Text[TextToDraw.size()];
        //reset the time to wait
        TimeBeginWait = ofGetElapsedTimeMillis();
    }
    ofFill();
    ofSetColor(255);
    ofDrawBitmapString(TextToDraw, 220, 150);
    next.draw(760, 230);
    clean.draw(490, 310);
    save.draw(493, 350);
    ofNoFill();
    ofSetColor(255);
    ofDrawRectangle(300, 190, 180, 180);
    ofFill();
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::screen3(){
//    ofDrawBitmapString(ofGetMouseX(), 100, 100);
//    ofDrawBitmapString(ofGetMouseY(), 150, 100);
    bool IsTime = (ofGetElapsedTimeMillis() - TimeBeginWait) >= 100;
    if( (text.size() > drawtext.size() ) & IsTime ){
        // add one letter to the text to draw
        drawtext += text[drawtext.size()];
        //reset the time to wait
        TimeBeginWait = ofGetElapsedTimeMillis();
    }
    ofDrawBitmapString(drawtext, 220, 150);
    next.draw(760, 230);
    key.draw(5, 80);
    ofSetColor(255);
    font.loadFont("font.ttf", 90);
    font.drawString(str, 360, 280);
    day = 45;
    start = 30 * ofToInt(str);
}

//--------------------------------------------------------------
void ofApp::screen4(){
//        ofDrawBitmapString(ofGetMouseX(), 100, 100);
//        ofDrawBitmapString(ofGetMouseY(), 150, 100);
    
    if(enter){
        enter = false;
        mysch.second = 59;
        mysch.counter = 0;
    }
    
    if(hour == 0){
        hour += 24;
        day --;
    }
    
    if(minute == 0){
        minute += 59;
        hour --;
    }
    
    if(mysch.second == -1){
        mysch.second += 60;
        minute --;
    }
    int days = mysch.counter/60/60/24;
    
    ofSetColor(255);
    font.loadFont("font.ttf", 90);
    font.drawString(ofToString(start, 0), 400, 260);
    font.loadFont("font.ttf", 20);
    font.drawString(ofToString(hour, 0) + " : " + ofToString(minute, 0) + " : " + ofToString(mysch.second, 0), 412, 300);
    portrait.draw(210,150);
//    font.loadFont("font.ttf", 15);
    ofDrawBitmapString("You two have been together for " + ofToString(days, 0) + " days.", 240, 350);
    list.draw(50, 35);
}

//--------------------------------------------------------------
void ofApp::screen5(){
//    ofDrawBitmapString(ofGetMouseX(), 100, 100);
//    ofDrawBitmapString(ofGetMouseY(), 150, 100);
    portrait.draw(185,135,30,30);
    ofDrawBitmapString(ofToString(start, 0) + " days " + ofToString(hour, 0) + " hours " + ofToString(minute, 0) + " minutes " + ofToString(mysch.second, 0) + " seconds left ", 235, 155);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(s == 2){
        fbo.begin();
        ofCircle(x, y, 2);
        fbo.end();
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (ofGetMouseX() >= 765 && ofGetMouseX() <= 776 && ofGetMouseY() >= 230 && ofGetMouseY() <= 250){
        s += 1;
    }
    if (ofGetMouseX() >= 494 && ofGetMouseX() <= 511 && ofGetMouseY() >= 311 && ofGetMouseY() <= 337){
        fbo.begin();
        ofClear(255,255,255, 0);
        fbo.end();
    }
    if (ofGetMouseX() >= 494 && ofGetMouseX() <= 513 && ofGetMouseY() >= 351 && ofGetMouseY() <= 371){
        portrait.grabScreen(305, 195, 170, 170);
        portrait.save("portrait.png");
    }
    
    //key
    if(s == 3){
        if (ofGetMouseX() >= 48 && ofGetMouseX() <= 60 && ofGetMouseY() >= 93 && ofGetMouseY() <= 136){
            str.append ("1");
        }
        if (ofGetMouseX() >= 138 && ofGetMouseX() <= 148 && ofGetMouseY() >= 180 && ofGetMouseY() <= 203){
            str.append ("2");
        }
        if (ofGetMouseX() >= 96 && ofGetMouseX() <= 109 && ofGetMouseY() >= 258 && ofGetMouseY() <= 306){
            str.append ("3");
        }
        if (ofGetMouseX() >= 122 && ofGetMouseX() <= 135 && ofGetMouseY() >= 293 && ofGetMouseY() <= 325){
            str.append ("4");
        }
        if (ofGetMouseX() >= 79 && ofGetMouseX() <= 93 && ofGetMouseY() >= 147 && ofGetMouseY() <= 191){
            str.append ("5");
        }
        if (ofGetMouseX() >= 52 && ofGetMouseX() <= 68 && ofGetMouseY() >= 299 && ofGetMouseY() <= 348){
            str.append ("6");
        }
        if (ofGetMouseX() >= 43 && ofGetMouseX() <= 58 && ofGetMouseY() >= 189 && ofGetMouseY() <= 249){
            str.append ("7");
        }
        if (ofGetMouseX() >= 141 && ofGetMouseX() <= 153 && ofGetMouseY() >= 234 && ofGetMouseY() <= 276){
            str.append ("8");
        }
        if (ofGetMouseX() >= 67 && ofGetMouseX() <= 79 && ofGetMouseY() >= 235 && ofGetMouseY() <= 273){
            str.append ("9");
        }
        if (ofGetMouseX() >= 110 && ofGetMouseX() <= 122 && ofGetMouseY() >= 190 && ofGetMouseY() <= 237){
            str.append ("0");
        }
        if (ofGetMouseX() >= 19 && ofGetMouseX() <= 37 && ofGetMouseY() >= 405 && ofGetMouseY() <= 448){
            str = str.substr(0, str.size()-1);
        }
    }
    
    if (ofGetMouseX() >= 50 && ofGetMouseX() <= 80 && ofGetMouseY() >= 40 && ofGetMouseY() <= 60){
        s = 5;
    }
    
    if (ofGetMouseX() >= 210 && ofGetMouseX() <= 560 && ofGetMouseY() >= 151 && ofGetMouseY() <= 173){
        s = 4;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
//--------------------------------------------------------------



