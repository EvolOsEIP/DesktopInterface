#pragma once
#include <iostream>
#include <gtkmm.h>

#define CSS_PROVIDER "../css/styles.css"
#define GLADE_PATH "../resources/glade/Window.glade"

class MyWindow : public Gtk::ApplicationWindow {
  public:
    MyWindow(BaseObjectType *object, const Glib::RefPtr<Gtk::Builder> &builder);
    virtual ~MyWindow();

  protected:
    void on_button_clicked();
    bool on_key_pressed(GdkEventKey *event);

    Gtk::Box *_box;
    Gtk::Button *_btn;

};

