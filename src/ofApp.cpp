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

		DirectedWeightedEdge* d2 = new DirectedWeightedEdge(8, nodeList[1], nodeList[2]);
		m_Graph->AddEdgeToGraph(d2);

		DirectedWeightedEdge* d14 = new DirectedWeightedEdge(8, nodeList[1], nodeList[6]);
		m_Graph->AddEdgeToGraph(d14);

		DirectedWeightedEdge* d3 = new DirectedWeightedEdge(7, nodeList[2], nodeList[3]);
		m_Graph->AddEdgeToGraph(d3);

		DirectedWeightedEdge* d4 = new DirectedWeightedEdge(9, nodeList[3], nodeList[4]);
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
	//pathfollow->AddNewTargetForBoid(nodeList[5]);
	//pathfollow->CreateAndSetPathToFollow();

}

//--------------------------------------------------------------
void ofApp::update(){
	/*switch (SelectedIndex)
	{
	case 1:
		basicMotion->Update();
		break;
	case 2:
		seekArrive->Update();
		break;
	case 3:
		dynamicWander->Update();
		break;
	case 4:
		flock->Update();
		break;
	default:
		basicMotion->Update();
		break;
	}*/
	pathfollow->Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	m_Grid->Draw();
	ofSetColor(255, 0, 0);
	pathfollow->Draw();

	//for(auto x:nodeList)
	//{
	//	ofDrawCircle(x->m_Position, 5);
	//	for (auto connection : m_Graph->GetConnections(x))
	//	{
	//		ofDrawArrow(ofVec3f(x->m_Position), ofVec3f(connection->m_Sink->m_Position));
	//	}
	//}
	
	//switch (SelectedIndex)
	//{
	//case 1:
	//	basicMotion->Draw();
	//	break;
	//case 2:
	//	seekArrive->Draw();
	//	break;
	//case 3:
	//	dynamicWander->Draw();
	//	break;
	//case 4:
	//	flock->Draw();
	//	break;
	//default:
	//	basicMotion->Draw();
	//	break;
	//}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//if (key == 'n' && SelectedIndex == 4)
	//{
	//	flock->SetNextLeader();
	//}
	//else if (key == 'k' && SelectedIndex == 4)
	//{
	//	flock->EnableSecondLeader(true);
	//}
	//else if (key == 'l' && SelectedIndex == 4)
	//{
	//	flock->EnableSecondLeader(false);
	//}
	//else
	//	SelectedIndex = key > 48 && key < 53 ? key - 48 : 0;


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
	//if (SelectedIndex == 2)
	//{
	//	seekArrive->SetPosition(ofVec2f(x, y));
	//}
	//if (SelectedIndex == 4)
	//{
	//	flock->SetLeaderPosition(ofVec2f(x, y));
	//}
	Node* tempNode = m_Grid->GetNodeByPosition(ofVec2f(x, y));

	pathfollow->AddNewTargetForBoid(tempNode);

	//DirectedWeightedEdge* p15 = new DirectedWeightedEdge(2, nodeList[0], tempNode);
	//m_Graph->AddEdgeToGraph(p15);
//	pathfollow->CreateAndSetPathToFollow();
	pathfollow->CreateAndSetPathToFollow(m_Grid, tempNode);
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
