#include <iostream>
#include <gtkmm.h>

class MyWindow : public Gtk::Window {
  public:
    MyWindow();

  private:
    void on_button_clicked();
    Gtk::Button m_button;
};

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

int main(int ac, char **av)
{
  auto app = Gtk::Application::create(ac, av, "org.evolos.application");

  MyWindow window;
  return app->run(window);
}

