#ifndef CPP_LegolasItem_H
#define CPP_LegolasItem_H

#include "IItem.h"

class LegolasItem : public IItem{
public:
    LegolasItem(const std::string &name, int days_remaining, int quality) : IItem(name, days_remaining, quality) {}
    virtual ~LegolasItem() = default;

    void update() override {
        return;
    }
};

#endif //CPP_LegolasItem_H
