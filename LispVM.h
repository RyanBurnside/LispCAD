#ifndef LISPVM_H
#define LISPVM_H

#include <ecl/ecl.h>
#include <iostream>
#include <string>

class LispVM
{
public:
  LispVM(int argc, char** argv);
  ~LispVM();

static cl_object send_string(const std::string& s);
static void def_c_funct(const std::string& s, cl_objectfn_fixed fun,
			       int num_args);
};

#endif
