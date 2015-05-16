#include "motions/spiral.h"

#include "visual/visual_motion.h"

#include <gtkmm/application.h>
#include <gtkmm/window.h>

using namespace std;

int main(int argc, char** argv)
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "visualize.spiral");

   Gtk::Window win;
   win.set_title("Spiral");

   VisualMotion vm;
   win.add(vm);
   vm.show();

   return app->run(win);
}
