#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <iostream>
#include <gtkmm-3.0/gtkmm.h>

#include "figure.h"
#include "constants.h"
#include "app_codes.h"
#include "io_figure.h"
#include "task_manager.h"
#include "event_data.h"

// Button groups' sizes.
enum { MOVE_SIZE = 6, SCALE_SIZE = 2, ROTATE_SIZE = 6, ENTRY_SIZE = 3 };


class myApplication
{
    public:
        myApplication(const char *const filename);
        Gtk::Window *get_window();
    protected:
        Gtk::Window *main_window;
        Gtk::DrawingArea *drawing_area;
        Gtk::Button *move_btns[MOVE_SIZE];
        Gtk::Button *scale_btns[SCALE_SIZE];
        Gtk::Button *rotate_btns[ROTATE_SIZE];
        Gtk::Entry *entry_arr[ENTRY_SIZE];

        err_t read_entry(double &value, const Gtk::Entry &entry);
        void on_button_clicked(const char command, const char code);
};

#endif
