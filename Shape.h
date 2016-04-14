#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <vector>
#include <math.h>

#define PI 3.14159265

struct ShapePoint
{
  ShapePoint(double x, double y)
  {
    this->x = x;
    this->y = y;
  }

  double x = 0;
  double y = 0;

  double distance_to(ShapePoint& s)
  {
    double dif_x = s.x - x;
    double dif_y = s.y - y;
    return sqrt(dif_x * dif_x + dif_y * dif_y);
  }

  double direction_to(ShapePoint& s, bool use_radians = true)
  {
    double dif_x = s.x - x;
    double dif_y = s.y - y;
    double result = atan2(dif_y, dif_x);
    return use_radians ? result : result * 180.0 / PI;
  }
};

/* Instead of polymorphism, all current geometry can fall into 3 shapes easily
   described in a single class wrapped around a shape flag and collection
   of ShapePoints */

class Shape
{
public:
  // Some flags to determine how to handle this shape
  enum type {LINE, ARC, CIRCLE};

  // The meat of the Shape, a list of points
  std::vector<ShapePoint> pts;

  int  type_flag = Shape::type::LINE;
  /* snap modes are
     vertex (lines)
     midpoint (lines, circle)
     quadrants (circle)
     divisions <num_divisions> works with arcs, lines, circles */

  static bool   vertex_snap_on;
  static bool   midpt_snap_on;
  static bool   quad_snap_on;
  static bool   division_snap_on;
  static double divisions_per_object;

  /* This is the distance from the cursor onscreen to be "selected"
     The width of the selection mask defined per shape in pixels.
     The mask thickness is not considered for rectangular selections.*/

  static int selection_mask_dist;

  // A flag to mark shape instances as selected
  bool selected = false;

  // Colors are broken down into uchars to jive with FLTK 
  unsigned char r      =  0;
  unsigned char g      =  0;
  unsigned char b      =  0;
  void set_color(unsigned char r, unsigned char g, unsigned char b);

  Shape();
  Shape(std::vector<ShapePoint> &l, int shape_type = Shape::type::LINE);

  // These are methods that process based on the flag of the shape
  bool mouse_hits_mask(double mouse_x, double mouse_y);
  bool rectangle_touches(ShapePoint pt1, ShapePoint pt2);
  bool rectangle_encloses(ShapePoint pt1, ShapePoint pt2);

  // Helper class methods to generate specific shapes
  static Shape shape_make_line(ShapePoint& a, ShapePoint& b, unsigned char red,
			       unsigned char green, unsigned char blue);

  static Shape shape_make_circle(ShapePoint& center, double radius,
				 unsigned char red, unsigned char green,
				 unsigned char blue);

  // Note, point order is start center end clockwise
  static Shape shape_make_arc(ShapePoint& start, ShapePoint& middle, 
			      ShapePoint& end, unsigned char red, 
			      unsigned char green, unsigned char blue);
  ~Shape();
};
#endif
