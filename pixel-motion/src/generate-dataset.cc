#include <iostream>
#include <thread>
#include <chrono>
#include <cstdio>

#include "motions/spiral.h"

using namespace std;

void print_screen(Screen s) {
  char up_left[] = {(char)0xe2, (char)0x95, (char)0x94, (char)0};
  char up_right[] = {0xe2, 0x95, 0x97, 0};
  char down_left[] = {0xe2, 0x95, 0x9a, 0};
  char down_right[] = {0xe2, 0x95, 0x9d, 0};
  char vertical[] = {0xe2, 0x95, 0x91, 0};
  char horizontal[] = {0xe2, 0x95, 0x90, 0};

  cout << up_left;
  for (size_t c = 0; c < s[0].size(); c++) cout << horizontal;
  cout << up_right << endl;

  for (auto row : s) {
    cout << vertical;
    for (Pixel col : row) cout << col;
    cout << vertical << endl;
  }
  cout << down_left;
  for (size_t c = 0; c < s[0].size(); c++) cout << horizontal;
  cout << down_right << endl;
}

int main(int argc, char * argv[])
{
  Spiral *s = new Spiral(40, 60, 1, 2, 35,
                         Spiral::Direction::Clock, Spiral::Orientation::In,
                         2, 0.0);
  for(int i = 0; i < 1000; i++) {
    print_screen(s->getNextScreen());
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
  return 0;
}
