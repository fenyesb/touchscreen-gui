#include "FileWindow.h"
#include "Button.h"
#include "Config.h"
#include "IconButton.h"
#include "icons/icon_folder.h"
#include "icons/icon_file.h"
#include "WindowManager.h"
#include "MessageWindow.h"
#include <SD.h>
#include <string>

void fwnd_itemclick(Button* btn)
{
	FileWindow* fwndptr = (FileWindow*)(btn->GetParent());
	if(btn->GetText().back()=='/')
		fwndptr->OpenSubFolder(btn->GetText().substr(0,btn->GetText().length()-1));
}

void fwnd_openparent(Button* btn)
{
	FileWindow* fwndptr = (FileWindow*)(btn->GetParent());
	fwndptr->OpenParentFolder();
}

void FileWindow::OpenParentFolder()
{
	if(title == "/")
		return;
	title = title.substr(0,title.rfind("/"));
	if(title=="")
		title = "/";
	root.close();
	root = SD.open(title.c_str());
	createbuttons();
}

void FileWindow::OpenSubFolder(std::string location)
{
	root.rewindDirectory();
	while(true)
	{
		File entry = root.openNextFile();
		if(!entry)
			break;
		if(entry.name()==location)
		{
			title += (title == "/" ? "" : "/");
			title += entry.name();
			entry.close();
			root.close();
			root = SD.open(title.c_str());
			createbuttons();
			break;
		}
		entry.close();
	}
}

void FileWindow::createbuttons()
{
	deletebuttons();
	children.clear();
	int n_items = 0;
	root.rewindDirectory();
	while(true)
	{
		File entry = root.openNextFile();
		if(!entry)
			break;
		n_items++;
		entry.close();
	}
	root.rewindDirectory();
	IconButton* listitem = new IconButton(0, 0);
	listitem->SetText("..");
	listitem->SetCallback(fwnd_openparent);
	AddChild(listitem);
	int y = listitem->GetHeight();
	for(int i = 0; i < n_items; i++)
	{
		File entry = root.openNextFile();
		listitem = new IconButton(0, y);
		if(entry.isDirectory())
		{
			listitem->SetText(std::string(entry.name())+"/");
			listitem->SetIcon(icon_folder);
		}else{
			listitem->SetText(entry.name());
			listitem->SetIcon(icon_file);
		}
		listitem->SetCallback(fwnd_itemclick);
		AddChild(listitem);
		y += listitem->GetHeight();
		entry.close();
	}
	WM.RequestRedraw();
}

FileWindow::FileWindow(std::string path, int x, int y, int w, int h) : Window(x, y, w, h)
{
	SetTitle(path);
	root = SD.open(path.c_str());
	createbuttons();
}

void FileWindow::OnShowWindow()
{
	if(!root)
	{
		Window* errwnd = new MessageWindow("Hibas utvonal!");
		AddDialog(errwnd);
		WM.AddWindow(errwnd);
	}
}

FileWindow::~FileWindow()
{
	if(!root)
	{
		root.close();
	}
}

void FileWindow::deletebuttons()
{
	for(auto it = children.begin(); it != children.end(); it++)
	{
		Control* child = *it;
		delete child;
	}
}
