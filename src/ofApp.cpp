#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	pathfollow->CreateGraph(1000, 1000);
	pathfollow->AddNewTargetForBoid(0, 0);
	pathfollow->CreateAndSetPathToFollow();
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
	pathfollow->Draw();
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
	pathfollow->AddNewTargetForBoid(x, y);
	pathfollow->CreateAndSetPathToFollow();
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
