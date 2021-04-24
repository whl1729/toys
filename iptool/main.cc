#include "ipv4_table.h"
#include <stdlib.h>
#include <chrono>
#include <iostream>

using namespace std::chrono;

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cout << "Usage: " << argv[0] << " file_path ip" << std::endl;
    return 1;
  }

  IPv4Table table;
  if (!table.Load(argv[1])) {
    std::cout << "Ipv4Table::Load(" << argv[1] << ") error!" << std::endl;
    return 1;
  }

  uint32_t ip = atoi(argv[2]);

  IPv4Item item;
  
  auto start = high_resolution_clock::now();
  if (!table.Search(ip, item)) {
    std::cout << "Ipv4Table::Search(" << argv[2] << ") failed!" << std::endl;
    return 1;
  }

  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - start);
  std::cout << "Search costs " << duration.count() << " microseconds." << std::endl;

  DisplayItem(item);
  return 0;
}