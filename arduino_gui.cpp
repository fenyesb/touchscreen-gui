// Made by: Balázs Fényes (f.balazs96@gmail.com)
// GUI for touchscreens (https://github.com/fenyesb/touchscreen-gui)

#include <StandardCplusplus.h>
#include <serstream>
#include <avr/pgmspace.h>
#include <UTFT.h>
#include <URTouch.h>
#include <SD.h>
#include "Window.h"
#include "WindowManager.h"
#include "TouchManager.h"
#include "MainWindow.h"

using namespace std;

UTFT myGLCD(SSD1289, 38, 39, 40, 41);
UTFT* Graphics::utft = &myGLCD;

URTouch myTouch(6, 5, 4, 3, 2);
URTouch* TouchManager::urtouch = &myTouch;

void setup()
{
	Serial.begin(9600);
	
	Graphics::Initalize();
	TouchManager::Initalize();
	
	pinMode(BACKLIGHT, OUTPUT);
	analogWrite(BACKLIGHT, 255);
	
	MainWindow* mainwnd = new MainWindow(30, 30, 250, 200);
	WM.AddWindow(mainwnd);
}

void loop()
{
	TM.ReadEvents();
	if(TM.IsDragEvent())
	{
		int x, y, dx, dy;
		TM.GetDragEvent(&x, &y, &dx, &dy);
#ifdef DEBUG
		myGLCD.setColor(0, 255, 0);
		myGLCD.drawLine(x, y, x+dx, y+dy);
#endif
		WM.DragEvent(x, y, dx, dy);
	}
	else if(TM.IsTouchEvent())
	{
		int x, y;
		TM.GetTouchEvent(&x, &y);
#ifdef DEBUG
		myGLCD.setColor(255, 255, 0);
		myGLCD.drawCircle (x, y, 5);
#endif
		WM.TouchEvent(x, y);
	}
	WM.Refresh();
	delay(50);
}
