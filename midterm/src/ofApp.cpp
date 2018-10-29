#include "ofApp.h"
float a = 0;
float b = 0;
ofImage door, door2, shelf, shelf2, set1, set2, tv, tv2, shoe, shoe2, sofa, sofa2, kitchen, kitchen2, chair, chair2, desk, desk2, table, table2, coffee, coffee2, game, game2, ball, cart, cart2;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(100);
    
    glm::vec2 rectPos = glm::vec2(1320,29);
    rectCollider.set(rectPos, 90, 171);
    
    glm::vec2 rectPos2 = glm::vec2(610,29);
    rectCollider2.set(rectPos2, 90, 171);
    
    glm::vec2 rectPos3 = glm::vec2(700,12);
    rectCollider3.set(rectPos3, 100, 181);
    
    glm::vec2 rectPos4 = glm::vec2(10,12);
    rectCollider4.set(rectPos4, 100, 181);
    
    glm::vec2 rectPos5 = glm::vec2(800,40);
    rectCollider5.set(rectPos5, 100, 154);
    
    glm::vec2 rectPos6 = glm::vec2(110,40);
    rectCollider6.set(rectPos6, 100, 154);
    
    glm::vec2 rectPos7 = glm::vec2(980,31);
    rectCollider7.set(rectPos7, 220, 159);
    
    glm::vec2 rectPos8 = glm::vec2(260,31);
    rectCollider8.set(rectPos8, 220, 159);
    
    glm::vec2 rectPos9 = glm::vec2(1287,110);
    rectCollider9.set(rectPos9, 33, 100);
    
    glm::vec2 rectPos10 = glm::vec2(570,110);
    rectCollider10.set(rectPos10, 33, 100);
    
    glm::vec2 rectPos11 = glm::vec2(960,200);
    rectCollider11.set(rectPos11, 263, 100);
    
    glm::vec2 rectPos12 = glm::vec2(240,200);
    rectCollider12.set(rectPos12, 263, 100);
    
    glm::vec2 rectPos13 = glm::vec2(1150,550);
    rectCollider13.set(rectPos13, 283, 150);
    
    glm::vec2 rectPos14 = glm::vec2(430,550);
    rectCollider14.set(rectPos14, 283, 150);
    
    glm::vec2 rectPos15 = glm::vec2(1125,400);
    rectCollider15.set(rectPos15, 300, 130);
    
    glm::vec2 rectPos16 = glm::vec2(405,400);
    rectCollider16.set(rectPos16, 300, 130);
    
    glm::vec2 rectPos17 = glm::vec2(730,130);
    rectCollider17.set(rectPos17, 110, 120);
    
    glm::vec2 rectPos18 = glm::vec2(10,130);
    rectCollider18.set(rectPos18, 110, 120);
    
    glm::vec2 rectPos19 = glm::vec2(730,570);
    rectCollider19.set(rectPos19, 278, 112);
    
    glm::vec2 rectPos20 = glm::vec2(10,570);
    rectCollider20.set(rectPos20, 278, 112);
    
    glm::vec2 rectPos21 = glm::vec2(730,170);
    rectCollider21.set(rectPos21, 40, 123);
    
    glm::vec2 rectPos22 = glm::vec2(10,170);
    rectCollider22.set(rectPos22, 40, 123);
    
    glm::vec2 rectPos23 = glm::vec2(790,350);
    rectCollider23.set(rectPos23, 100, 100);
    
    glm::vec2 rectPos24 = glm::vec2(100,350);
    rectCollider24.set(rectPos24, 100, 100);
    
    glm::vec2 rectPos25 = glm::vec2(1000,450);
    rectCollider25.set(rectPos25, 52, 50);
    
    glm::vec2 rectPos26 = glm::vec2(20,480);
    rectCollider26.set(rectPos26, 90, 68);
    
    glm::vec2 rectPos27 = glm::vec2(740,480);
    rectCollider27.set(rectPos27, 90, 68);
    
    //load image
    door.load("door.png");
    door2.load("door2.png");
    shelf.load("shelf.png");
    shelf2.load("shelf2.png");
    set1.load("set.png");
    set2.load("set2.png");
    tv.load("tv.png");
    tv2.load("tv2.png");
    shoe.load("shoe.png");
    shoe2.load("shoe2.png");
    sofa.load("sofa.png");
    sofa2.load("sofa2.png");
    kitchen.load("kitchen.png");
    kitchen2.load("kitchen2.png");
    chair.load("chair.png");
    chair2.load("chair2.png");
    desk.load("desk.png");
    desk2.load("desk2.png");
    table.load("table.png");
    table2.load("table2.png");
    coffee.load("coffee.png");
    coffee2.load("coffee2.png");
    game.load("game.png");
    game2.load("game2.png");
    ball.load("ball.png");
    cart.load("cart.png");
    cart2.load("cart2.png");
    
}

