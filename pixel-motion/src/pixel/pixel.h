#ifndef PIXEL_H
#define PIXEL_H

#include <vector>
#include <iostream>

using namespace std;

struct Pixel;

using Screen = vector<vector<Pixel>>;

ostream& operator<<(ostream&, const Pixel&);

struct Pixel {
  char r;
  char g;
  char b;

  Pixel();
  Pixel(char, char, char);
  
  static Pixel getRed();
  static Pixel getBackground();

  friend ostream& operator<<(ostream&, const Pixel&);
};

#endif
