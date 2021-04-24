#ifndef _IPV4_TABLE_H_
#define _IPV4_TABLE_H_

#include <string>
#include <vector>

struct IPv4Item {
  uint32_t start_ip;
  uint32_t end_ip;
  std::string country;
  std::string province;
  std::string city;
};

class IPv4Table {
 public:
  bool Load(std::string file_path);
  bool Search(uint32_t ip, IPv4Item &item);
  void Display();

 private:
  std::vector<IPv4Item> table_;
};

void DisplayItem(const IPv4Item &item);

#endif // _IPV4_TABLE_H_