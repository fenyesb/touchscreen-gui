#include "Checkbox.h"
#include "icons/icon_checkbox_off.h"
#include "icons/icon_checkbox_on.h"
#include "Graphics.h"
#include "Config.h"
#include "WindowManager.h"

Checkbox::Checkbox(int x, int y) : Label(x, y), checked(false)
{
}

Checkbox::~Checkbox()
{
}

void Checkbox::SetChecked(bool checked)
{
	this->checked = checked;
	WM.RequestRedraw();
}

void Checkbox::Touch()
{
	checked = !checked;
	WM.RequestRedraw();
}

void Checkbox::Draw(Graphics graphics) const
{
	graphics.Color(0, 70, 255);
	graphics.Fill();
	graphics.Shrink(BUTTON_BORDER);
	graphics.Color(50, 50, 50);
	graphics.Fill();
	graphics.Icon(checked ? icon_checkbox_on : icon_checkbox_off);
	graphics.Offset(ICON_SIZE+BUTTON_BORDER,0);
	graphics.Color(255,255,255);
	graphics.Text(text.c_str());
}
