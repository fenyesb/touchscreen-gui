#pragma once

#include <vector>
#include <UTFT.h>
#include "Graphics.h"

class Window;

///Vezérlő alaposztály, nem példányosítható.
class Control
{
protected:
	int x, y;
	Window* parent;
public:
	Control(int x = 0, int y = 0);
	virtual ~Control();
	
	virtual bool Contains(int x, int y) const;
	virtual void Draw(Graphics) const;
	virtual void Touch();
	virtual void Drag(int dx, int dy);
	
	void SetX(int x) { this->x = x; }
	int GetX() const { return x; }
	void SetY(int y) { this->y = y; }
	int GetY() const { return y; }
	
	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;
	
	Window* GetParent() const { return parent; }
	void SetParent(Window* parent) { this->parent = parent; }
};
