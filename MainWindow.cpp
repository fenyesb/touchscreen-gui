#include "MainWindow.h"
#include "Label.h"
#include "Control.h"
#include "Button.h"
#include "Graphics.h"
#include "FileWindow.h"
#include "MessageWindow.h"
#include "Checkbox.h"
#include "NumericInput.h"
#include "WindowManager.h"

void open_dialog(Button* btn)
{
	Window* dialogwnd = new MessageWindow("Hello World!", 0, 0);
	btn->GetParent()->AddDialog(dialogwnd);
	WM.AddWindow(dialogwnd);
}

void open_sd(Button* btn)
{
	FileWindow* filebrowser = new FileWindow("/", 50, 50, 200, 150);
	btn->GetParent()->AddDialog(filebrowser);
	WM.AddWindow(filebrowser);
}

void reset(Button* btn)
{
	void (*f)(void) = 0;
	f();
}

MainWindow::MainWindow(int x, int y, int w, int h) : Window(x, y, w, h)
{
	SetTitle("Control test");

	Label* mylabel = new Label(10, 10);
	mylabel->SetText("Hello Label");
	AddChild(mylabel);

	NumericInput* numinput = new NumericInput(10, 30);
	numinput->SetRange(-100, 100);
	AddChild(numinput);
	
	Button* mybutton = new Button(10, 60);
	mybutton->SetText("Open dialog");
	mybutton->SetCallback(open_dialog);
	AddChild(mybutton);

	Button* filesbutton = new Button(10, 90);
	filesbutton->SetText("Open SD card");
	filesbutton->SetCallback(open_sd);
	AddChild(filesbutton);
	
	Checkbox* checkbox = new Checkbox(10, 120);
	checkbox->SetText("Checkbox");
	AddChild(checkbox);
	
	Button* resetbutton = new Button(10, 150);
	resetbutton->SetText("Reset");
	resetbutton->SetCallback(reset);
	AddChild(resetbutton);
}

void MainWindow::OnShowWindow()
{
	pinMode(SD_CS, OUTPUT);
	if(!SD.begin(SD_CS))
	{
		Window* errorwnd = new MessageWindow("Hibas SD kartya!");
		AddDialog(errorwnd);
		WM.AddWindow(errorwnd);
	}
}

MainWindow::~MainWindow()
{ //a destruktorok a ~Window -ban hívódnak
}
