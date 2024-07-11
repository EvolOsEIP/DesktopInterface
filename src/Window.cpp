#include "Window.hpp"

MyWindow::MyWindow() :
  _box_one_btn("Box 1"),
  _box_two_btn("Box 2"),
  _container(Gtk::ORIENTATION_VERTICAL),
  _box(Gtk::ORIENTATION_HORIZONTAL),
  _box_bis(Gtk::ORIENTATION_HORIZONTAL)
{

  // set the window
  set_default_size(800, 600);
  set_title("GTKmm Window Example");


  // button actions
  _box_one_btn.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
  _box_two_btn.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));

  // mouse event
  this->signal_key_press_event().connect(sigc::mem_fun(*this, &MyWindow::on_key_pressed));


  // box management
  _box.pack_start(_box_one_btn);
  _box_bis.pack_start(_box_two_btn);
  _container.pack_start(_box);
  _container.pack_start(_box_bis);

  add(_container);

  // css part

  auto cssProvider = Gtk::CssProvider::create();
  cssProvider->load_from_path(CSS_PROVIDER);

  auto screen = Gdk::Screen::get_default();
  Gtk::StyleContext::add_provider_for_screen(screen, cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);


  _box_two_btn.set_name("blue-box");
  _box_one_btn.set_name("red-box");

  // display
  _container.show_all();
}

void MyWindow::on_button_clicked()
{
  std::cout << "Button clicked !" << std::endl;
}

bool MyWindow::on_key_pressed(GdkEventKey *event)
{
  char letter = event->keyval;

  std::cout << "Key pressed: " << letter << std::endl;
  if (letter == 'q')
    exit(0);
  return true;
}

MyWindow::~MyWindow()
{
}
