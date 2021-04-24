#include "ipv4_table.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

static void split(string str, const string &delimiter, vector<string> &result)
{
  size_t pos = 0;
  std::string token;
  while ((pos = str.find(delimiter)) != std::string::npos)
  {
    token = str.substr(0, pos);
    result.push_back(token);
    str.erase(0, pos + delimiter.length());
  }

  result.push_back(str);
}

static bool ParseLine(const string &line, IPv4Item &item)
{
  vector<string> result;
  split(line, "\t", result);

  if (result.size() < 3) {
    std::cout << "invalid line: " << line << std::endl;
    return false;
  }

  item.start_ip = std::stoul(result[0], nullptr, 10);
  item.end_ip = std::stoul(result[1], nullptr, 10);
  item.country = result[2];

  if (result.size() > 3) {
    item.province = result[3];
  }

  if (result.size() > 4) {
    item.city = result[4];
  }

  return true;
}

bool IPv4Table::Load(std::string file_path)
{
  std::ifstream is(file_path);
  string line;

  while (std::getline(is, line))
  {
    IPv4Item item;
    if (ParseLine(line, item)) {
      table_.push_back(item);
    }
  }

  // Display();

  return true;
}

static bool Compare(const IPv4Item &a, const IPv4Item &b) {
  return a.end_ip < b.end_ip;
}

void DisplayItem(const IPv4Item &item) {
  std::cout << item.start_ip << "\t";
  std::cout << item.end_ip << "\t";
  std::cout << item.country << "\t";
  std::cout << item.province << "\t";
  std::cout << item.city << "\n";
}

void IPv4Table::Display() {
  for (auto &item: table_) {
    DisplayItem(item);
  }
}

bool IPv4Table::Search(uint32_t ip, IPv4Item &item) {
  IPv4Item target;
  target.end_ip = ip;

  auto result = std::lower_bound(table_.begin(), table_.end(), target, Compare);
  if (result == table_.end()) {
    std::cout << ip << " not found" << std::endl;
    return false;
  }

  std::cout << ip << " found" << std::endl;

  item = *result;

  return true;
}