#pragma once
#include "Window.h"

///Ablakok kirajzolása a megfelelő sorrendben és érintések továbbítása a megfelelő ablakhoz.
class WindowManager
{
	std::vector<Window*> wnds;
	bool request_redraw;
	
	void CloseWindowsIfNeeded();
	void Redraw();
	
public:
	void RequestRedraw() { request_redraw = true; }
	void Refresh();
	void AddWindow(Window* wndptr);
	
	void DragEvent(int x, int y, int dx, int dy);
	void TouchEvent(int x, int y);
};

extern WindowManager WM;
