#ifndef _COMMAND_HANDLERS_H_
#define _COMMAND_HANDLERS_H_

#include "app_codes.h"
#include "constants.h"
#include "transform_figure.h"
#include "projection_funcs.h"
#include "draw_function.h"
#include "io_figure.h"
#include "event_data.h"

err_t move_command(figure_t &main_figure, const trans_data_t &value);
err_t rotate_command(figure_t &main_figure, const trans_data_t &value);
err_t scale_command(figure_t &main_figure, const trans_data_t &value);
err_t get_projection(prj_data_t &data, const figure_t &main_figure);
void destroy_all(figure_t &main_figure, prj_data_t &data);
err_t read_from_file(figure_t &figure, load_data_t &data);
err_t draw_figure(draw_data_t &draw_data, const prj_data_t &prj_data);

#endif
