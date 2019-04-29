#include "rant/string/string.h"

namespace rant {

// String()
// 
// Instantiate an empty Rant String with length 0.
String::String() {
  s_ = nullptr;
  length_ = 0;
}

} // namespace rant
