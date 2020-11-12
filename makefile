bresenham: bresenham.o driver.o display.o
	g++ -o bresenham bresenham.o driver.o display.o -l glui -l glut -l GLU -l GL -l Xi -l Xmu -l Xext -l X11 -l m

bresenham.o: bresenham.cpp bresenham.h
	g++ -c bresenham.cpp

display.o: display.cpp display.h bresenham.h
	g++ -c display.cpp

driver.o: driver.cpp bresenham.h display.h
	g++ -c driver.cpp
