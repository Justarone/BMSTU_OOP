#include "../include/task_manager.h"


err_t task_manager(const event_t &event, event_data_t &data)
{
    err_t rc = OK;
    static figure_t main_figure = init_figure();

    switch (event.command)
    {
        case LOAD_DATA:
            rc = read_from_file(main_figure, data.load_data);
            break;
        case MOVE:
            rc = move_command(main_figure, event.code, data.trans_data);
            break;
        case SCALE:
            rc = scale_command(main_figure, event.code, data.value[SCALE]);
            break;
        case ROTATE:
            rc = rotate_command(main_figure, event.code, data.value[ROTATE]);
            break;
        case UPDATE_PROJECTION:
            rc = get_projection(*data.projection, main_figure);
            break;
        case DRAW:
            rc = draw_figure(data.area, *data.projection);
            break;
        case QUIT:
            destroy_figure(main_figure);
            destroy_projection(*data.projection);
            break;
        default:
            rc = COMMAND_ERROR;
    }
    return rc;
}


event_t init_event(const char command, const char code)
{
    event_t event;
    event.command = command;
    event.code = code;

    return event;
}

event_data_t init_data(const char *const filename, Gtk::DrawingArea *const area,
        double *const value, fpr_t *const projection)
{
    event_data_t data;

    data.load_data = init_load_data(filename);
    data.draw_data = init_draw_data(area);
    data.trans_data = init_trans_data(value);
    data.prj_data = init_prj_data(projection);

    return data;
}
