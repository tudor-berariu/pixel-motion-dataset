#include <ctime>
#include <cmath>
#include <iostream>

#include <cairomm/context.h>
#include <glibmm/main.h>

#include "visual/visual_motion.h"

VisualMotion::VisualMotion()
{
  s = new Spiral(100, 100, 1, 2, 35,
                 Spiral::Direction::Clock, Spiral::Orientation::Out,
                 5, 0.1);
  Glib::signal_timeout().connect( sigc::mem_fun(*this, &VisualMotion::on_timeout), 100);

#ifndef GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
  //Connect the signal handler if it isn't already a virtual method override:
  signal_draw().connect(sigc::mem_fun(*this, &VisualMotion::on_draw), false);
#endif //GLIBMM_DEFAULT_SIGNAL_HANDLERS_ENABLED
}

VisualMotion::~VisualMotion()
{
}

bool VisualMotion::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
  const int height = allocation.get_height();

  const Screen t = s->getNextScreen();
  

  // scale to unit square and translate (0, 0) to be (0.5, 0.5), i.e.
  // the center of the window
  cr->scale(width, height);
  
  for (int r = 0; r < t.size(); r++) {
    for (int c = 0; c < t[r].size(); c++) {
      cr->save();
      cr->set_line_width (0.2);
      cr->set_source_rgb (t[r][c].rf, t[r][c].gf, t[r][c].bf);
      cr->rectangle((double)r / (double)t.size(), (double)c / (double)t[0].size(),
                    (double)(r+1) / (double)t.size(), (double)(c+1) / (double)t[0].size());
      cr->fill();
      cr->stroke();
      cr->restore();
      cr->save();
    }
  }
  /*
  // draw a little dot in the middle
  cr->arc(0, 0, m_line_width / 3.0, 0, 2 * M_PI);
  cr->fill();
  */
  return true;
}


bool VisualMotion::on_timeout()
{
    // force our program to redraw the entire clock.
    Glib::RefPtr<Gdk::Window> win = get_window();
    if (win)
    {
        Gdk::Rectangle r(0, 0, get_allocation().get_width(),
                get_allocation().get_height());
        win->invalidate_rect(r, false);
    }
    return true;
}
