#include <gtkmm.h>
#include "Window.hpp"

int main(int ac, char **av)
{
  auto app = Gtk::Application::create(ac, av, "org.evolos.application");

  MyWindow window;
  return app->run(window);
}

