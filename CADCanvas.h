#ifndef CADCANVAS_H
#define CADCANVAS_H
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include "Shape.h"
#include "Drawing.h"


class CADCanvas : public Fl_Widget 
{
public:
Drawing* drawing_ptr = nullptr;
CADCanvas(int X, int Y,int W,int H,const char*L=0) : Fl_Widget(X,Y,W,H,L)
{
  this->drawing_ptr = new Drawing;
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
	fl_line(x() + s.pts[0].x, y() + s.pts[0].y,
		x() + s.pts[1].x, y() + s.pts[1].y);
	break;
      case Shape::type::ARC:
	break;
      case Shape::type::CIRCLE:
	fl_circle(x() + s.pts[0].x, y() + s.pts[0].y,
		  s.pts[1].x - s.pts[0].x);
	break;

      }
	
    }
  }

}
};

#endif
