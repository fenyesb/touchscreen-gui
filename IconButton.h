#pragma once
#include "Button.h"
#include "Config.h"

///Gomb egy kisméretű képpel.
class IconButton : public Button
{
protected:
	const unsigned short* icon_addr;
public:
	IconButton(int x = 0, int y = 0);
	
	int GetWidth() const override { return 3*BUTTON_BORDER+strlen(text.c_str())*FONT_WIDTH+ICON_SIZE; }
	int GetHeight() const override { return max(ICON_SIZE, FONT_HEIGHT)+2*BUTTON_BORDER; }
	virtual void SetIcon(const unsigned short* icon_addr);
	void Draw(Graphics) const override;
};
