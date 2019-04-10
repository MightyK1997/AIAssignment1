#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	Path o_path;

	//Create Nodes
	{
		Node* n1 = new Node(0, ofVec2f(100, 100));
		nodeList.emplace_back(n1);
		Node* n2 = new Node(1, ofVec2f(300, 50));
		nodeList.emplace_back(n2);
		Node* n3 =new Node(2, ofVec2f(400, 100));
		nodeList.emplace_back(n3);
		Node* n4 = new Node(3, ofVec2f(400, 300));
		nodeList.emplace_back(n4);
		Node* n5 = new Node(4, ofVec2f(375, 250));
		nodeList.emplace_back(n5);
		Node* n6 = new Node(5, ofVec2f(350, 350));
		nodeList.emplace_back(n6);
		Node* n7 = new Node(6, ofVec2f(300, 200));
		nodeList.emplace_back(n7);
		Node* n8 = new Node(7, ofVec2f(200, 250));
		nodeList.emplace_back(n8);
		Node* n9 = new Node(8, ofVec2f(250, 350));
		nodeList.emplace_back(n9);
		Node* n10 = new Node(9, ofVec2f(100, 300));
		nodeList.emplace_back(n10);
		Node* n11 = new Node(10, ofVec2f(150, 200));
		nodeList.emplace_back(n11);
	}

	//Create Edges for Graph
	{
		DirectedWeightedEdge* d1 = new DirectedWeightedEdge(7, nodeList[0], nodeList[1]);
		m_Graph->AddEdgeToGraph(d1);

		DirectedWeightedEdge* d2 = new DirectedWeightedEdge(2, nodeList[1], nodeList[2]);
		m_Graph->AddEdgeToGraph(d2);

		DirectedWeightedEdge* d14 = new DirectedWeightedEdge(25, nodeList[1], nodeList[6]);
		m_Graph->AddEdgeToGraph(d14);

		DirectedWeightedEdge* d3 = new DirectedWeightedEdge(2, nodeList[2], nodeList[3]);
		m_Graph->AddEdgeToGraph(d3);

		DirectedWeightedEdge* d4 = new DirectedWeightedEdge(2, nodeList[3], nodeList[4]);
		m_Graph->AddEdgeToGraph(d4);

		DirectedWeightedEdge* d5 = new DirectedWeightedEdge(10, nodeList[4], nodeList[5]);
		m_Graph->AddEdgeToGraph(d5);

		DirectedWeightedEdge* d6 = new DirectedWeightedEdge(2, nodeList[5], nodeList[6]);
		m_Graph->AddEdgeToGraph(d6);

		DirectedWeightedEdge* d16 = new DirectedWeightedEdge(2, nodeList[6], nodeList[5]);
		m_Graph->AddEdgeToGraph(d16);

		DirectedWeightedEdge* d7 = new DirectedWeightedEdge(1, nodeList[4], nodeList[6]);
		m_Graph->AddEdgeToGraph(d7);

		DirectedWeightedEdge* d8 = new DirectedWeightedEdge(7, nodeList[6], nodeList[7]);
		m_Graph->AddEdgeToGraph(d8);

		DirectedWeightedEdge* d15 = new DirectedWeightedEdge(7, nodeList[6], nodeList[1]);
		m_Graph->AddEdgeToGraph(d15);

		DirectedWeightedEdge* d17 = new DirectedWeightedEdge(7, nodeList[7], nodeList[6]);
		m_Graph->AddEdgeToGraph(d17);

		DirectedWeightedEdge* d9 = new DirectedWeightedEdge(2, nodeList[7], nodeList[8]);
		m_Graph->AddEdgeToGraph(d9);

		DirectedWeightedEdge* d10 = new DirectedWeightedEdge(6, nodeList[8], nodeList[9]);
		m_Graph->AddEdgeToGraph(d10);

		DirectedWeightedEdge* d20 = new DirectedWeightedEdge(6, nodeList[7], nodeList[9]);
		m_Graph->AddEdgeToGraph(d20);

		DirectedWeightedEdge* d11 = new DirectedWeightedEdge(4, nodeList[9], nodeList[10]);
		m_Graph->AddEdgeToGraph(d11);

		DirectedWeightedEdge* d12 = new DirectedWeightedEdge(14, nodeList[7], nodeList[10]);
		m_Graph->AddEdgeToGraph(d12);

		DirectedWeightedEdge* d18 = new DirectedWeightedEdge(14, nodeList[10], nodeList[7]);
		m_Graph->AddEdgeToGraph(d18);

		DirectedWeightedEdge* d13 = new DirectedWeightedEdge(14, nodeList[10], nodeList[0]);
		m_Graph->AddEdgeToGraph(d13);

		DirectedWeightedEdge* d19 = new DirectedWeightedEdge(14, nodeList[0], nodeList[10]);
		m_Graph->AddEdgeToGraph(d19);
	}
	//pathfollow->UpdateGraph(m_Graph);
	//pathfollow->SetStartNode(nodeList[0]);
	//pathfollow->AddNewTargetForBoid(nodeList[6]);
	//pathfollow->CreateAndSetPathToFollow();
	dynamicWander->SetBoid(m_WanderBoid);
	m_GameManager->SetPlayer(m_Player);
	m_GameManager->SetWanderNPC(m_WanderBoid);

	std::function<void(void)> temp = std::bind(&WanderDynamic::Update, dynamicWander);
	m_WanderAction->SetAction(temp);
	std::function<bool()> checkFunction = std::bind(&WanderDynamic::HasArrived, dynamicWander);
	m_WanderAction->SetCompleteFunction(checkFunction);
	temp = std::bind(&SeekSteeringArrive::Update, seekArrive);
	checkFunction = std::bind(&SeekSteeringArrive::HasArrived, seekArrive);
	m_SeekAction->SetAction(temp);
	m_SeekAction->SetCompleteFunction(checkFunction);
	m_SeekAction->SetCanInterrupt(true);
	m_WanderActionNode->SetAction(m_WanderAction);
	m_SeekActionNode->SetAction(m_SeekAction);
	m_WanderAIManager->Start();
	std::function<bool()> temp2 = std::bind(&GameManager::CheckIfPlayerIsInRange, m_GameManager);
	m_DecisionNode->SetDecisionFunction(temp2);
	m_DecisionNode->SetNodes(m_SeekActionNode, m_WanderActionNode);
	m_WanderAI->m_AIActionManager = m_WanderAIManager;
	m_WanderAI->m_DecisionMakingBehavior = m_DecisionTree;

}