//--------------------------------------------------------------
void ofApp::update(){
    glm::vec2 destination;
    destination.x   = ofGetMouseX();
    destination.y   = ofGetMouseY();
    
    float percent   = .05;
    glm::vec2 diff = destination - pos;
    pos += percent * diff;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofDrawLine(720, 0, 720, 800);
    
//    ofSetColor(255,255,0,0);
//    ofDrawCircle(300, 300, 50);
    
    
    
//    //circle
//    if (abs(int(pos.y+a-300)) <= 200 && abs(int(pos.x+b-300)) <= 150){
//        ofSetColor(255,255,0,255-(abs(int(pos.y-300))+abs(int(pos.x-300))));
//        ofDrawCircle(300, 300, 50);
//    }

    //door1
    glm::vec2 nearestPoint; // clamp circle to rect bounds
    nearestPoint.x = ofClamp(pos.x, rectCollider.getLeft(), rectCollider.getRight());
    nearestPoint.y = ofClamp(pos.y, rectCollider.getTop(), rectCollider.getBottom());

    glm::vec2 diff;
    diff.x = nearestPoint.x - (pos.x);
    diff.y = nearestPoint.y - (pos.y);
    bool rectCollided = glm::length(diff) <= 200;

    if (rectCollided) {
        ofSetColor(255,255,255,255-(abs(int(diff.x))+abs(int(diff.y)))*1.2);
        door.draw(1320,29);
    }
    
    //door2
    glm::vec2 nearestPoint2; // clamp circle to rect bounds
    nearestPoint2.x = ofClamp(pos.x, rectCollider2.getLeft(), rectCollider2.getRight());
    nearestPoint2.y = ofClamp(pos.y, rectCollider2.getTop(), rectCollider2.getBottom());
    
    glm::vec2 diff2;
    diff2.x = nearestPoint2.x - (pos.x);
    diff2.y = nearestPoint2.y - (pos.y);
    bool rectCollided2 = glm::length(diff2) <= 200;
    
    if (rectCollided2) {
        ofSetColor(255,255,255,255-(abs(int(diff2.x))+abs(int(diff2.y)))*1.2);
        door2.draw(610,29);
    }
    
    //shelf1
    glm::vec2 nearestPoint3; // clamp circle to rect bounds
    nearestPoint3.x = ofClamp(pos.x, rectCollider3.getLeft(), rectCollider3.getRight());
    nearestPoint3.y = ofClamp(pos.y, rectCollider3.getTop(), rectCollider3.getBottom());
    
    glm::vec2 diff3;
    diff3.x = nearestPoint3.x - (pos.x);
    diff3.y = nearestPoint3.y - (pos.y);
    bool rectCollided3 = glm::length(diff3) <= 200;
    
    if (rectCollided3) {
        ofSetColor(255,255,255,255-(abs(int(diff3.x))+abs(int(diff3.y)))*2);
        shelf.draw(730,12);
    }
    
    //shelf2
    glm::vec2 nearestPoint4; // clamp circle to rect bounds
    nearestPoint4.x = ofClamp(pos.x, rectCollider4.getLeft(), rectCollider4.getRight());
    nearestPoint4.y = ofClamp(pos.y, rectCollider4.getTop(), rectCollider4.getBottom());
    
    glm::vec2 diff4;
    diff4.x = nearestPoint4.x - (pos.x);
    diff4.y = nearestPoint4.y - (pos.y);
    bool rectCollided4 = glm::length(diff4) <= 200;
    
    if (rectCollided4) {
        ofSetColor(255,255,255,255-(abs(int(diff4.x))+abs(int(diff4.y)))*2);
        shelf2.draw(10,12);
    }
    
    //set1
    glm::vec2 nearestPoint5; // clamp circle to rect bounds
    nearestPoint5.x = ofClamp(pos.x, rectCollider5.getLeft(), rectCollider5.getRight());
    nearestPoint5.y = ofClamp(pos.y, rectCollider5.getTop(), rectCollider5.getBottom());
    
    glm::vec2 diff5;
    diff5.x = nearestPoint5.x - (pos.x);
    diff5.y = nearestPoint5.y - (pos.y);
    bool rectCollided5 = glm::length(diff5) <= 200;
    
    if (rectCollided5) {
        ofSetColor(255,255,255,255-(abs(int(diff5.x))+abs(int(diff5.y)))*2);
        set1.draw(830,40);
    }
    
    //set2
    glm::vec2 nearestPoint6; // clamp circle to rect bounds
    nearestPoint6.x = ofClamp(pos.x, rectCollider6.getLeft(), rectCollider6.getRight());
    nearestPoint6.y = ofClamp(pos.y, rectCollider6.getTop(), rectCollider6.getBottom());
    
    glm::vec2 diff6;
    diff6.x = nearestPoint6.x - (pos.x);
    diff6.y = nearestPoint6.y - (pos.y);
    bool rectCollided6 = glm::length(diff6) <= 200;
    
    if (rectCollided6) {
        ofSetColor(255,255,255,255-(abs(int(diff6.x))+abs(int(diff6.y)))*2);
        set2.draw(110,40);
    }
    
    //tv1
    glm::vec2 nearestPoint7; // clamp circle to rect bounds
    nearestPoint7.x = ofClamp(pos.x, rectCollider7.getLeft(), rectCollider7.getRight());
    nearestPoint7.y = ofClamp(pos.y, rectCollider7.getTop(), rectCollider7.getBottom());
    
    glm::vec2 diff7;
    diff7.x = nearestPoint7.x - (pos.x);
    diff7.y = nearestPoint7.y - (pos.y);
    bool rectCollided7 = glm::length(diff7) <= 200;
    
    if (rectCollided7) {
        ofSetColor(255,255,255,255-(abs(int(diff7.x))+abs(int(diff7.y)))*2);
        tv.draw(980,31);
    }
    
    //tv2
    glm::vec2 nearestPoint8; // clamp circle to rect bounds
    nearestPoint8.x = ofClamp(pos.x, rectCollider8.getLeft(), rectCollider8.getRight());
    nearestPoint8.y = ofClamp(pos.y, rectCollider8.getTop(), rectCollider8.getBottom());
    
    glm::vec2 diff8;
    diff8.x = nearestPoint8.x - (pos.x);
    diff8.y = nearestPoint8.y - (pos.y);
    bool rectCollided8 = glm::length(diff8) <= 200;
    
    if (rectCollided8) {
        ofSetColor(255,255,255,255-(abs(int(diff8.x))+abs(int(diff8.y)))*2);
        tv2.draw(260,31);
    }
    
    //shoe1
    glm::vec2 nearestPoint9; // clamp circle to rect bounds
    nearestPoint9.x = ofClamp(pos.x, rectCollider9.getLeft(), rectCollider9.getRight());
    nearestPoint9.y = ofClamp(pos.y, rectCollider9.getTop(), rectCollider9.getBottom());
    
    glm::vec2 diff9;
    diff9.x = nearestPoint9.x - (pos.x);
    diff9.y = nearestPoint9.y - (pos.y);
    bool rectCollided9 = glm::length(diff9) <= 200;
    
    if (rectCollided9) {
        ofSetColor(255,255,255,255-(abs(int(diff9.x))+abs(int(diff9.y)))*2);
        shoe.draw(1287,110);
    }
    
    //shoe2
    glm::vec2 nearestPoint10; // clamp circle to rect bounds
    nearestPoint10.x = ofClamp(pos.x, rectCollider10.getLeft(), rectCollider10.getRight());
    nearestPoint10.y = ofClamp(pos.y, rectCollider10.getTop(), rectCollider10.getBottom());
    
    glm::vec2 diff10;
    diff10.x = nearestPoint10.x - (pos.x);
    diff10.y = nearestPoint10.y - (pos.y);
    bool rectCollided10 = glm::length(diff10) <= 200;
    
    if (rectCollided10) {
        ofSetColor(255,255,255,255-(abs(int(diff10.x))+abs(int(diff10.y)))*2);
        shoe2.draw(570,110);
    }
    
    //sofa1
    glm::vec2 nearestPoint11; // clamp circle to rect bounds
    nearestPoint11.x = ofClamp(pos.x, rectCollider11.getLeft(), rectCollider11.getRight());
    nearestPoint11.y = ofClamp(pos.y, rectCollider11.getTop(), rectCollider11.getBottom());
    
    glm::vec2 diff11;
    diff11.x = nearestPoint11.x - (pos.x);
    diff11.y = nearestPoint11.y - (pos.y);
    bool rectCollided11 = glm::length(diff11) <= 200;
    
    if (rectCollided11) {
        ofSetColor(255,255,255,255-(abs(int(diff11.x))+abs(int(diff11.y)))*2);
        sofa.draw(960,200);
    }
    
    //sofa2
    glm::vec2 nearestPoint12; // clamp circle to rect bounds
    nearestPoint12.x = ofClamp(pos.x, rectCollider12.getLeft(), rectCollider12.getRight());
    nearestPoint12.y = ofClamp(pos.y, rectCollider12.getTop(), rectCollider12.getBottom());
    
    glm::vec2 diff12;
    diff12.x = nearestPoint12.x - (pos.x);
    diff12.y = nearestPoint12.y - (pos.y);
    bool rectCollided12 = glm::length(diff12) <= 200;
    
    if (rectCollided12) {
        ofSetColor(255,255,255,255-(abs(int(diff12.x))+abs(int(diff12.y)))*2);
        sofa2.draw(240,200);
    }
    
    //kitchen1
    glm::vec2 nearestPoint13; // clamp circle to rect bounds
    nearestPoint13.x = ofClamp(pos.x, rectCollider13.getLeft(), rectCollider13.getRight());
    nearestPoint13.y = ofClamp(pos.y, rectCollider13.getTop(), rectCollider13.getBottom());
    
    glm::vec2 diff13;
    diff13.x = nearestPoint13.x - (pos.x);
    diff13.y = nearestPoint13.y - (pos.y);
    bool rectCollided13 = glm::length(diff13) <= 200;
    
    if (rectCollided13) {
        ofSetColor(255,255,255,255-(abs(int(diff13.x))+abs(int(diff13.y)))*2);
        kitchen.draw(1150,550);
    }
    
    //kitchen2
    glm::vec2 nearestPoint14; // clamp circle to rect bounds
    nearestPoint14.x = ofClamp(pos.x, rectCollider14.getLeft(), rectCollider14.getRight());
    nearestPoint14.y = ofClamp(pos.y, rectCollider14.getTop(), rectCollider14.getBottom());
    
    glm::vec2 diff14;
    diff14.x = nearestPoint14.x - (pos.x);
    diff14.y = nearestPoint14.y - (pos.y);
    bool rectCollided14 = glm::length(diff14) <= 200;
    
    if (rectCollided14) {
        ofSetColor(255,255,255,255-(abs(int(diff14.x))+abs(int(diff14.y)))*2);
        kitchen2.draw(430,550);
    }
    
    //chair1
    glm::vec2 nearestPoint15; // clamp circle to rect bounds
    nearestPoint15.x = ofClamp(pos.x, rectCollider15.getLeft(), rectCollider15.getRight());
    nearestPoint15.y = ofClamp(pos.y, rectCollider15.getTop(), rectCollider15.getBottom());
    
    glm::vec2 diff15;
    diff15.x = nearestPoint15.x - (pos.x);
    diff15.y = nearestPoint15.y - (pos.y);
    bool rectCollided15 = glm::length(diff15) <= 200;
    
    if (rectCollided15) {
        ofSetColor(255,255,255,255-(abs(int(diff15.x))+abs(int(diff15.y)))*2);
        chair.draw(1125,400);
    }
    
    //chair2
    glm::vec2 nearestPoint16; // clamp circle to rect bounds
    nearestPoint16.x = ofClamp(pos.x, rectCollider16.getLeft(), rectCollider16.getRight());
    nearestPoint16.y = ofClamp(pos.y, rectCollider16.getTop(), rectCollider16.getBottom());
    
    glm::vec2 diff16;
    diff16.x = nearestPoint16.x - (pos.x);
    diff16.y = nearestPoint16.y - (pos.y);
    bool rectCollided16 = glm::length(diff16) <= 200;
    
    if (rectCollided16) {
        ofSetColor(255,255,255,255-(abs(int(diff16.x))+abs(int(diff16.y)))*2);
        chair2.draw(405,400);
    }
    
    //desk1
    glm::vec2 nearestPoint17; // clamp circle to rect bounds
    nearestPoint17.x = ofClamp(pos.x, rectCollider17.getLeft(), rectCollider17.getRight());
    nearestPoint17.y = ofClamp(pos.y, rectCollider17.getTop(), rectCollider17.getBottom());
    
    glm::vec2 diff17;
    diff17.x = nearestPoint17.x - (pos.x);
    diff17.y = nearestPoint17.y - (pos.y);
    bool rectCollided17 = glm::length(diff17) <= 200;
    
    if (rectCollided17) {
        ofSetColor(255,255,255,255-(abs(int(diff17.x))+abs(int(diff17.y)))*2);
        desk.draw(730,130);
    }
    
    //desk2
    glm::vec2 nearestPoint18; // clamp circle to rect bounds
    nearestPoint18.x = ofClamp(pos.x, rectCollider18.getLeft(), rectCollider18.getRight());
    nearestPoint18.y = ofClamp(pos.y, rectCollider18.getTop(), rectCollider18.getBottom());
    
    glm::vec2 diff18;
    diff18.x = nearestPoint18.x - (pos.x);
    diff18.y = nearestPoint18.y - (pos.y);
    bool rectCollided18 = glm::length(diff18) <= 200;
    
    if (rectCollided18) {
        ofSetColor(255,255,255,255-(abs(int(diff18.x))+abs(int(diff18.y)))*2);
        desk2.draw(10,130);
    }
    
    //table1
    glm::vec2 nearestPoint19; // clamp circle to rect bounds
    nearestPoint19.x = ofClamp(pos.x, rectCollider19.getLeft(), rectCollider19.getRight());
    nearestPoint19.y = ofClamp(pos.y, rectCollider19.getTop(), rectCollider19.getBottom());
    
    glm::vec2 diff19;
    diff19.x = nearestPoint19.x - (pos.x);
    diff19.y = nearestPoint19.y - (pos.y);
    bool rectCollided19 = glm::length(diff19) <= 200;
    
    if (rectCollided19) {
        ofSetColor(255,255,255,255-(abs(int(diff19.x))+abs(int(diff19.y)))*2);
        table.draw(730,588);
    }
    
    //table2
    glm::vec2 nearestPoint20; // clamp circle to rect bounds
    nearestPoint20.x = ofClamp(pos.x, rectCollider20.getLeft(), rectCollider20.getRight());
    nearestPoint20.y = ofClamp(pos.y, rectCollider20.getTop(), rectCollider20.getBottom());
    
    glm::vec2 diff20;
    diff20.x = nearestPoint20.x - (pos.x);
    diff20.y = nearestPoint20.y - (pos.y);
    bool rectCollided20 = glm::length(diff20) <= 200;
    
    if (rectCollided20) {
        ofSetColor(255,255,255,255-(abs(int(diff20.x))+abs(int(diff20.y)))*2);
        table2.draw(10,588);
    }
    
    //coffee1
    glm::vec2 nearestPoint21; // clamp circle to rect bounds
    nearestPoint21.x = ofClamp(pos.x, rectCollider21.getLeft(), rectCollider21.getRight());
    nearestPoint21.y = ofClamp(pos.y, rectCollider21.getTop(), rectCollider21.getBottom());
    
    glm::vec2 diff21;
    diff21.x = nearestPoint21.x - (pos.x);
    diff21.y = nearestPoint21.y - (pos.y);
    bool rectCollided21 = glm::length(diff21) <= 200;
    
    if (rectCollided21) {
        ofSetColor(255,255,255,255-(abs(int(diff21.x))+abs(int(diff21.y)))*2);
        coffee.draw(728,170);
    }
    
    //coffee2
    glm::vec2 nearestPoint22; // clamp circle to rect bounds
    nearestPoint22.x = ofClamp(pos.x, rectCollider22.getLeft(), rectCollider22.getRight());
    nearestPoint22.y = ofClamp(pos.y, rectCollider22.getTop(), rectCollider22.getBottom());
    
    glm::vec2 diff22;
    diff22.x = nearestPoint22.x - (pos.x);
    diff22.y = nearestPoint22.y - (pos.y);
    bool rectCollided22 = glm::length(diff22) <= 200;
    
    if (rectCollided22) {
        ofSetColor(255,255,255,255-(abs(int(diff22.x))+abs(int(diff22.y)))*2);
        coffee2.draw(8,170);
    }
    
    //game1
    glm::vec2 nearestPoint23; // clamp circle to rect bounds
    nearestPoint23.x = ofClamp(pos.x, rectCollider23.getLeft(), rectCollider23.getRight());
    nearestPoint23.y = ofClamp(pos.y, rectCollider23.getTop(), rectCollider23.getBottom());
    
    glm::vec2 diff23;
    diff23.x = nearestPoint23.x - (pos.x);
    diff23.y = nearestPoint23.y - (pos.y);
    bool rectCollided23 = glm::length(diff23) <= 200;
    
    if (rectCollided23) {
        ofSetColor(255,255,255,255-(abs(int(diff23.x))+abs(int(diff23.y)))*2);
        game.draw(790,350);
    }
    
    //game2
    glm::vec2 nearestPoint24; // clamp circle to rect bounds
    nearestPoint24.x = ofClamp(pos.x, rectCollider24.getLeft(), rectCollider24.getRight());
    nearestPoint24.y = ofClamp(pos.y, rectCollider24.getTop(), rectCollider24.getBottom());
    
    glm::vec2 diff24;
    diff24.x = nearestPoint24.x - (pos.x);
    diff24.y = nearestPoint24.y - (pos.y);
    bool rectCollided24 = glm::length(diff24) <= 200;
    
    if (rectCollided24) {
        ofSetColor(255,255,255,255-(abs(int(diff24.x))+abs(int(diff24.y)))*2);
        game2.draw(100,350);
    }
    
    //ball
    glm::vec2 nearestPoint25; // clamp circle to rect bounds
    nearestPoint25.x = ofClamp(pos.x, rectCollider25.getLeft(), rectCollider25.getRight());
    nearestPoint25.y = ofClamp(pos.y, rectCollider25.getTop(), rectCollider25.getBottom());
    
    glm::vec2 diff25;
    diff25.x = nearestPoint25.x - (pos.x);
    diff25.y = nearestPoint25.y - (pos.y);
    bool rectCollided25 = glm::length(diff25) <= 200;
    
    if (rectCollided25) {
        ofSetColor(255,255,255,255-(abs(int(diff25.x))+abs(int(diff25.y)))*2);
        ball.draw(1000,450);
    }
    
    //cart1
    glm::vec2 nearestPoint26; // clamp circle to rect bounds
    nearestPoint26.x = ofClamp(pos.x, rectCollider26.getLeft(), rectCollider26.getRight());
    nearestPoint26.y = ofClamp(pos.y, rectCollider26.getTop(), rectCollider26.getBottom());
    
    glm::vec2 diff26;
    diff26.x = nearestPoint26.x - (pos.x);
    diff26.y = nearestPoint26.y - (pos.y);
    bool rectCollided26 = glm::length(diff26) <= 200;
    
    if (rectCollided26) {
        ofSetColor(255,255,255,255-(abs(int(diff26.x))+abs(int(diff26.y)))*2);
        cart.draw(20,480);
    }
    
    //cart2
    glm::vec2 nearestPoint27; // clamp circle to rect bounds
    nearestPoint27.x = ofClamp(pos.x, rectCollider27.getLeft(), rectCollider27.getRight());
    nearestPoint27.y = ofClamp(pos.y, rectCollider27.getTop(), rectCollider27.getBottom());
    
    glm::vec2 diff27;
    diff27.x = nearestPoint27.x - (pos.x);
    diff27.y = nearestPoint27.y - (pos.y);
    bool rectCollided27 = glm::length(diff27) <= 200;
    
    if (rectCollided27) {
        ofSetColor(255,255,255,255-(abs(int(diff27.x))+abs(int(diff27.y)))*2);
        cart2.draw(740,480);
    }
    
    ofPushStyle();
    
    //glow
    ofColor glowColor = ofColor::fromHex(0x3E544C);
    const ofColor targetColor = ofColor::fromHex(0xB5B585);
    
    glowColor = glowColor.lerp(targetColor, lerpAmount/100.0);
    
    if(lerpAmount>100 || lerpAmount<1)
        lerpStep *= -1;
    lerpAmount += lerpStep;
    
    int glowResolution = 20;
    glowColor.a = 255.0/glowResolution;
    ofSetColor(glowColor);
    
    for(int i = glowResolution; i>0; i--){
        ofDrawCircle(pos, i*2);
    }
    
    //light
    ofSetCircleResolution(30);
    ofSetColor(ofColor(255,255,0));
    ofDrawCircle(pos,2);
    ofPopStyle();
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

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
