#ifndef FROST_FRUIT_H
#define FROST_FRUIT_H
#include <iostream>
#include <string>
#include <vector>
#include "../include/IItem.h"

using namespace std;

class Frostfruit;

/*
class Item {
public:
  Item(string name, int days_remaining, int quality)
      : t(name), d(days_remaining), v(quality) {}
  friend class Frostfruit;
  friend std::ostream &operator<<(std::ostream &s, Item &item);

private:
  string t;
  int d;
  int v;
};
*/

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


