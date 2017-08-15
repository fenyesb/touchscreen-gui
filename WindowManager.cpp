#include "WindowManager.h"
#include "Window.h"
#include "Config.h"
#include "Graphics.h"

WindowManager WM;

void WindowManager::Redraw()
{
	if(!request_redraw)
		return;
	request_redraw = false;
	Graphics gr;
	gr.Color(0, 0, 0);
	gr.Fill();
	for(auto it = wnds.begin(); it != wnds.end(); it++)
	{
		Window* wnd = *it;
		wnd->Render();
	}
}

void WindowManager::AddWindow(Window* wndptr)
{
	wnds.push_back(wndptr);
	wndptr->OnShowWindow();
	RequestRedraw();
}

void WindowManager::CloseWindowsIfNeeded()
{
	for(auto it = wnds.begin(); it != wnds.end();)
	{
		Window* wnd = *it;
		if(wnd->IsClosing())
		{
			delete wnd;
			it = wnds.erase(it);
			RequestRedraw();
		}
		else
		{
			it++;
		}
	}
}

void WindowManager::DragEvent(int x, int y, int dx, int dy)
{
	for(auto it = wnds.rbegin(); it != wnds.rend(); it++)
	{
		Window* wnd = *it;
		if(wnd->WindowDrag(x-wnd->GetX(), y-wnd->GetY(), dx, dy))
			break;
	}
}

void WindowManager::TouchEvent(int x, int y)
{
	for(auto it = wnds.rbegin(); it != wnds.rend(); it++)
	{
		Window* wnd = *it;
		if(wnd->WindowTouch(x - wnd->GetX(), y - wnd->GetY()))
			break;
	}
}

void WindowManager::Refresh()
{
	CloseWindowsIfNeeded();
	Redraw();
}
