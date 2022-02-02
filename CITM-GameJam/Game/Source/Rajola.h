#ifndef __RAJOLA_H__
#define __RAJOLA_H__

#include "App.h"
#include "Render.h"
#include "Point.h"

class rajola {
public:
	rajola(fPoint screenPosition, iPoint spritePosition, float angle = 0.0f, float scale = 0.0f) {
		p = screenPosition;
		sp = spritePosition;
		a = angle;
		s = scale;
		grab = false;
		grabPosition = fPoint(0, 0);
		c = 30.0f * scale;	//30 = normal width height
	}

	bool DetectGrab(iPoint mouse);	//if it collides, grab = true, and returns true

	void setGrab(bool b);
	bool Grabbed();
private:
	fPoint p;	//screen position
	iPoint sp;	//sprite position
	float a;	//angle
	float s;	//scale
	bool grab;
	fPoint grabPosition;	//The coordinates in which the object is grabbed
	float c;	//collider width and height
};
#endif