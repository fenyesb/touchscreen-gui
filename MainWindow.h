#pragma once

#include "Window.h"

///Ez az ablak jelenik meg a program indulásakor.
class MainWindow : public Window
{
public:
	MainWindow(int x = 0, int y = 0, int w = 0, int h = 0);
	~MainWindow();
	void OnShowWindow() override;
};
