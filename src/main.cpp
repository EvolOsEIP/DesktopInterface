#include <gtkmm.h>
#include "Window.hpp"

int main(int ac, char **av)
{
  auto app = Gtk::Application::create(ac, av, "org.evolos.application");
  auto builder = Gtk::Builder::create();

  builder->add_from_file(GLADE_PATH);

  MyWindow *window = nullptr;
  builder->get_widget_derived("window1", window);

  if (!window) {
    std::cerr << "Unable to create the window" << std::endl;
    exit(84);
  }
  app->run(*window);

  delete window;
  return 0;
}

