#include "Control.h"
#include "Config.h"

Control::Control(int x, int y) : x(x), y(y), parent(nullptr)
{
}

Control::~Control()
{
}

bool Control::Contains(int x, int y) const
{
	return x >= 0 && y >= 0 && x < GetWidth() && y < GetHeight();
}

void Control::Draw(Graphics graphics) const
{
	graphics.Color(30,30,30);
	graphics.Fill();
}

void Control::Touch()
{
}

void Control::Drag(int x, int y)
{
}
