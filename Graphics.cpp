#include "Graphics.h"
#include "Config.h"

using namespace std;

extern uint8_t SmallFont[];

Graphics::Graphics(int x, int y, int w, int h) : r(255), g(255), b(255)
{
	setborders(x, y, x + w - 1, y + h - 1);
}

void Graphics::Initalize()
{
	utft->InitLCD(LANDSCAPE);
	utft->setFont(SmallFont);
	utft->clrScr();
}

void Graphics::setborders(int x1, int y1, int x2, int y2)
{
	this->x1 = constrain(constrain(x1, this->x1, this->x2), 0, SCREEN_WIDTH-1);
	this->y1 = constrain(constrain(y1, this->y1, this->y2), 0, SCREEN_HEIGHT-1);
	this->x2 = constrain(constrain(x2, this->x1, this->x2), 0, SCREEN_WIDTH-1);
	this->y2 = constrain(constrain(y2, this->y1, this->y2), 0, SCREEN_HEIGHT-1);
}

void Graphics::Offset(int x, int y)
{
	setborders(this->x1 + x, this->y1 + y, x2, y2);
}

void Graphics::Clip(int x, int y, int w, int h)
{
	setborders(this->x1 + x, this->y1 + y, this->x1 + x + w - 1, this->y1 + y + h - 1);
}

void Graphics::Text(const char* s) const
{
	if(strlen(s) * FONT_WIDTH > GetWidth() || FONT_HEIGHT > GetHeight())
		return;
	utft->setColor(r, g, b);
	utft->print(s, x1, y1);
}
	
void Graphics::Fill() const
{
	utft->setColor(r, g, b);
	utft->fillRect(x1, y1, x2, y2);
}

void Graphics::Border() const
{
	utft->setColor(r, g, b);
	utft->drawRect(x1, y1, x2, y2);
}

void Graphics::Color(int r, int g, int b)
{
	this->r = r & 0xFF;
	this->g = g & 0xFF;
	this->b = b & 0xFF;
}

void Graphics::Icon(const unsigned short* icon_addr) const
{
	if(ICON_SIZE > GetWidth() || ICON_SIZE > GetHeight())
		return;
	utft->drawBitmap(x1, y1, ICON_SIZE, ICON_SIZE, icon_addr, 1);
}

void Graphics::Shrink(int amt)
{
	setborders(x1 + amt, y1 + amt, x2 - amt, y2 - amt);
}

void Graphics::Number(int num) const
{
	if(NUMBER_LENGTH * FONT_WIDTH > GetWidth() || FONT_HEIGHT > GetHeight())
		return;
	utft->setColor(r, g, b);
	utft->printNumI(num, x1, y1, NUMBER_LENGTH, ' ');
}
