#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetLineWidth(0.3);
}

//--------------------------------------------------------------
void ofApp::update() {

	if (ofGetFrameNum() % 180 == 0) {

		this->r_rect = RecuRect(6, ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), 720, true);
	}

	this->r_rect.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	r_rect.draw();
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}