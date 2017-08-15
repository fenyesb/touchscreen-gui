#include "Label.h"
#include "Config.h"
#include <string>

Label::Label(int x, int y) : Control(x, y)
{
}

Label::~Label()
{
}

void Label::SetText(std::string s)
{
	text = s;
}

void Label::Draw(Graphics graphics) const
{
	graphics.Color(255,255,255);
	graphics.Text(text.c_str());
}

void Label::Touch()
{
}
