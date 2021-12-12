#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	shader.load("", "eye.frag");
	baseFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	currentTime = ofGetElapsedTimeMillis();
	ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (ofGetElapsedTimeMillis() - currentTime > waitTime && !isLerping) {
		newXPosition = ofRandom(boundsX[0], boundsX[1]);
   	newYPosition = ofRandom(boundsY[0], boundsY[1]);
		
   	isLerping = true;
	}
	
	if (isLerping) {
   currentPosition[0] = ofLerp(currentPosition[0], newXPosition, 0.005);
   currentPosition[1] = ofLerp(currentPosition[1], newYPosition, 0.005);
		
   // Am I in situ?
   if (abs(currentPosition[0] - newXPosition) < 3.0 &&
       abs(currentPosition[1] - newYPosition) < 3.0) {
     isLerping = false; // Stop
     currentTime = ofGetElapsedTimeMillis(); // Wait
   }
  }

	// Send shader updates
	// Update fbo.
	baseFbo.begin();
		shader.begin();
			shader.setUniform2f("u_resolution", baseFbo.getWidth(), baseFbo.getHeight());
			shader.setUniform1f("u_time", ofGetElapsedTimef());
			shader.setUniform2f("u_position", currentPosition[0], currentPosition[1]);
			ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
		shader.end();
	baseFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	baseFbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}