#include "Input.h"
#include <Windows.h>

bool isEvent(unsigned char event)
{
	//gets the key state of a given pressed key
	return GetAsyncKeyState(event);
}
