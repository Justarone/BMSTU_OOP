#include "main_window.h"

mainWindow::mainWindow(const char *filename)
{
    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();
    builder->add_from_file(filename);

    builder->get_widget("appWindow", appWindow);
    //main_window->set_title("Лабораторная №3.");
    //Gdk::RGBA color, color2;
    //color.set_rgba(0.95, 0.95, 0.95);
    //color2.set_rgba(0., 0.15, 0.3);
    //main_window->override_background_color(color);

    builder->get_widget("sceneRadio", sceneRadio);
    builder->get_widget("modelRadio", modelRadio);
    builder->get_widget("cameraRadio", cameraRadio);
    modelRadio->join_group(*sceneRadio);
    cameraRadio->join_group(*sceneRadio);

    builder->get_widget("sceneWindow", sceneWindow);
    sceneWindow->signal_draw().connect(sigc::mem_fun(*this, &mainWindow::on_draw));

    builder->get_widget("prevButton", prevButton);
    builder->get_widget("nextButton", nextButton);

    prevButton->signal_clicked().connect(sigc::bind<const char *>(sigc::mem_fun(*this,
                    &mainWindow::callbackFunction), "prevButton"));
    nextButton->signal_clicked().connect(sigc::bind<const char *>(sigc::mem_fun(*this,
                    &mainWindow::callbackFunction), "nextButton"));

    builder->get_widget("xEntry", xEntry);
    builder->get_widget("yEntry", yEntry);
    builder->get_widget("zEntry", zEntry);
    xEntry->get_buffer()->set_text("0");
    yEntry->get_buffer()->set_text("0");
    zEntry->get_buffer()->set_text("0");

    builder->get_widget("moveButton", moveButton);
    builder->get_widget("rotateButton", rotateButton);
    builder->get_widget("scaleButton", scaleButton);
    moveButton->signal_clicked().connect(sigc::bind<const char *>(sigc::mem_fun(*this,
                    &mainWindow::callbackFunction), "moveButton"));
    rotateButton->signal_clicked().connect(sigc::bind<const char *>(sigc::mem_fun(*this,
                    &mainWindow::callbackFunction), "rotateButton"));
    scaleButton->signal_clicked().connect(sigc::bind<const char *>(sigc::mem_fun(*this,
                    &mainWindow::callbackFunction), "scaleButton"));

    builder->get_widget("addButton", addButton);
    builder->get_widget("removeButton", removeButton);
    addButton->signal_clicked().connect(sigc::bind<const char *>(sigc::mem_fun(*this,
                    &mainWindow::callbackFunction), "addButton"));
    removeButton->signal_clicked().connect(sigc::bind<const char *>(sigc::mem_fun(*this,
                    &mainWindow::callbackFunction), "removeButton"));

    builder->get_widget("loadButton", loadButton);
    builder->get_widget("loadEntry", loadEntry);
    loadButton->signal_clicked().connect(sigc::bind<const char *>(sigc::mem_fun(*this,
                    &mainWindow::callbackFunction), "loadButton"));

    //any_widget->override_background_color(color2);
    //any_widget->override_color(color);
}

void mainWindow::callbackFunction(const char *str) {
    auto cr = sceneWindow->get_window()->create_cairo_context();
    //cr->set_source_rgb(1, 1, 1);
    //cr->paint();
    //cr->stroke();

    cr->set_source_rgb(0., 0., 0.);
    //cr->set_line_width(5);
    cr->move_to(100, 200);
    cr->line_to(700, 200);
    cr->stroke();

    std::cout << str << std::endl;
    //std::cout << sceneRadio->get_active() << modelRadio->get_active() 
    //<< cameraRadio->get_active() << std::endl;
}

Gtk::Window * mainWindow::get_window() {
    return appWindow;
}


//err_t mainWindow::read_entry(double &value, const Gtk::Entry &entry) {
    //std::string str = static_cast<std::string>(entry.get_buffer()->get_text());
    //try
    //{
        //value = std::stod(str);
    //} 
    //catch (const std::invalid_argument& ia) {
        //std::cerr << "Invalid argument: " << ia.what() << '\n';
        //return READ_ERROR;
    //}
    //return OK;
//}
// connect: drawing_area->signal_draw().connect(sigc::mem_fun(*this, &myApplication::on_draw));
bool mainWindow::on_draw(Cairo::RefPtr<Cairo::Context> const& cr) {
    cr->set_source_rgb(1, 1, 1);
    cr->paint();
    cr->stroke();

    cr->set_source_rgb(0., 0, 0);
    cr->set_line_width(3);
    cr->move_to(100, 100);
    cr->line_to(800, 800);
    cr->stroke();
    std::cout << "Print some text\n";
    return true;
}
