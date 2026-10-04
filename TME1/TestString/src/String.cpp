#include "String.h"

namespace pr
{

// TODO: copier s dans data (liste d'initialisation)
String::String (const char *s) : data(nullptr)
{
  std::cout << "String constructor called for: " << s << std::endl;
  if( s!=nullptr){
    data=newcopy(data,s);

  }
  
}

String::~String ()
{
  std::cout << "String destructor called for: " << (data ? data : "(null)")
      << std::endl;
    delete [] data;
}

String& string::operator=(const string & other){
  if (this != other){
    delete[] data;
    str=newcopy(other.data);
  }
  return *this; 
}

// TODO : add other operators and functions

}// namespace pr

