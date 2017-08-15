#pragma once

#include "Window.h"
#include "Label.h"

///Üzenet kiírása egy Label segítségével.
class MessageWindow : public Window
{
public:
	MessageWindow(std::string msg, int x = 0, int y = 0);
	~MessageWindow();
};
