#pragma once
#include "Control.h"
#include "Config.h"
#include <string>

///Szöveget megjelenítő vezérlő.
class Label : public Control
{
protected:
	std::string text;
public:
	Label(int x = 0, int y = 0);
	~Label();
	
	virtual void SetText(std::string);
	virtual std::string GetText() const { return text; }
	void Draw(Graphics) const override;
	void Touch() override;
	int GetWidth() const override { return strlen(text.c_str()) * FONT_WIDTH; }
	int GetHeight() const override { return FONT_HEIGHT; }
};
