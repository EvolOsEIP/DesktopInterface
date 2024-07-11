#pragma once
#include <iostream>
#include <gtkmm.h>

#define CSS_PROVIDER "../css/styles.css"

class MyWindow : public Gtk::Window {
  public:
    MyWindow();
    ~MyWindow();

  private:
    void on_button_clicked();
    bool on_key_pressed(GdkEventKey *event);
    Gtk::Box _box;
    Gtk::Box _box_bis;

    Gtk::Box _container;
    Gtk::Button _box_one_btn;
    Gtk::Button _box_two_btn;

};

