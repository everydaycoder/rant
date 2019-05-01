#ifndef __RANT_STRING_STRING_H__
#define __RANT_STRING_STRING_H__

namespace rant {

class String {
public:
  String();
  String(const char* s);
  ~String();

  char* c_str() const;
private:
  char* s_;
  int length_;
}; // class String

} // namespace rant

#endif // __RANT_STRING_STRING_H__
