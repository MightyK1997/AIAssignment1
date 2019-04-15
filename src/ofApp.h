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

#include "BehaviorTree.h"
#include "Selector.h"
#include "BooleanTask.h"
#include "ActionTask.h"
#include "Inverter.h"
#include "Sequencer.h"
#include "Entropy.h"

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
	Boid* m_Player = new Boid();
	Boid* m_WanderBoid = new Boid();
	AStarPathFollow* pathfollow = new AStarPathFollow(m_WanderBoid, Heuristic::Zero, m_Graph,5, 10, 0.1);
	Graph* m_Graph = new Graph();
	Grid* m_Grid = new Grid("grid.png", true);
	KinematicSeek kSeek;
	Flocking* flock = new Flocking(10);
	int SelectedIndex = 1;
	std::vector<Node*> nodeList;

	//Decision Making stuff
	SeekSteeringArrive* seekArrive = new SeekSteeringArrive(m_WanderBoid, 50, 50, 0.1);
	SeekSteeringArrive* seekToBegin = new SeekSteeringArrive(m_WanderBoid, 50, 50, 0.1);
	BasicMotion* basicMotion = new BasicMotion(m_WanderBoid, 5000);
	WanderDynamic* dynamicWander = new WanderDynamic();

	//Decision Tree
	ActionNode* m_WanderActionNode = new ActionNode();
	ActionNode* m_SeekActionNode = new ActionNode();
	DecisionNode* m_DecisionNode = new DecisionNode();
	DecisionTree* m_DecisionTree = new DecisionTree(m_DecisionNode);

	bool IsPlayerNearStart();



	//Other Common Things
	AI* m_EnemyAI = new AI();
	ActionManager* m_WanderAIManager = new ActionManager();
	GameManager* m_GameManager = new GameManager();

	//Actions
	Action* m_WanderAction = new Action(5, 2);
	Action* m_SeekToBeginAction = new Action(5, 2);
	Action* m_SeekAction = new Action(5, 2);
	Action* m_BasicMotionAction = new Action(5, 2);



	//Behavior Tree

	//Action Tasks
	ActionTask* m_WanderTask = new ActionTask(m_WanderAction);
	ActionTask* m_SeekTask = new ActionTask(m_SeekAction);
	ActionTask* m_GoToStartTask = new ActionTask(m_SeekToBeginAction);
	ActionTask* m_BasicMotionTask = new ActionTask(m_BasicMotionAction);

	//Decision Tasks
	BooleanTask* m_CloseDistanceCheckTask = new BooleanTask();
	BooleanTask* m_FarDistanceCheckTask = new BooleanTask();
	BooleanTask* m_BasicMotionCheckTask = new BooleanTask();
	Selector* m_DistanceCheckSelector = new Selector();
	Inverter* m_DistanceCheckInverter = new Inverter();
	Sequencer* m_RootSequencer = new Sequencer();

	//Other things
	BehaviorTree* m_BehaviorTree = new BehaviorTree(m_DistanceCheckInverter);

	//Decision Tree learning
	Entropy entropy;

};
