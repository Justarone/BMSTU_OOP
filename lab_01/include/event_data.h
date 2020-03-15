#ifndef _SUB_EVENTS_H_
#define _SUB_EVENTS_H_

#include "figure.h"
#include <gtkmm.h>

struct load_data
{
    const char* filename;
};
using load_data_t = struct load_data;


struct draw_data
{
    Gtk::DrawingArea *area;
};
using draw_data_t = struct draw_data;


struct transform_data
{
    double value;
};
using trans_data_t = struct transform_data;


struct projection_data
{
    fpr_t *projection;
};
using prj_data_t = projection_data;

struct event_data
{
    load_data_t load_data;
    draw_data_t draw_data;
    trans_data_t trans_data;
    prj_data_t prj_data;
};
using event_data_t = struct event_data;

event_data_t init_data();
load_data_t init_load_data(const char *filename = NULL);
draw_data_t init_draw_data(Gtk::DrawingArea *area = NULL);
trans_data_t init_trans_data(const double value = 0);
prj_data_t init_prj_data(fpr_t *projection = NULL);
void add_prj_data(event_data_t &event_data, fpr_t * projection = NULL);
void add_trans_data(event_data_t &event_data, const double value = 0);
void add_draw_data(event_data_t &event_data, Gtk::DrawingArea * area = NULL);
void add_load_data(event_data_t &event_data, const char *filename = NULL);

#endif