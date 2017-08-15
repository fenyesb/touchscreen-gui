#include "Config.h"
#include "IconButton.h"
#include "Graphics.h"

IconButton::IconButton(int x, int y) : Button(x,y), icon_addr(0)
{
}

void IconButton::SetIcon(const unsigned short* icon_addr)
{
	this->icon_addr = icon_addr;
}

void IconButton::Draw(Graphics graphics) const
{
	graphics.Color(0, 70, 255);
	graphics.Fill();
	graphics.Shrink(BUTTON_BORDER);
	graphics.Color(50, 50, 50);
	graphics.Fill();
	if(icon_addr!=0)
		graphics.Icon(icon_addr);
	graphics.Offset(ICON_SIZE+BUTTON_BORDER,0);
	graphics.Color(255,255,255);
	graphics.Text(text.c_str());
}
