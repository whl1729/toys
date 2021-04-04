#include "alphabet.h"

#include <fstream>
#include <string>

namespace toys {

Alphabet::Alphabet(const std::string &in_file_name) {
  file_name = in_file_name;
}

int Alphabet::SetCodes() {
  std::ifstream is(file_name);
  std::string line;
  while (is >> line) {
    std::size_t pos = line.find_first_of(' ');
    std::string key = line.substr(0, pos);
    std::vector<std::string> values;
    std::size_t start = pos + 1;
    while ((pos = line.find("、", start)) != std::string::npos) {
      values.push_back(line.substr(start, pos));
      start = pos + 1;
    }

    if (start < line.length()) {
      values.push_back(line.substr(start));
    }

    codes.insert({key, values});
  }

  return 0;
}

std::vector<std::string> Alphabet::GetCodes(const std::string &key) {
  if (codes.find(key) == codes.end()) {
    return std::vector<std::string>{};
  }

  return codes[key];
}
}