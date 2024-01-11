#include <X11/Xlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  Display* display;
  XEvent event;
  //int win_x, win_y;
  unsigned int win_border_width = 2;
  char* msg = "Hello, World!";

  display = XOpenDisplay(":0");
  if (!display)
  {
    fprintf (stderr, "Cannot connect to X server %s\n", ":0");
    exit(EXIT_FAILURE);
  }
  int screen_num = DefaultScreen(display);
  /*win_x = win_y = 0;
  int win_width = DisplayWidth(display, screen_num) / 3;
  int win_height = DisplayHeight(display, screen_num) / 3;
  Window win = XCreateSimpleWindow(display,
                                   RootWindow(display, screen_num),
                                   win_x, win_y,
                                   win_width, win_height,
                                   win_border_width, BlackPixel(display, screen_num),
                                   WhitePixel(display, screen_num));*/

  Window win = XCreateSimpleWindow(display,
                                   RootWindow(display, screen_num),
                                   10, 10,
                                   500, 500,
                                   win_border_width, BlackPixel(display, screen_num),
                                   WhitePixel(display, screen_num));

  XSelectInput(display, win, ExposureMask | KeyPressMask);
  XMapWindow(display, win);

  while (1)
  {
    XNextEvent(display, &event);
    if (event.type == Expose)
    {
      XFillRectangle(display, win, DefaultGC(display, screen_num), 20, 20, 10, 10);
      XDrawString(display, win, DefaultGC(display, screen_num),10, 50, msg, strlen(msg));
    }
    if (event.type == KeyPress)
      break;
  }

  XCloseDisplay(display);
  exit(EXIT_SUCCESS);
}
