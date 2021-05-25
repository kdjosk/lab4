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

void Frostfruit::printItems() {
  for (int i = 0; i < items_.size(); ++i) {
    std::cout << items_[i]->getName() << ", " << items_[i]->getDaysRemaining() << ", " << items_[i]->getQuality() << std::endl;
  }
}

void Frostfruit::printItems(std::ostream& outstream) {
  for (const auto item : items_) {
    outstream << item << std::endl;
  }
}
