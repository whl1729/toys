#include <iostream>
#include <string>
#include <vector>

#include "alphabet.h"

int main(int argc, char *argv[])
{
  std::string file_name("/home/along/daying/memory/alphabet_code.md");
  if (argc > 1) {
    file_name = argv[1];
  }

  std::cout << "file_name: " << file_name << std::endl;

  toys::Alphabet alphabet(file_name);
  if (alphabet.SetCodes() != 0) {
    std::cout << "fail to SetCode" << std::endl;
    return 1;
  }

  std::vector<std::string> codes;
  std::string arr[] = {"ab", "cd", "ef"};
  for (const std::string &elem: arr) {
    codes = alphabet.GetCodes(elem);
    for (const std::string &code: codes) {
      std::cout << code << " " << std::endl;
    }
    std::cout << std::endl;
  }

  return 0;
}