#pragma once

#include "ofMain.h"
#include "basic-motion.h"
#include "KinematicSeek.h"
#include "Seek-Steering.h"
#include "Seek-Steering-Arrive.h"
#include "Wander-Steering-Kinematic.h"
#include "Wander-Steering-Dynamic.h"
#include "Flocking.h"

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
	BasicMotion* basic = new BasicMotion(50);
	SeekSteering* seek = new SeekSteering(50);
	SeekSteeringArrive* seek2 = new SeekSteeringArrive(50, 50, 0.1);
	WanderKinematic* w1 = new WanderKinematic();
	WanderDynamic* w2 = new WanderDynamic();
	Flocking* f = new Flocking(10);
};
