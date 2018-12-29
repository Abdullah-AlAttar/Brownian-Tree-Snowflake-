#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    cur = Particle({ofGetWidth() / 2.f, 0.f});
}

//--------------------------------------------------------------
void ofApp::update()
{
    while (!cur.finished() and !cur.intersects(particles))
    {
        cur.update();
    }
        particles.push_back(cur);
        cur = Particle({ofGetWidth() / 2.f, ofRandom(-10.f,10.f)});
    rcnt += 0.1f;
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofTranslate(ofGetWidth() / 2.f, ofGetHeight() / 2.f);
    ofRotateDeg(rcnt);
    ofRotateDeg(30.f);
    for (auto i = 0ul; i < 6ul; ++i)
    {
        ofRotate(60.f);
        cur.draw();
        for (auto &p : particles)
        {
            p.draw();
        }

        ofPushMatrix();
        ofScale(1, -1);
        cur.draw();
        for (auto &p : particles)
        {
            p.draw();
        }
        ofPopMatrix();
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
