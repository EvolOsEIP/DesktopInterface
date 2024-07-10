#include "Window.hpp"

MyWindow::MyWindow() : m_button("Click me") {
  set_default_size(800, 600);
  set_title("GTKmm Window Example");

  m_button.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));

  add(m_button);
  m_button.show();
}

void MyWindow::on_button_clicked() {
  std::cout << "Button clicked !" << std::endl;
}

