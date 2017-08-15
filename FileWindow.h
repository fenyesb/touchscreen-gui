#pragma once

#include "Window.h"
#include <SD.h>
#include <string>
#include "Button.h"
#include "IconButton.h"

///Fájlkezelő ablak, támogatja az almappákat.
class FileWindow : public Window
{
protected:
	void createbuttons();
	void deletebuttons();
	File root;
public:
	///A megadott útvonalat nyitja meg.
	FileWindow(std::string path = "/", int x = 0, int y = 0, int w = 0, int h = 0);
	~FileWindow();
	void OnShowWindow() override;
	void OpenSubFolder(std::string);
	void OpenParentFolder();
};
