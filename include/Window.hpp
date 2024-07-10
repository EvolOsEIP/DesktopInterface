#pragma once
#include <iostream>
#include <gtkmm.h>


class MyWindow : public Gtk::Window {
  public:
    MyWindow();

  private:
    void on_button_clicked();
    bool on_key_pressed(GdkEventKey *event);
    Gtk::Button m_button;
};

