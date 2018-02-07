#include "RecuRect.h"

RecuRect::RecuRect() {

}

RecuRect::RecuRect(int level, ofVec2f location, float size, bool origin) {

	this->type = ofRandom(100);

	if (origin || (level > 0 && this->type > 20)) {

		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x - size / 4, location.y - size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x - size / 4, location.y + size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x + size / 4, location.y - size / 4), size / 2));
		this->rects.push_back(RecuRect(level - 1, ofVec2f(location.x + size / 4, location.y + size / 4), size / 2));
	}

	this->level = level;
	this->location = location;
	this->size = size;
	this->origin = origin;
	this->color.setHsb(ofRandom(255), 230, 230);
	this->alpha = 0;
	this->alpha_vec = ofRandom(2, 5);
}

RecuRect::~RecuRect() {

}

void RecuRect::update() {

	for (int i = 0; i < this->rects.size(); i++) {

		this->rects[i].update();
	}

	this->alpha += this->alpha_vec;
}

void RecuRect::draw() {

	for (int i = 0; i < this->rects.size(); i++) {

		this->rects[i].draw();
	}
	
	if (this->type > 60) {

		ofNoFill();
		ofSetColor(255, this->alpha);
		ofDrawRectangle(this->location, size, size);
	}

	if (this->type < 3) {

		ofFill();
		ofSetColor(this->color, this->alpha);
		ofDrawRectangle(this->location, size, size);
	}

}
