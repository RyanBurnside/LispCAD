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
CommandLine(int X, int Y,int W,int H,const char*L=0) : Fl_Input(X,Y,W,H,L){}

/* This is a mode that determines if the test is to be sent directly to the
   repl or if it is to be sent to a calling function like (get-int)
*/
  
  bool repl_mode  = true;
};

#endif
