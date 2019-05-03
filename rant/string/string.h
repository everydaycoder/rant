#ifndef __RANT_STRING_STRING_H__
#define __RANT_STRING_STRING_H__

namespace rant {

class String {
public:
  String();
  String(const char* s);
  ~String();

  const char* c_str() const;
  operator char*() const;

  String& concat(const String& other);
  String& concat(const char* other);
  String operator +(const String& other) const;
  String operator +(const char* other) const;
private:
  char* s_;
  int length_;
}; // class String

} // namespace rant

#endif // __RANT_STRING_STRING_H__
