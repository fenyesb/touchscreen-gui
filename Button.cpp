#include "Button.h"
#include "Config.h"
#include <string>

Button::Button(int x, int y) : Label(x, y), callback(NULL)
{
}

Button::~Button()
{
}

void Button::Draw(Graphics graphics) const
{
	graphics.Color(0, 70, 255);
	graphics.Fill();
	graphics.Shrink(BUTTON_BORDER);
	graphics.Color(255, 255, 255);
	graphics.Text(text.c_str());
}

void Button::SetCallback(void (*f)(Button*))
{
	callback = f;
}

void Button::SetText(std::string s)
{
	text = s;
}

void Button::Touch()
{
	if(callback != NULL)
		callback(this);
}
