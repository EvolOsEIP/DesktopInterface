#include "Window.hpp"

MyWindow::MyWindow(BaseObjectType *object, const Glib::RefPtr<Gtk::Builder> &builder) :
  Gtk::ApplicationWindow(object),
  _btn(nullptr),
  _box(nullptr)
{

  // set the window
  set_default_size(800, 600);
  set_title("GTKmm Window Example");


  // button actions
  // mouse event
  this->signal_key_press_event().connect(sigc::mem_fun(*this, &MyWindow::on_key_pressed));

  builder->get_widget("lamorkitue", _btn);
  builder->get_widget("box", _box);

  if (!_btn || !_box) {
    std::cerr << "Can not load elements" << std::endl;
    exit(84);
  }

  Gtk::Widget *parent = _btn->get_parent();
  if (parent)
    _box->remove(*_btn);


  _box->pack_end(*_btn);

  add(*_box);
  show_all();
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
