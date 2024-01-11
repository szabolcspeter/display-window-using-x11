#include <X11/Xlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
  Display* display;

  display = XOpenDisplay(":0");
  if (!display)
  {
    fprintf (stderr, "Cannot connect to X server %s\n", ":0");
    exit(EXIT_FAILURE);
  }
  int screen_num = DefaultScreen(display);
  printf("Default Screen: %d\n", screen_num);

  int screen_width = DisplayWidth(display, screen_num);
  int screen_height = DisplayHeight(display, screen_num);
  printf("Resolution in pixels: %d, %d\n", screen_width, screen_height);

  /*Window root_window = RootWindow(display, screen_num);
  printf("Root Window ID: %d\n", root_window);*/

  unsigned long white_pixel = WhitePixel(display, screen_num);
  printf("White Pixel value: %lu\n", white_pixel);

  unsigned long black_pixel = BlackPixel(display,screen_num);
  printf("Black Pixel value: %lu\n", black_pixel);
  

  XCloseDisplay(display);
  exit(EXIT_SUCCESS);
}
