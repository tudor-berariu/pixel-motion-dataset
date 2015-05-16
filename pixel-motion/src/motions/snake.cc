#include "motions/snake.h"

Snake::Snake(int height, int width, 
              HDirection h_direction, VDirection v_direction,
              double noise)
  : height {height},
    width {width},
    h_direction {h_direction},
    v_direction {v_orientation},
    noise {noise},
    e { r() },
    next_row{0, height},
    next_col{0, width},
    row {next_row(e)},
    col {next_col(e)}
 { }
