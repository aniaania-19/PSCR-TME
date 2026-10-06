#include "String.h"

namespace pr
{

String::String(const char *s) : data(nullptr)
{
    std::cout << "String constructor called for: " << (s ? s : "(null)") << std::endl;
    if (s != nullptr) {
        data = newcopy(s);
    }
}

String::~String()
{
    std::cout << "String destructor called for: " << (data ? data : "(null)")
              << std::endl;
    delete[] data;
}

String::String(const String& other) : data(nullptr)
{
    if (other.data != nullptr) {
        data = newcopy(other.data);
    }
}

String& String::operator=(const String& other)
{
    if (this != &other) {
        delete[] data;
        data = other.data ? newcopy(other.data) : nullptr;
    }
    return *this;
}

String::String(String&& other) noexcept : data(other.data)
{
    other.data = nullptr;
}

String& String::operator=(String&& other) noexcept
{
    if (this != &other) {
        delete[] data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}

bool String::operator<(const String& other) const
{
    return compare(data, other.data) < 0;
}

bool operator==(const String& a, const String& b)
{
    return compare(a.data, b.data) == 0;
}

String operator+(const String& a, const String& b)
{
    char* buf = newcat(a.data, b.data);
    String concat(buf);   // copie le contenu
    delete[] buf;         // libère le tableau temporaire
    return concat;
}
std::ostream& operator<<(std::ostream& os,const String& str){
  if(str.data !=nullptr)
     os << str.data;

  return os;
}

} // namespace pr