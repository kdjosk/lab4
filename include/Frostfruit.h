#ifndef FROST_FRUIT_H
#define FROST_FRUIT_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Frostfruit;

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

class Frostfruit {
public:
  void printItems();
  void addItem(const Item &item);
  void updateQuality();

private:
  vector<Item> items_;
};

const std::string item1 = "Aged Cheese";
const std::string item2 = "Tickets to a concert";
const std::string item3 = "Legolas, Hand of Gollum";
#endif // FROST_FRUIT_H
