// generated by Fast Light User Interface Designer (fluid) version 1.0302

#include "LispCAD.h"
#include <iostream>

void add_line(cl_object x, cl_object y, cl_object x2, cl_object y2) {
  ShapePoint a(ecl_to_double(x), ecl_to_double(y));
  ShapePoint b(ecl_to_double(x2), ecl_to_double(y2));
  Shape temp;
  temp = Shape::shape_make_line(a, b, 255, 255, 255);
  canvas->drawing_ptr->add_shape(temp);
  canvas->redraw();
}

void add_circle(cl_object x, cl_object y, cl_object radius) {
  ShapePoint a(ecl_to_double(x), ecl_to_double(y));
  Shape temp;
  temp = Shape::shape_make_circle(a, ecl_to_double(radius), 255, 255, 255);
  canvas->drawing_ptr->add_shape(temp);
  canvas->redraw();
}

void test_CB(Fl_Widget* w, void* p) {
  std::cout << "test_CB called!" << std::endl;
}

void commandline_CB_wrapper(Fl_Widget* w, void* p) {
  CommandLine::call_back(w, p);
}

cl_object get_int() {
  return CommandLine::get_input(CommandLine::mode::GET_INT);
}

void canvas_click(Fl_Widget* w, void* p) {
  std::string temp = mini_buffer->value();
  temp += std::to_string(Fl::event_x());
  mini_buffer->value("Puck you sir!");
}

Fl_Double_Window *main_window=(Fl_Double_Window *)0;

CADCanvas *canvas=(CADCanvas *)0;

Fl_Text_Display *echo_area=(Fl_Text_Display *)0;

CommandLine *mini_buffer=(CommandLine *)0;

Fl_Menu_Bar *menu_bar=(Fl_Menu_Bar *)0;

static void cb_file_quit_item(Fl_Menu_*, void*) {
  exit(0);
}

Fl_Menu_Item menu_menu_bar[] = {
 {"File", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"New", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Save", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Save As", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"Quit", 0,  (Fl_Callback*)cb_file_quit_item, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Edit", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Lisp", 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 0},
 {"Refresh Scripts", 0,  0, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {"REPL", 0,  0, (void*)(0), 0, FL_NORMAL_LABEL, 0, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};

Fl_Slider *pan_across=(Fl_Slider *)0;

Fl_Slider *pan_vert=(Fl_Slider *)0;

int main(int argc, char **argv) {
  cl_boot(argc, argv);
  atexit(cl_shutdown);
  std::string loadpath="(load \"System/SYSTEM Scripts/Setup.lisp\")";
  cl_safe_eval(c_string_to_object(loadpath.c_str()), Cnil, Cnil);
  { main_window = new Fl_Double_Window(800, 630, "LispCAD");
    main_window->box(FL_UP_BOX);
    { canvas = new CADCanvas(0, 33, 780, 482, "CADCanvas");
      canvas->box(FL_FLAT_BOX);
      canvas->color(FL_FOREGROUND_COLOR);
      canvas->selection_color(FL_BACKGROUND_COLOR);
      canvas->labeltype(FL_NORMAL_LABEL);
      canvas->labelfont(0);
      canvas->labelsize(14);
      canvas->labelcolor(FL_FOREGROUND_COLOR);
      canvas->callback((Fl_Callback*)canvas_click);
      canvas->align(Fl_Align(FL_ALIGN_CENTER));
      canvas->when(FL_WHEN_ENTER_KEY_ALWAYS);
      Fl_Group::current()->resizable(canvas);
    } // CADCanvas* canvas
    { echo_area = new Fl_Text_Display(5, 535, 790, 43);
      echo_area->box(FL_FLAT_BOX);
      echo_area->color(FL_LIGHT2);
      echo_area->textcolor((Fl_Color)36);
      echo_area->buffer(new Fl_Text_Buffer);
      echo_area->scrollbar_width(12);
      echo_area->wrap_mode(Fl_Text_Display::WRAP_AT_BOUNDS, 80);
    } // Fl_Text_Display* echo_area
    { mini_buffer = new CommandLine(5, 580, 790, 25);
      mini_buffer->box(FL_THIN_DOWN_BOX);
      mini_buffer->color(FL_BACKGROUND2_COLOR);
      mini_buffer->selection_color((Fl_Color)94);
      mini_buffer->labeltype(FL_NORMAL_LABEL);
      mini_buffer->labelfont(0);
      mini_buffer->labelsize(14);
      mini_buffer->labelcolor(FL_FOREGROUND_COLOR);
      mini_buffer->textfont(4);
      mini_buffer->callback((Fl_Callback*)commandline_CB_wrapper);
      mini_buffer->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      mini_buffer->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // CommandLine* mini_buffer
    { menu_bar = new Fl_Menu_Bar(0, 0, 800, 31);
      menu_bar->color(FL_LIGHT1);
      menu_bar->menu(menu_menu_bar);
    } // Fl_Menu_Bar* menu_bar
    { pan_across = new Fl_Slider(0, 514, 780, 19);
      pan_across->type(5);
      pan_across->color(FL_LIGHT1);
      pan_across->selection_color((Fl_Color)94);
    } // Fl_Slider* pan_across
    { pan_vert = new Fl_Slider(780, 29, 20, 486);
      pan_vert->type(4);
      pan_vert->selection_color((Fl_Color)94);
    } // Fl_Slider* pan_vert
    main_window->size_range(640, 480);
    main_window->end();
  } // Fl_Double_Window* main_window
  // Register ecl functions
  cl_def_c_function(c_string_to_object("add-line"), cl_objectfn_fixed(add_line), 4);
  cl_def_c_function(c_string_to_object("add-circle"), cl_objectfn_fixed(add_circle), 3);
  cl_def_c_function(c_string_to_object("get-int"), cl_objectfn_fixed(get_int), 0);
  main_window->show();
  main_window->show(argc, argv);
  return Fl::run();
}
