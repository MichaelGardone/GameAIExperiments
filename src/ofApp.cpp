#include "ofApp.h"

#include "frontend/scenes/kseeker_scene/KSeekerScene.h"
#include "frontend/scenes/kfleer_scene/KFleerScene.h"
#include "frontend/scenes/karrive_scene/KArriveScene.h"
#include "frontend/scenes/kwander_scene/KWanderScene.h"
#include "frontend/scenes/dynamic_scene/DynamicScene.h"
#include "frontend/scenes/face_scene/FaceScene.h"
#include "frontend/scenes/dwander_scene/DWanderScene.h"
#include "frontend/scenes/eae6900_scene/EAE6900Scene.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);

	scene = new Scenes::EAE6900Scene();

	scene->setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	scene->update(ofGetLastFrameTime());
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);

	scene->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	scene->key_pressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	scene->key_released(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	scene->mouse_pressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	scene->mouse_released(x, y, button);
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
