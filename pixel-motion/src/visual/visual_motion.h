#ifndef VISUAL_MOTION_H
#define VISUAL_MOTION_H

#include <gtkmm/drawingarea.h>
#include "motions/spiral.h"

class VisualMotion : public Gtk::DrawingArea
{
public:
  VisualMotion();
  virtual ~VisualMotion();

protected:
  //Override default signal handler:
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

  bool on_timeout();

  Spiral *s;
};

#endif
