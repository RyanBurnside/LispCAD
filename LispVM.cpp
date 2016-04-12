#include "LispVM.h"

LispVM::LispVM(int argc, char** argv)
{
  cl_boot(argc, argv);
  atexit(cl_shutdown);
  std::cout << "Starting LispVM " << this << std::endl;

}

LispVM::~LispVM()
{

}

cl_object LispVM::send_string(const std::string& s)
{
  return cl_safe_eval(c_string_to_object(s.c_str()), Cnil, Cnil);
}

void LispVM::def_c_funct(const std::string& s, cl_objectfn_fixed fun, 
			 int num_args)
{
  return cl_def_c_function(c_string_to_object(s.c_str()), 
			   fun, num_args);
}

void hello_world()
{
  std::cout << "Hello world " << std::endl;
}

int main()
{
  std::cout << "hello world!" << std::endl;
  LispVM a();
  LispVM::def_c_funct("hello-world", (cl_objectfn_fixed)hello_world, 0);
  LispVM::send_string("(hello-world)");
  return 0;
}
