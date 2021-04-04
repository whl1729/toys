#ifndef _ALPHABET_H_
#define _ALPHABET_H_

#include <map>
#include <string>
#include <vector>

namespace toys {

class Alphabet {
 public:
  Alphabet(const std::string &in_file_name);
  int SetCodes();
  std::vector<std::string> GetCodes(const std::string &key);

 private:
  std::string file_name;
  std::map<std::string, std::vector<std::string>> codes;
};
}

#endif