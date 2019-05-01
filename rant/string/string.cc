#include "rant/string/string.h"

#include <string.h>

namespace rant {

// String() <cons>
// 
// Instantiate an empty Rant String with length 0.
String::String() {
  s_ = nullptr;
  length_ = 0;
}

// String(const char*) <cons>
// 
// Instantiate a new Rant String with the given char* value.
// @param const char* s The value to set the string to.
String::String(const char* s) {
  // Create new char* with sizeof(s)+1 (Null) bytes allocated to it.
  s_ = new char[sizeof(s)+1];
  s_ = strncpy(s_, s, sizeof(s) + 1);
  // Set last position to null to complete string.
  s_[sizeof(s)] = '\0';
  
  length_ = sizeof(s);
}

// ~String() <dest>
// 
// Clean up internal private variables.
String::~String() {
  delete s_;
}

// char* c_str() const
// 
// Returns the underlying c string (char*) that contains the string data.
// @return char* The underlying c string
// 
// @const
char* String::c_str() const {
  return s_;
}

} // namespace rant
