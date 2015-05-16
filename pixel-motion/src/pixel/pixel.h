#ifndef PIXEL_H
#define PIXEL_H

struct Pixel {
  char r;
  char g;
  char b;

  Pixel();
  Pixel(char, char, char);
  
  static Pixel getRed();
  static Pixel getBackground();
};

#endif
