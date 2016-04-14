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
  float scale = 1.0;

  CADCanvas(int X, int Y,int W,int H,const char*L=0) : Fl_Widget(X,Y,W,H,L)
  {
    this->drawing_ptr = new Drawing;
  }

  int handle(int event)
  {
    // Read the parent's handle and assign it to int for return
    // Return 1 if event consumed
    int ret = Fl_Widget::handle(event);
    int new_x = Fl::event_x() - x();
    int new_y = Fl::event_y() - y();
    
    switch(event)
    {
    case FL_PUSH:
      if(CommandLine_ptr != nullptr)
      {
	if(mode == PICK_POINT)
	{
	  CommandLine_ptr->insert(std::string(
				    std::to_string(new_x) + " " + 
				    std::to_string(new_y) + " ").c_str());
	}
      }
      return(1);
      break;
    case FL_RELEASE:
      return(1);
      break;

    case FL_MOUSEWHEEL:
      // TODO clean up bounds checking for scale *DANGER DANGER*
      if(Fl::event_dy() == -1) // Zoom out
      {
	scale *= 2.0;
      }
      else // Zoom in
      {

	if(scale > 0.0)
	{scale /= 2.0;}
      }
      draw();
      return(1);
      break;
    }
    // Still here? Event not consumed!
    return(ret);
  }

  void draw()
  {
    // DRAW BG
    fl_color(color());
    fl_rectf(x(),y(),w(),h());

    if(drawing_ptr != nullptr)
    {
      for(Shape& s:drawing_ptr->shapes)
      {
	fl_color(s.r, s.g, s.b);
	// Break this out as its own function

	switch(s.type_flag)
	{
	case Shape::type::LINE:
	  fl_line(x() + s.pts[0].x * scale, y() + s.pts[0].y * scale,
		  x() + s.pts[1].x * scale, y() + s.pts[1].y * scale);
	  break;
	case Shape::type::ARC:
	  break;
	case Shape::type::CIRCLE:
	  fl_circle(x() + s.pts[0].x * scale, y() + s.pts[0].y * scale,
		    s.pts[1].x * scale - s.pts[0].x * scale);
	  break;

	}
	
      }
    }

  }
};

#endif
