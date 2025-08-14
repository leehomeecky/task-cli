// task-cli.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "temp_storage.h"

int main()
{

  std::unique_ptr<storage::IStorage<std::string>> temp_storage =
      std::make_unique<storage::TempStorage<std::string>>();

  temp_storage->create(1, std::string("meecky"));
  temp_storage->create(2, std::string("leeho"));
  temp_storage->create(3, std::string("leehomeecky"));
  temp_storage->create(4, std::string("meeckyleeho"));
  temp_storage->update(1, std::string("this is me"));
  temp_storage->deleteById(2);

  std::vector<std::string> value = temp_storage->read();
  for (std::string var : value) {
    std::cout << var << std::endl;
  }
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
