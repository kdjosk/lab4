#ifndef CPP_CheeseItem_H
#define CPP_CheeseItem_H

#include "IItem.h"

class CheeseItem : public IItem{
public:
    CheeseItem(const std::string &name, int days_remaining, int quality) : IItem(name, days_remaining, quality) {}
    virtual ~CheeseItem() = default;

    void update() override {

        if (getQuality() < 50)
        {
            if (getDaysRemaining() <= 0)
            {
                incrementQualityBy(2);
            }
            else
            {
                incrementQualityBy(1);
            }
            
            if (getQuality() > 50)
            {
                decreaseQualityBy(getQuality() - 50);
            }
        }


        decreaseDaysRemaining();
    }
};

#endif //CPP_CheeseItem_H
