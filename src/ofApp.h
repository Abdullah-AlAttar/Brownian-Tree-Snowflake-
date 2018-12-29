#pragma once

#include "ofMain.h"

struct Particle 
{
	ofVec2f pos;
	float rad = 3;
	ofVec3f color{ofRandom(0,200), 0, ofRandom(0,200)};
	Particle() = default;
	Particle(ofVec2f _pos)
	{
		this->pos = _pos;
	}
	void update()
	{
		this->pos.x -=3;
		this->pos.y += ofRandom(-3.f,3.f);
		// auto angle = this->pos.angle()
	}
	void draw()
	{
		ofSetColor(color.x,color.y,color.z);
		// ofFill();
		ofDrawCircle(this->pos,rad);
	}
	bool finished()
	{
		return this->pos.x < 0.f;
	}
	bool intersects(std::vector<Particle>& others)
	{
		for(auto & p :others)
		{
			auto d = ofDist(p.pos.x,p.pos.y,this->pos.x,this->pos.y);
			if(d < this->rad*2)
			{
				return true;
			}
		}
		return false;
	}
};
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
		
		Particle cur;
		std::vector<Particle> particles;
		float rcnt = 0.f;
};
