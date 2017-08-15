#pragma once
#include <string>
#include "Control.h"
#include "Graphics.h"	

///Ablak ősosztály
class Window
{
protected:
	int x, y;
	int w, h;
	std::string title;
	bool active = true;
	Window* parent = nullptr;
	bool request_close = false;
	
public:
	std::vector<Control*> children;
	
	Window(int x = 0, int y = 0, int w = 0, int h = 0);
	virtual ~Window();
	
	void AddChild(Control*);
	void AddDialog(Window*);
	
	virtual void Render() const;
	virtual bool WindowTouch(int x, int y);
	virtual bool WindowDrag(int x, int y, int dx, int dy);
	
	int GetX() const { return x; }
	int GetY() const { return y; }
	int GetWidth() const { return w; }
	int GetHeight() const { return h; }
	
	void SetX(int x);
	void SetY(int y);
	void SetWidth(int w);
	void SetHeight(int h);
	
	void Close() { request_close = true; active = false; }
	bool IsClosing() { return request_close; }
	
	std::string GetTitle() const { return title; }
	void SetTitle(std::string title) { this->title = title; }
	
	bool Contains(int x, int y) const;
	
	void SetActive(bool active) { this->active = active; }
	void SetParent(Window* parent) {this->parent = parent; }
	
	///A WM.AddWindow() hívja
	virtual void OnShowWindow() {};
};
