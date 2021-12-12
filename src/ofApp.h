#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
	
		// Loading the GOD shader in here. 
		ofShader shader;
		ofFbo baseFbo;
		float currentPosition[2] = {640, 360}; // Center of the screen
		float boundsX[2] = {-500, 1700};
		float boundsY[2] = {-200, 900};
		float newXPosition, newYPosition;
		long waitTime = 5000;
		long currentTime;
		bool isLerping = false; 
};
