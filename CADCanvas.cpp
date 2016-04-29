#include "CADCanvas.h"


double CADCanvas::scale_dimension(double value)
{
  return value * scale;
}

int CADCanvas::handle(int event)
{
  // Read the parent's handle and assign it to int for return
  // Return 1 if event consumed
  int ret = Fl_Widget::handle(event);
  int new_x = Fl::event_x() - x();
  int new_y = Fl::event_y() - y();
    
  switch(event)
  {
  case FL_PUSH:
    if(CommandLine_ptr != nullptr and Fl::event_button() == 1)
    {
	CommandLine_ptr->insert(std::string(
				  std::to_string(new_x) + " " + 
				  std::to_string(new_y) + " ").c_str());
    }
    draw();
    return(1);
    break;

  case FL_MOUSEWHEEL:
    if(Fl::event_dy() == -1) // Zoom out
    {
      // Check for wrap around
      if(scale * 2.0 > scale)
	scale *= 2.0;
    }
    else if(Fl::event_dy() == 1)
    {
      scale *= 0.5;
    }

    redraw();
    return(1);
    break;
  }

  // Still here? Event not consumed!
  return(ret);
}

void CADCanvas::draw()
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
	fl_line(x() + scale_dimension(s.pts[0].x), 
		y() + scale_dimension(s.pts[0].y),
		x() + scale_dimension(s.pts[1].x), 
		y() + scale_dimension(s.pts[1].y));
	break;
      case Shape::type::ARC:
      {
	double _x = x() + scale_dimension(s.pts[0].x);
	double _y = y() + scale_dimension(s.pts[0].y);
	double _x2 = x() + scale_dimension(s.pts[1].x);
	double _y2 = y() + scale_dimension(s.pts[1].y);
	fl_arc(_x, _y, abs(_x2 - _x), abs(_y2 - _y), s.angle_1, s.angle_2);
      }	       
	       
	break;
      case Shape::type::CIRCLE:
	fl_circle(x() + scale_dimension(s.pts[0].x), 
		  y() + scale_dimension(s.pts[0].y),
		  scale_dimension(s.pts[1].x) - scale_dimension(s.pts[0].x));
	break;

      }
      for(auto p:s.pts)
      {
	fl_color(255, 255, 0);
	fl_circle(x() + scale_dimension(p.x), 
		  y() + scale_dimension(p.y), 3);
	fl_circle(x() + scale_dimension(p.x), 
		  y() + scale_dimension(p.y), 2);
      }
    }
  }
}
