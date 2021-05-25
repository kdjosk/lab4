#include "../include/Frostfruit.h"
Frostfruit::~Frostfruit() {
  for (auto item : items_) {
    delete item;
  }
}

std::ostream& operator<<(std::ostream& s, IItem* item) {
  s << item->getName() << ", " << item->getDaysRemaining() << ", " << item->getQuality();
  return s;
}

void Frostfruit::updateQuality() {
  for (int i = 0; i < items_.size(); ++i) {
    items_[i]->update();
  }
}

void Frostfruit::addItem(IItem* item) { items_.push_back(item); }

void Frostfruit::printItems(std::ostream& outstream) {
  for (int i = 0; i < items_.size(); ++i) {
    outstream << items_[i] << endl;
  }
}

void Frostfruit::printItems() {
  for (int i = 0; i < items_.size(); ++i) {
    cout << items_[i] << endl;
  }
}


