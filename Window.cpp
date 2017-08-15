#include "Window.h"
#include "Control.h"
#include "Graphics.h"
#include "Config.h"
#include "WindowManager.h"

Window::Window(int x, int y, int w, int h)
{
	SetX(x);
	SetY(y);
	SetWidth(w);
	SetHeight(h);
}

void Window::AddChild(Control* ctlptr)
{
	ctlptr->SetParent(this);
	children.push_back(ctlptr);
}

void Window::AddDialog(Window* wndptr)
{
	wndptr->SetX(x + w / 2 - wndptr->GetWidth() / 2);
	wndptr->SetY(y + h / 2 - wndptr->GetHeight() / 2);
	wndptr->SetParent(this);
	active = false;
}

void Window::Render() const
{
	Graphics graphics(x, y, w, h);
	if(active)
	{
		graphics.Color(150, 150, 150);
	}
	else
	{
		graphics.Color(75, 75, 75);
	}
	graphics.Fill();
	graphics.Offset(WINDOW_BORDER, WINDOW_BORDER);
	graphics.Color(255, 255, 255);
	graphics.Text(GetTitle().c_str());
	Graphics titlebtn(graphics);
	titlebtn.Offset(w - 3 * FONT_WIDTH - 2 * WINDOW_BORDER,0);
	titlebtn.Color(255, 0, 0);
	titlebtn.Text(" X ");
	graphics.Clip(0, WINDOW_BORDER+FONT_HEIGHT, w - WINDOW_BORDER * 2, h - WINDOW_BORDER * 3 - FONT_HEIGHT);
	if(active)
	{
		graphics.Color(50, 50, 50);
	}
	else
	{
		graphics.Color(10, 10, 10);
	}
	graphics.Fill();
	for(auto it = children.begin(); it != children.end(); it++)
	{
		Control* child = *it;
		Graphics gr_clip(graphics);
		gr_clip.Clip(child->GetX(), child->GetY(), child->GetWidth(), child->GetHeight());
		child->Draw(gr_clip);
	}
}

bool Window::Contains(int x, int y) const
{
	return x >= 0 && y >= 0 && x < w && y < h;
}

bool Window::WindowTouch(int x, int y)
{
	if(!active||IsClosing()||!Contains(x,y))
		return false;
	if(y<=WINDOW_BORDER*2+FONT_HEIGHT&&x>=w-3*FONT_WIDTH-WINDOW_BORDER)
	{
		Close();
		return true;
	}
	x -= WINDOW_BORDER;
	y -= 2*WINDOW_BORDER + FONT_HEIGHT;
	for(auto it = children.begin(); it != children.end(); it++)
	{
		Control* child = *it;
		if(child->Contains(x-child->GetX(), y-child->GetY()))
		{
			child->Touch();
			break;
		}
	}
	return true;
}

bool Window::WindowDrag(int x, int y, int dx, int dy)
{
	if(!active||IsClosing()||!Contains(x,y))
		return false;
	if(y <= WINDOW_BORDER * 2 + FONT_HEIGHT)
	{
		SetX(GetX() + dx);
		SetY(GetY() + dy);
		WM.RequestRedraw();
	}
	else
	{
		x -= WINDOW_BORDER;
		y -= 2 * WINDOW_BORDER + FONT_HEIGHT;
		for(auto it = children.begin(); it != children.end(); it++)
		{
			Control* child = *it;
			if(child->Contains(x-child->GetX(), y-child->GetY()))
			{
				child->Drag(dx, dy);
				break;
			}
		}
	}
	return true;
}

void Window::SetX(int x)
{
	this->x = max(0, min(x, SCREEN_WIDTH - w));
	WM.RequestRedraw();
}

void Window::SetY(int y)
{
	this->y = max(0, min(y, SCREEN_HEIGHT - h));
	WM.RequestRedraw();
}

void Window::SetWidth(int w)
{
	this->w = max(0, min(w, SCREEN_WIDTH - x));
	WM.RequestRedraw();
}

void Window::SetHeight(int h)
{
	this->h = max(0, min(h, SCREEN_HEIGHT - y));
	WM.RequestRedraw();
}

Window::~Window()
{
	if(parent!=nullptr)
	{
		parent->SetActive(true);
	}
	for(auto it = children.begin(); it != children.end(); it++)
	{
		Control* child = *it;
		delete child;
	}
}
