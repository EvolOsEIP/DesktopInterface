#pragma once
#include <iostream>
#include <gtkmm.h>


class MyWindow : public Gtk::Window {
  public:
    MyWindow();

  private:
    void on_button_clicked();
    Gtk::Button m_button;
};

