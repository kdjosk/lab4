#ifndef FROST_FRUIT_H
#define FROST_FRUIT_H
#include <iostream>
#include <string>
#include <vector>
#include "../include/IItem.h"

using namespace std;

class Frostfruit;

class Frostfruit {
public:
  void printItems();
  void printItems(std::ostream& outstream);
  void addItem(IItem* item);
  void updateQuality();
  ~Frostfruit();

private:
  vector<IItem*> items_;
};

#endif // FROST_FRUIT_H