//--------------------------------------------------------------
void ofApp::update(){
	seekArrive->SetPosition(m_Player->GetBoidKinematicData().Position);
	m_WanderAI->Update(0.01f);
	//pathfollow->Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	/*switch (SelectedIndex)
	{
	case 1:
	case 2:
		for (auto x : nodeList)
		{
			ofDrawCircle(x->m_Position, 5);
			for (auto connection : m_Graph->GetConnections(x))
			{
				ofDrawArrow(ofVec3f(x->m_Position), ofVec3f(connection->m_Sink->m_Position));
			}
		}
		break;
	case 3:
		ofSetBackgroundColor(0, 0, 0);
		m_Grid->Draw();
		ofSetColor(255, 0, 0);
	default:
		break;
	}
	pathfollow->Draw();*/
	dynamicWander->Draw();
	m_Player->Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	SelectedIndex = key > 48 && key < 53 ? key - 48 : 0;
	pathfollow->ResetPath();
	switch (SelectedIndex)
	{
	//Dijkstra
	case 1:
		pathfollow->MovementInput(true);
		pathfollow->UpdateAStarHeuristic(Heuristic::Zero);
		pathfollow->SetStartNode(nodeList[0]);
		pathfollow->AddNewTargetForBoid(nodeList[6]);
		pathfollow->CreateAndSetPathToFollow();
		break;
	//AStar + Manhattan
	case 2:
		pathfollow->MovementInput(true);
		pathfollow->UpdateAStarHeuristic(Heuristic::Manhattan);
		pathfollow->SetStartNode(nodeList[0]);
		pathfollow->AddNewTargetForBoid(nodeList[6]);
		pathfollow->CreateAndSetPathToFollow();
		break;
	case 3:
		pathfollow->MovementInput(false);
		break;
	default:
		break;
	}
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
void ofApp::mousePressed(int x, int y, int button)
{
	m_Player->SetBoidPosition(ofVec2f(x, y));
	//if (SelectedIndex != 3)return;
	//Node* tempNode = m_Grid->GetNodeByPosition(ofVec2f(x, y));
	//pathfollow->MovementInput(true);
	//pathfollow->AddNewTargetForBoid(tempNode);
	//pathfollow->CreateAndSetPathToFollow(m_Grid, tempNode);
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
