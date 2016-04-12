// CommandLine class, extends Fl_Input

#ifndef COMMANDLINE_H
#define COMMANDLINE_H
#include <FL/Fl.H>
#include <FL/Fl_Input.h>
#include <string>
#include <ecl/ecl.h>
#include <iostream>

class CommandLine : public Fl_Input
{
public:

// Ugly hack to have a wait variable for external functions
// Not used internally
bool wait_input = true;

enum mode{GET_INT, GET_DOUBLE, NEUTRAL};
static int current_mode;
static cl_object last_object;

CommandLine(int X, int Y,int W,int H,const char*L=0) : Fl_Input(X,Y,W,H,L){}

// Operations to trap user in an input/update loop until value is obtained
// This value is then inserted directly into ecl if the type is right after
/// the return button is pressed
static cl_object get_input(int enum_flag);
static void call_back(Fl_Widget* w, void* d); // callback function
};

#endif
