#include "TouchManager.h"
#include "Config.h"
#include <UTFT.h>

TouchManager TM;
#ifdef DEBUG
extern UTFT myGLCD;
#endif

bool TouchManager::is_touch_valid(int x, int y) const
{
	return x >= 0 && y >= 0 && x < SCREEN_WIDTH && y < SCREEN_HEIGHT;
}

float TouchManager::drag_distance() const
{
	return hypot(drag_end_x - drag_start_x, drag_end_y - drag_start_y);
}

void TouchManager::Initalize()
{
	urtouch->InitTouch();
	urtouch->setPrecision(PREC_HI);
}

void TouchManager::ReadEvents()
{
	int x, y;
	while (urtouch->dataAvailable() == true)
	{
		urtouch->read();
		x = urtouch->getX();
		y = urtouch->getY();
		if (is_touch_valid(x, y))
		{
			has_event = true;
			drag_end_x = x;
			drag_end_y = y;
			long touch_ms = millis();
			if(touch_ms - last_touch_ms >= TOUCH_TIMEOUT)
			{
				drag_start_x = x;
				drag_start_y = y;
#ifdef DEBUG
				myGLCD.setColor(255,0,0);
				myGLCD.drawCircle (drag_end_x, drag_end_y, 5);
#endif
			}
			last_touch_ms = touch_ms;
		}
	}
}

bool TouchManager::IsDragEvent() const
{
	return has_event && drag_distance() >= DRAG_DISTANCE_THRESHOLD;
}
void TouchManager::GetDragEvent(int* x, int* y, int* dx, int* dy)
{
	has_event = false;
	*x = drag_start_x;
	*y = drag_start_y;
	*dx = drag_end_x-drag_start_x;
	*dy = drag_end_y-drag_start_y;
}

bool TouchManager::IsTouchEvent() const
{
	return has_event && drag_distance() < DRAG_DISTANCE_THRESHOLD;
}
void TouchManager::GetTouchEvent(int* x, int* y)
{
	has_event = false;
	*x = drag_start_x;
	*y = drag_start_y;
}
