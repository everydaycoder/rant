#include "rant/string/string.h"

#include <string.h>
#include <iostream>

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
  s_ = new char[strlen(s)+1];
  s_ = strncpy(s_, s, strlen(s)+1);
  // Set last position to null to complete string.
  s_[strlen(s)] = '\0';
  
  length_ = strlen(s_);
}

// ~String() <dest>
// 
// Clean up internal private variables.
String::~String() {
  delete s_;
}

// const char* c_str() const
// 
// Returns the underlying c string (char*) that contains the string data.
// @return char* The underlying c string
// 
// @const
const char* String::c_str() const {
  return s_;
}

// operator char*() const
//
// Returns the underlying c string without the need to call c_str().
// @return char* The underlying c string
// 
// @const
// @operator
String::operator char*() const {
  return s_;
}

// String& concat(const String&)
// 
// Concatenates the given string object with the current one and returns
// the result. This value is also saved in the calling object's c string.
// @return String& This string object
String& String::concat(const String& other) {
  char* result = new char[length_ + other.length_ + 1];
  result = strncpy(result, s_, length_);

  strncpy(result+length_, other.s_, other.length_);
  s_ = new char[length_ + other.length_ + 1];
  s_ = strncpy(s_, result, strlen(result));

  length_ = strlen(s_);

  return *this;
}

// String& concat(const char*)
// 
// Concatenates the given c string with the current one and returns the
// result. This value is also saved in the calling object's c string.
// @return String& This string object
String& String::concat(const char* other) {
  char* result = new char[length_ + strlen(other) + 1];
  result = strncpy(result, s_, length_);

  strncpy(result+length_, other, strlen(other));
  s_ = new char[length_ + other.length_ + 1];
  s_ = strncpy(s_, result, strlen(result));

  length_ = strlen(s_);

  return *this;
}

// String operator +(const String&) const
// 
// Concatenate the two strings in place without altering either object.
// @return String& The constructed string object
// 
// @const
// @operator
String String::operator+(const String& other) const {
  char* tmp = new char[length_ + other.length_ + 1];
  tmp = strncpy(tmp, s_, length_);
  
  strncpy(tmp+length_, other.s_, other.length_);

  return String(tmp);
}

// String operator +(const char*) const
// 
// Concatenate the two strings in place without altering either object.
// @return String The constructed string object
// 
// @const
// @operator
String String::operator+(const char* other) const {
  char* tmp = new char[length_ + strlen(other)+1];
  tmp = strncpy(tmp, s_, length_);
  
  strncpy(tmp+length_, other, strlen(other));

  return String(tmp);
}

} // namespace rant
