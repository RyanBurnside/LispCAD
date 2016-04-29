#ifndef CADCANVAS_H
#define CADCANVAS_H
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "Shape.h"
#include "Drawing.h"
#include "CommandLine.h"

class CADCanvas : public Fl_Widget 
{
public:
  Drawing* drawing_ptr = nullptr;
  CommandLine* CommandLine_ptr = nullptr;
  enum {SELECTING, PICK_SHAPE, PICK_POINT};
  int mode = PICK_POINT;  
  double scale = 1.0;
  double offset_x = 0.0;
  double offset_y = 0.0;
  // Used for mapping a real location to window location
  double scale_dimension(double value);
  CADCanvas(int X, int Y,int W,int H,const char* L = 0) : Fl_Widget(X,Y,W,H,L)
  {
    // This should be removed eventually CADCanvas should not own drawings.
    this->drawing_ptr = new Drawing;
  }

  int handle(int);
  void draw();
};

#endif
