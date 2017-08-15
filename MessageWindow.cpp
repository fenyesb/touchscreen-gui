#include "MessageWindow.h"
#include "Label.h"
#include "Config.h"

MessageWindow::MessageWindow(std::string msg, int x, int y) : Window(x, y, 0, 0)
{
	Label* msglabel = new Label(0, 0);
	msglabel->SetText(msg);
	AddChild(msglabel);
	SetWidth(msglabel->GetWidth() + 2 * WINDOW_BORDER);
	SetHeight(msglabel->GetHeight() + 3 * WINDOW_BORDER + FONT_HEIGHT);
}

MessageWindow::~MessageWindow()
{ //az msglabel a ~Window -ban törlődik
}
