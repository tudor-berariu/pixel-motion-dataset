#include "pixel/pixel.h"

Pixel::Pixel() : r{' '}, g{' '}, b{' '} { }

Pixel::Pixel(char r, char g, char b) : r{r}, g{g}, b{b} { }

Pixel Pixel::getRed() {
  Pixel red('X', 'X', 'X');
  red.rf = 0.91;
  red.gf = 0.09;
  red.bf = 0.09;
  return red;
}

Pixel Pixel::getNoise() {
  Pixel blue('*', '*', '*');
  blue.rf = 0.09;
  blue.gf = 0.09;
  blue.bf = 0.91;
  return blue;
}

Pixel Pixel::getBackground() {
  Pixel back;
  back.rf = 0.11;
  back.gf = 0.11;
  back.bf = 0.11;
  return back;
}

ostream& operator<<(ostream& s, const Pixel& p) {
  s << p.r;
  return s;
}
