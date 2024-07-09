#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <unistd.h>
#include <iostream>

int main(void)
{
  Display *display;
  Window window;
  XEvent event;
  int screen = 0;

  display = XOpenDisplay(NULL);
  if (!display) {
    std::cerr << "Unable to open X display" << std::endl;
    return 84;
  }

  screen = DefaultScreen(display);
  window = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 800, 600, 1, BlackPixel(display, screen), WhitePixel(display, screen));
  XSelectInput(display, window, ExposureMask | KeyPressMask | ButtonPressMask);
  XMapWindow(display, window);

  while (true) {
    XNextEvent(display, &event);
    if (event.type == Expose) {
      XFillRectangle(display, window, DefaultGC(display, screen), 20, 20, 10, 10);
    } else if (event.type == KeyPress)   {
      char buf[128] = {0};
      KeySym keysym;
      int len = XLookupString(&event.xkey, buf, sizeof(buf), &keysym, NULL);
      if (len > 0) {
        std::cout << "You pressed the " << buf << " key" << std::endl;
        if (buf[0] == 'q') {
          break;
        }
      }
    } else if (event.type == ButtonPress) {
      std::cout << "You pressed a mouse button" << std::endl;
    }
  }
  XCloseDisplay(display);
}
