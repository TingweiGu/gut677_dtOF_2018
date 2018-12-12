#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpenCv.h"

using namespace cv;

class Scheduler : public ofThread {
public:
    unsigned long second = 59;
    unsigned long counter = 0;
    
    Scheduler() {
        timer.setPeriodicEvent(1000000000); // 1 second
        startThread();
    }
private:
    ofTimer timer;
    void threadedFunction() {
        while (isThreadRunning()) {
            timer.waitNext();
            second --;
            counter ++;
        }
    }
};

class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    void screen1();
    void screen2();
    void screen3();
    void screen4();
    void screen5();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //screen
    int s = 1;
    ofImage next;
    
    //background
    ofVideoGrabber cap;
    cv::Size cap_size;
    cv::Mat src, mini_src;
    cv::CascadeClassifier face_cascade;
    ofPoint gap;
    
    //timer
    Scheduler mysch;
    int day = 0;
    int hour = 0;
    int minute = 0;
    
    //typewriter
    ofTrueTypeFont font;
    ofTrueTypeFont type;
    string fullText;
    string Text;
    string text;
    string textToDraw;
    string TextToDraw;
    string drawtext;
    int timeBeginWait;
    int TimeBeginWait;
    
    //draw
    ofFbo fbo;
    ofImage portrait;
    ofImage img;
    ofImage clean;
    ofImage save;
    bool enter = true;
    
    //number
    ofImage key;
    bool a = true;
    string str = "";
    int start;
    ofImage list;
};


