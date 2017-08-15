#pragma once

#include <URTouch.h>

///Érintések kezelése, kattintás és húzás megkülönböztetése.
class TouchManager
{
	long last_touch_ms = -9999;

	int drag_start_x = -1, drag_start_y=-1;
	int drag_end_x = -1, drag_end_y = -1;
	int has_event = true;
	static URTouch* urtouch;
	
	bool is_touch_valid(int x, int y) const;
	float drag_distance() const;
public:
	
	static void Initalize();
	
	void ReadEvents();
	
	bool IsDragEvent() const;
	void GetDragEvent(int* x, int* y, int* dx, int* dy);
	
	bool IsTouchEvent() const;
	void GetTouchEvent(int* x, int* y);
};

extern TouchManager TM;
