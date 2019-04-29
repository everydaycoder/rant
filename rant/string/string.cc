#include "rant/string/string.h"

namespace rant {

// String() <cons>
// 
// Instantiate an empty Rant String with length 0.
String::String() {
  s_ = nullptr;
  length_ = 0;
}

// ~String() <dest>
// 
// Clean up internal private variables.
String::~String() {
  delete s_;
}

} // namespace rant
