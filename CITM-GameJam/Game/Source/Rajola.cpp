#include "Rajola.h"

bool rajola::DetectGrab(iPoint mouse) {

	if (mouse.x > (p.x + (WH/2) - c) && mouse.x < (p.x + (WH / 2) + c) && mouse.y >(p.y + (WH / 2) - c) && mouse.y < (p.y + (WH / 2) + c)) {
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