#pragma once
#include <UTFT.h>
#include "Config.h"

///Az UTFT könyvtár használatát leegyszerűsítő rajzoló osztály. A megadott téglalapon belül rajzol.
class Graphics
{
	int x1 = 0, y1 = 0, x2 = SCREEN_WIDTH, y2 = SCREEN_HEIGHT;
	int r, g, b;
	static UTFT* utft;
	void setborders(int x1, int y1, int x2, int y2);
public:
	Graphics(int x = 0, int y = 0, int w = SCREEN_WIDTH, int h = SCREEN_HEIGHT);
	static void Initalize();
	void Clip(int, int, int, int);
	void Offset(int, int);
	void Text(const char*) const;
	void Fill() const;
	void Border() const;
	void Color(int, int, int);
	void Shrink(int);
	void Icon(const unsigned short* icon_addr) const;
	void Number(int) const;
	
	int GetWidth() const { return x2 - x1 + 1; }
	int GetHeight() const { return y2 - y1 + 1; }
};
