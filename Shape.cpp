#include "Shape.h"

// Give default values to the static members
bool   Shape::vertex_snap_on         = true;
bool   Shape::midpt_snap_on          = true;
bool   Shape::quad_snap_on           = true;
bool   Shape::division_snap_on       = false;
double Shape::divisions_per_object   = 4;
int    Shape::selection_mask_dist    = 3;


Shape Shape::shape_make_line(ShapePoint& a, ShapePoint& b, 
			     unsigned char red = 0, unsigned char green = 0, 
			     unsigned char blue = 0)
{
  std::vector<ShapePoint> temp {a, b};
  Shape s(temp, Shape::type::LINE);
  s.set_color(red, green, blue);
  return s;
}

Shape Shape::shape_make_circle(ShapePoint& center, double radius, 
			       unsigned char red = 0, unsigned char green = 0,
			       unsigned char blue = 0) 
{
  std::vector<ShapePoint> temp {center, ShapePoint(center.x + radius, center.y)};
  Shape s(temp, Shape::type::CIRCLE);
  s.set_color(red, green, blue);
  return s;
}

Shape Shape::shape_make_arc(ShapePoint& start, ShapePoint& center, 
			    ShapePoint& end, unsigned char red = 0, 
			    unsigned char green = 0, unsigned char blue = 0) 
{
  std::vector<ShapePoint> temp {start, center, end};
  Shape s(temp, Shape::type::ARC);
  s.set_color(red, green, blue);
  return s;
}


Shape::Shape()
{

}


Shape::Shape(std::vector<ShapePoint> &l, int shape_type)
{
  this->type_flag = shape_type;
  this->pts = l;
}

void Shape::set_color(unsigned char r, unsigned char g, unsigned char b)
{
  this->r = r;
  this->g = g;
  this->b = b;
}

bool Shape::mouse_hits_mask(double mouse_x, double mouse_y)
{
  switch(type_flag)
  {
  case Shape::type::LINE:

    break;
  case Shape::type::ARC:

    break;
  case Shape::type::CIRCLE:
	
    break;
  }
  return false;
}

bool Shape::rectangle_touches(ShapePoint pt1, ShapePoint pt2)
{
  switch(type_flag)
  {
  case Shape::type::LINE:

    break;
  case Shape::type::ARC:

    break;
  case Shape::type::CIRCLE:
	
    break;
  }
  return false;
}

bool Shape::rectangle_encloses(ShapePoint pt1, ShapePoint pt2)
{
  switch(type_flag)
  {
  case Shape::type::LINE:

    break;
  case Shape::type::ARC:

    break;
  case Shape::type::CIRCLE:
	
    break;
  }
  return false;
}

Shape::~Shape()
{

}
