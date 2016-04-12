#include "CommandLine.h"

int CommandLine::current_mode = CommandLine::mode::NEUTRAL;
cl_object CommandLine::last_object;

cl_object CommandLine::get_input(int enum_flag)
{
  current_mode = enum_flag;
  while (current_mode != CommandLine::mode::NEUTRAL)
  { 
    // Simply update GUI and process events until the callback (enter key)
    // breaks the loop and sets the flag to neutral when valid input is present
    Fl::wait();
    Fl::check();
  }
  return CommandLine::last_object;
}

void CommandLine::call_back(Fl_Widget* w, void* d)
{
  // Calls itself and sets mode flag if successful converstion
  CommandLine* command = (CommandLine*)w;
  std::string temp_string = command->value();
  switch(current_mode)
    {
    case GET_INT:
      try
      {
	int temp = std::stoi(temp_string);
	std::cout << temp << std::endl;
	last_object = c_string_to_object(std::to_string(temp).c_str());
	current_mode = CommandLine::mode::NEUTRAL;
      }
      catch(...)
      {
	std::cout << "Error, expected an int" << std::endl;
      }
      
      break;
    case GET_DOUBLE:
      try
      {
	double temp = std::stod(temp_string);
	std::cout << temp << std::endl;
	last_object = c_string_to_object(temp_string.c_str());
	current_mode = CommandLine::mode::NEUTRAL;
      }
      catch(...)
      {
	std::cout << "Error, expected a floating point" << std::endl;
      }

      break;
    case NEUTRAL:
      try
      {
	cl_object obj = c_string_to_object(temp_string.c_str());
	cl_safe_eval(obj, Cnil, Cnil);
      }
      catch(...)
      {

      }
      break;
    }
}
