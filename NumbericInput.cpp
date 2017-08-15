#include "NumericInput.h"
#include "Control.h"
#include "icons/icon_arrows.h"
#include "Graphics.h"
#include "Config.h"
#include "WindowManager.h"

NumericInput::NumericInput(int x, int y) : Control(x, y), num(0)
{
}

NumericInput::~NumericInput()
{
}

void NumericInput::SetRange(int minvalue, int maxvalue)
{
	this->minvalue = minvalue;
	this->maxvalue = maxvalue;
	num = constrain(num, minvalue, maxvalue);
	WM.RequestRedraw();
}

void NumericInput::Drag(int dx, int dy)
{
	int delta_num = abs(dy) / SCROLL_SPEED;
	num += (dy > 0 ? -1 : 1) * delta_num;
	WM.RequestRedraw();
}

void NumericInput::Draw(Graphics graphics) const
{
	graphics.Color(0, 70, 255);
	graphics.Fill();
	graphics.Shrink(BUTTON_BORDER);
	graphics.Color(50, 50, 50);
	graphics.Fill();
	graphics.Icon(icon_arrows);
	graphics.Offset(ICON_SIZE + BUTTON_BORDER, 0);
	graphics.Color(255, 255, 255);
	graphics.Number(num);
}
