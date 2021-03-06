#ifndef __RAJOLA_H__
#define __RAJOLA_H__

#include "App.h"
#include "Render.h"
#include "Point.h"

#define WH 125
#define CWH 40.0f
#define FilesRaj 30
#define ColumnesRaj 24
#define RajolaGlobalScale 0.6f

class rajola {
public:
	rajola(iPoint screenPosition, iPoint spritePosition, float angle = 0.0f, float scale = 0.0f) {
		p = screenPosition;
		sp = spritePosition;
		a = angle;
		s = scale * RajolaGlobalScale;
		grab = false;
		grabPosition = iPoint(0, 0);
		c = CWH * scale * RajolaGlobalScale;	//30 = normal width height
	}

	bool DetectGrab(iPoint mouse);	//if it collides, grab = true, and returns true
	bool DetectCollision(iPoint mouse);

	void setGrab(bool b);
	bool Grabbed();

public:
	iPoint p;	//screen position
	iPoint sp;	//sprite position
	float a;	//angle
	float s;	//scale
	bool grab;
	iPoint grabPosition;	//The coordinates in which the object is grabbed
	float c;	//collider width and height / 2 (divided by 2)
};
#endif