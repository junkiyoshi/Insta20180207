#pragma once
#include "ofMain.h"

class RecuRect
{
public:
	RecuRect();
	RecuRect(int level, ofVec2f location, float size, bool origin = false);
	~RecuRect();

	void update();
	void draw();
private:
	int level;
	ofVec2f location;
	float size;
	int type;
	bool origin;
	ofColor color;
	float alpha;
	float alpha_vec;

	std::vector<RecuRect> rects;
};