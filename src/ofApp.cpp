#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // load all the images
    ofLog() << "Gathering images...";
    ofDirectory dir;
    
    //
    t=0;
    
    int nFiles = dir.listDir(ofToDataPath("good/"));
    if(nFiles) {
        for(int i=0; i<dir.size(); i++) {
            if (i % 20 == 0)    ofLog() << " - loading image "<<i<<" / "<<dir.size();
            string filePath = dir.getPath(i);
            images.push_back(ofImage());
            images.back().load(filePath);
            imgType[t] = 0; // ********************
            t++;
        }
    }
    
    //
    int nFiles2 = dir.listDir(ofToDataPath("bad/"));
    if(nFiles2) {
        for(int i=0; i<dir.size(); i++) {
            if (i % 20 == 0)    ofLog() << " - loading image "<<i<<" / "<<dir.size();
            string filePath = dir.getPath(i);
            images.push_back(ofImage());
            images.back().load(filePath);
            imgType[t] = 1; // ********************
            t++;
        }
    }
    // setup ofxCcv
    ccv.setup("image-net-2012.sqlite3");
    
    // encode all of the images with ofxCcv
    ofLog() << "Encoding images...";
    for (int i=0; i<images.size(); i++) {
        if (i % 20 == 0)    ofLog() << " - encoding image "<<i<<" / "<<images.size();
        vector<float> encoding = ccv.encode(images[i], ccv.numLayers()-1);
        encodings.push_back(encoding);
    }
    
    // run t-SNE and load image points to imagePoints
    ofLog() << "Run t-SNE on images";
    imagePoints = tsne.run(encodings, 2, 25, 0.1, true);
    
    // make the images the same size
    for (int i=0; i<images.size(); i++) {
        images[i].resize(100 * images[i].getWidth() / images[i].getHeight(), 100);
    }
    
    // setup gui
    gui.setup();
    gui.add(scale.set("scale", 4.0, 0.0, 10.0));
    gui.add(imageSize.set("imageSize", 1.0, 0.0, 2.0));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // 배경
    ofBackground(100, 100, 25);
    
    ofPushMatrix();
    // 마우스에 따라 이동
    ofTranslate(-ofGetMouseX() * (scale - 0.5), -ofGetMouseY() * (scale - 0.5));
    
    // 각 이미지 디스플레이
    for (int i=0; i<imagePoints.size(); i++) {
        float x = ofMap(imagePoints[i][0], 0, 1, 0, scale * ofGetWidth());
        float y = ofMap(imagePoints[i][1], 0, 1, 0, scale * ofGetHeight());
        
        // 이미지 디스플레이
        ofSetColor(255,255,255);
        images[i].draw(x, y, imageSize * images[i].getWidth(), imageSize * images[i].getHeight());
    }
    
    ofNoFill();
    for (int i=0; i<imagePoints.size(); i++) {
        float x = ofMap(imagePoints[i][0], 0, 1, 0, scale * ofGetWidth());
        float y = ofMap(imagePoints[i][1], 0, 1, 0, scale * ofGetHeight());
        
        // 테두리 그리기
        if(imgType[i] == 0) {
            ofSetColor(0,0,255);  // 0 이면 good
            ofSetLineWidth(2);
            ofDrawRectangle(x-1, y-1, imageSize * images[i].getWidth()+1, imageSize * images[i].getHeight()+1);
        }else {
            ofSetColor(255,0,0);  // 1이면 bad
            ofSetLineWidth(2);
            ofDrawRectangle(x-1, y-1, imageSize * images[i].getWidth()+1, imageSize * images[i].getHeight()+1);
        }
    }
    ofPopMatrix();
    
    gui.draw();
    
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
