#ifndef __RAJOLA_H__
#define __RAJOLA_H__

#include "App.h"

class fpoint {
public:
	float x;
	float y;
public:
	fpoint() {
		x = 0.0f;
		y = 0.0f;
	}
	fpoint(float x, float y) {
		this->x = x;
		this->y = y;
	}
};

class ipoint {
public:
	int x = 0;
	int y = 0;
public:
	ipoint() {
		x = 0;
		y = 0;
	}
	ipoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

class rajola {
public:
	rajola(fpoint screenPosition, ipoint spritePosition) {
		p = screenPosition;
		sp = spritePosition;
		grab = false;
	}

	bool DetectGrab();
	bool Draw();

private:
	fpoint p;	//screen position
	ipoint sp;	//sprite position
	bool grab;
};
#endif