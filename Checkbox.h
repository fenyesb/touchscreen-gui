#pragma once
#include "Config.h"
#include "Label.h"
#include "Graphics.h"
#include <string>

///Logikai típusú beviteli mező, érintésre az értéke invertálódik.
class Checkbox : public Label
{
protected:
	bool checked;
public:
	Checkbox(int x = 0, int y = 0);
	~Checkbox();

	void SetChecked(bool);
	bool GetChecked() const { return checked; }
	
	int GetWidth() const override { return strlen(text.c_str())*FONT_WIDTH+3*BUTTON_BORDER+ICON_SIZE; }
	int GetHeight() const override { return max(FONT_HEIGHT, ICON_SIZE)+2*BUTTON_BORDER; }
	void Draw(Graphics) const override;
	void Touch() override;
};
