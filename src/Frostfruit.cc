#include "../include/Frostfruit.h"

Frostfruit::~Frostfruit() {
  for (auto item : items_) {
    delete item;
  }
}

std::ostream &operator<<(std::ostream &s, Item &item) {
  s << item.t << ", " << item.d << ", " << item.v;
  return s;
}

void Frostfruit::updateQuality() {
  for (int i = 0; i < items_.size(); ++i) {
    items_[i]->update();
  }
}

void Frostfruit::addItem(IItem* item) { items_.push_back(item); }
/*
void Frostfruit::printItems() {
  for (vector<IItem>::iterator i = items_.begin(); i != items_.end(); i++) {
    std::cout << *i << std::endl;
  }
}
*/

void Frostfruit::printItems() {
  for (int i = 0; i < items_.size(); ++i) {
    std::cout << items_[i]->getName() << ", " << items_[i]->getDaysRemaining() << ", " << items_[i]->getQuality() << std::endl;
  }
}
