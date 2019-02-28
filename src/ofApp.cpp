#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	Path o_path;

	//Create Nodes
	{
		Node* n1 = new Node(0, ofVec2f(0, 100));
		nodeList.emplace_back(n1);
		Node* n2 = new Node(1, ofVec2f(100, 20));
		nodeList.emplace_back(n2);
		Node* n3 =new Node(2, ofVec2f(200, 20));
		nodeList.emplace_back(n3);
		Node* n4 = new Node(3, ofVec2f(300, 20));
		nodeList.emplace_back(n4);
		Node* n5 = new Node(4, ofVec2f(400, 100));
		nodeList.emplace_back(n5);
		Node* n6 = new Node(5, ofVec2f(300, 200));
		nodeList.emplace_back(n6);
		Node* n7 = new Node(6, ofVec2f(200, 200));
		nodeList.emplace_back(n7);
		Node* n8 = new Node(7, ofVec2f(100, 200));
		nodeList.emplace_back(n8);
		Node* n9 = new Node(8, ofVec2f(200, 100));
		nodeList.emplace_back(n9);
	}

	//Create Edges for Graph
	{
		DirectedWeightedEdge* p1 = new DirectedWeightedEdge(4, nodeList[0], nodeList[1]);
		m_Graph->AddEdgeToGraph(p1);

		DirectedWeightedEdge* p2 = new DirectedWeightedEdge(8, nodeList[1], nodeList[2]);
		m_Graph->AddEdgeToGraph(p2);

		DirectedWeightedEdge* p3 = new DirectedWeightedEdge(7, nodeList[2], nodeList[3]);
		m_Graph->AddEdgeToGraph(p3);

		DirectedWeightedEdge* p4 = new DirectedWeightedEdge(9, nodeList[3], nodeList[4]);
		m_Graph->AddEdgeToGraph(p4);

		DirectedWeightedEdge* p5 = new DirectedWeightedEdge(10, nodeList[4], nodeList[5]);
		m_Graph->AddEdgeToGraph(p5);

		DirectedWeightedEdge* p6 = new DirectedWeightedEdge(2, nodeList[5], nodeList[6]);
		m_Graph->AddEdgeToGraph(p6);

		DirectedWeightedEdge* p7 = new DirectedWeightedEdge(1, nodeList[6], nodeList[7]);
		m_Graph->AddEdgeToGraph(p7);

		DirectedWeightedEdge* p8 = new DirectedWeightedEdge(7, nodeList[8], nodeList[7]);
		m_Graph->AddEdgeToGraph(p8);

		DirectedWeightedEdge* p9 = new DirectedWeightedEdge(2, nodeList[2], nodeList[8]);
		m_Graph->AddEdgeToGraph(p9);

		DirectedWeightedEdge* p10 = new DirectedWeightedEdge(6, nodeList[8], nodeList[6]);
		m_Graph->AddEdgeToGraph(p10);

		DirectedWeightedEdge* p11 = new DirectedWeightedEdge(4, nodeList[5], nodeList[2]);
		m_Graph->AddEdgeToGraph(p11);

		DirectedWeightedEdge* p12 = new DirectedWeightedEdge(14, nodeList[3], nodeList[5]);
		m_Graph->AddEdgeToGraph(p12);

		DirectedWeightedEdge* p13 = new DirectedWeightedEdge(11, nodeList[1], nodeList[7]);
		m_Graph->AddEdgeToGraph(p13);

		DirectedWeightedEdge* p14 = new DirectedWeightedEdge(8, nodeList[7], nodeList[0]);
		m_Graph->AddEdgeToGraph(p14);
	}
	pathfollow->UpdateGraph(m_Graph);
	pathfollow->SetStartNode(nodeList[1]);
	pathfollow->AddNewTargetForBoid(nodeList[5]);
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
	//pathfollow->Draw();
	m_Grid->Draw();
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
	//pathfollow->CreateAndSetPathToFollow();
	pathfollow->CreateAndSetPathToFollow(tempNode);
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
