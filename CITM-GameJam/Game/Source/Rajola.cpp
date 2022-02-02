#include "Rajola.h"

bool rajola::DetectGrab(iPoint mouse) {
	if (mouse.x > p.x && mouse.x < (p.x + c) && mouse.y > p.y && mouse.y < (p.y + c)) {
		//Grabbed
		grab = true;
		grabPosition.x = mouse.x - p.x;
		grabPosition.y = mouse.y - p.y;
		return true;
	}
	return false;
}

void rajola::setGrab(bool b) {
	grab = b;
}

bool rajola::Grabbed() {
	return grab;
}