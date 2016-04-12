#ifndef DRAWING_H
#define DRAWING_H
#include <iostream>
#include <algorithm>
#include <list>
#include "Shape.h"

class Drawing
{
public:
  Drawing(){};
  ~Drawing(){};
  std::list<Shape> shapes;
  void add_shape(Shape& s);
  void remove_shape(Shape& s);
};

#endif
