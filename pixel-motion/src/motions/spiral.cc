#include "motions/spiral.h"

Spiral::Spiral(int height, int width, Direction direction, Orientation orientation,
               double noise)
  : height {height},
    width {width},
    direction {direction},
    orientation {orientation},
    noise {noise},
    e { r() },
    next_row{0, height},
    next_col{0, width},
    row {next_row(e)},
    col {next_col(e)}
 { }

Spiral::Spiral(int height, int width, Direction direction, Orientation orientation)
  : Spiral(height, width, direction, orientation, 1.0) { }

Spiral::Screen Spiral::getNextScreen() {
  Screen screen(height, vector<Pixel>(width));
  for (vector<Pixel>& r : screen) {
    fill(r.begin(), r.end(), Pixel::getBackground());
  }
  if((row + col) < width) {
    if(row < col) {
      col++;
    } else {
      row--;
    }
  } else {
    if(row < col) {
      row++;
    } else {
      col--;
    }
  }
  screen[row][col] = Pixel::getRed();
  return screen;
}

