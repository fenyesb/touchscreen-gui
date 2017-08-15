#pragma once
#include "Label.h"
#include "Config.h"
#include <string>

///Gomb osztály, ami érintésre meghív egy megadott callback függvényt.
class Button : public Label
{
protected:
	///Ezt a függvényt hívja meg érintés esetén.
	void (*callback)(Button*);
public:
	Button(int x = 0, int y = 0);
	virtual ~Button();
	
	int GetWidth() const override { return strlen(text.c_str())*FONT_WIDTH+2*BUTTON_BORDER; }
	int GetHeight() const override { return FONT_HEIGHT+2*BUTTON_BORDER; }
	virtual void SetCallback(void (*f)(Button*));
	void SetText(std::string) override;
	void Draw(Graphics) const override;
	void Touch() override;
};
