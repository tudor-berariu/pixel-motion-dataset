#include <iostream>
#include <thread>
#include <chrono>
#include <cstdio>

#include "motions/spiral.h"

using namespace std;

int main(int argc, char * argv[])
{
  Spiral *s = new Spiral(30, 30, Spiral::Direction::Trig, Spiral::Orientation::In);
  for(int i = 0; i < 100; i++) {
    Spiral::Screen t = s->getNextScreen();
    cout << (char)201;
    for (int c = 0; c < (int)t.size(); c++) cout << (char)205;
    cout << (char)187;
    cout << endl;
    for (auto row : t) {
      cout << (char)186;
      for (Pixel col : row) {
        cout << col.r;
      }
      cout << (char)186;
      cout << endl;
    }
    cout << (char)200;
    for (int c = 0; c < (int)t.size(); c++) cout << (char)205;
    cout << (char)216;
    cout << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
