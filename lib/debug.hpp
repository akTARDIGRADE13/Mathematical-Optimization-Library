#include <ostream>
#include <vector>

namespace akTARDIGRADE13{

  template<typename T>
  std::ostream& operator<<(std::ostream& os, const std::vector<T>& op) {
	  for(auto &i:op) os << i << ' ';
	  return os;
  }
}

