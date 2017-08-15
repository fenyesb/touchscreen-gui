# touchscreen-gui
Graphical user interface library for embedded systems (i.e. Arduino) with multi-window support and a few implemented controls (buttons, labels, ...) for touchscreens.

# Features
* Window-handling: modal window (dialog), titlebar, decorative chrome, close button, z-ordering, dragging the window is contstrained within the screen
* Controls: button, checkbox, button with icon, label, numerical input is available, others can be implemented easily
* Events (touch, drag) go to the correct window and control

# Bugs
* There is no double-buffering functionality. If a redraw is requested, every window will be redrawn completely.

# Building
You will probably need the following libraries:
* *UTFT* drawing library - http://www.rinkydinkelectronics.com/library.php?id=51
* *URTouch* touch handling library - http://www.rinkydinkelectronics.com/library.php?
id=92
* *arduino-mk* for building the project (you can also use a preferred IDE) - https://github.com/sudar/Arduino-Makefile
* *SdFat* if you need to access the memory card - https://github.com/greiman/SdFat
* *Standard C++ for Arduino* for C++11 support - https://github.com/maniacbug/StandardCplusplus/
Modify the Makefile for your board and then compile with the run.sh script.
