#pragma once
#include "Config.h"
#include "Control.h"
#include "Graphics.h"

///Szám típusú beviteli mező.
class NumericInput : public Control
{
protected:
	int num;
	int minvalue, maxvalue;
public:
	NumericInput(int x = 0, int y = 0);
	~NumericInput();

	void SetRange(int minvalue, int maxvalue);
	int GetValue() { return num; }
	
	int GetWidth() const override { return NUMBER_LENGTH*FONT_WIDTH+3*BUTTON_BORDER+ICON_SIZE; }
	int GetHeight() const override { return max(FONT_HEIGHT, ICON_SIZE)+2*BUTTON_BORDER; }
	void Draw(Graphics) const override;
	void Drag(int dx, int dy) override;
};
