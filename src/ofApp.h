#pragma once

#include "ofMain.h"
#include "basic-motion.h"
#include "KinematicSeek.h"
#include "Seek-Steering.h"
#include "Seek-Steering-Arrive.h"
#include "Wander-Steering-Kinematic.h"
#include "Wander-Steering-Dynamic.h"
#include "Flocking-behavior.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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


private:
	KinematicSeek kSeek;
	BasicMotion* basicMotion = new BasicMotion(5000);
	SeekSteeringArrive* seekArrive = new SeekSteeringArrive(50, 50, 0.1);
	WanderDynamic* dynamicWander = new WanderDynamic();
	Flocking* flock = new Flocking(10);
	int SelectedIndex = 1;
};
