#include "pixel/pixel.h"

Pixel::Pixel() : r{' '}, g{' '}, b{' '} { }

Pixel::Pixel(char r, char g, char b) : r{r}, g{g}, b{b} { }

Pixel Pixel::getRed() {
  Pixel red('X', ' ', ' ');
  return red;
}

Pixel Pixel::getBackground() {
  Pixel back;
  return back;
}

ostream& operator<<(ostream& s, const Pixel& p) {
  s << p.r;
  return s;
}
