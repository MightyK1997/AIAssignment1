#pragma once

#include "ofMain.h"
#include "basic-motion.h"
#include "KinematicSeek.h"
#include "Seek-Steering.h"
#include "Seek-Steering-Arrive.h"
#include "Wander-Steering-Kinematic.h"
#include "Wander-Steering-Dynamic.h"
#include "Flocking-behavior.h"

#include "Dijkstra.h"
#include "AStarPathFollow.h"
#include "Grid.h"
#include "AI.h"
#include "DecisionTree.h"
#include "ActionNode.h"
#include "GameManager.h"
#include "DecisionNode.h"

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
	AStarPathFollow* pathfollow = new AStarPathFollow(Heuristic::Zero, m_Graph,5, 10, 0.1);
	Graph* m_Graph = new Graph();
	Grid* m_Grid = new Grid("grid.png", true);
	KinematicSeek kSeek;
	Boid* m_Player = new Boid();
	Boid* m_WanderBoid = new Boid();
	BasicMotion* basicMotion = new BasicMotion(5000);
	SeekSteeringArrive* seekArrive = new SeekSteeringArrive(m_WanderBoid, 50, 50, 0.1);
	WanderDynamic* dynamicWander = new WanderDynamic();
	Flocking* flock = new Flocking(10);
	int SelectedIndex = 1;
	std::vector<Node*> nodeList;



	AI* m_WanderAI = new AI();
	ActionManager* m_WanderAIManager = new ActionManager();
	ActionNode* m_WanderActionNode = new ActionNode();
	ActionNode* m_SeekActionNode = new ActionNode();
	Action* m_WanderAction = new Action();
	Action* m_SeekAction = new Action(5, 2);
	DecisionNode* m_DecisionNode = new DecisionNode();
	GameManager* m_GameManager = new GameManager();
	DecisionTree* m_DecisionTree = new DecisionTree(m_DecisionNode);
};
