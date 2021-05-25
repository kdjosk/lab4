#include <fstream>
#include <streambuf>
#include <gtest/gtest.h>

#include "../include/CheeseItem.h"
#include "../include/ConcertTicketItem.h"
#include "../include/Frostfruit.h"
#include "../include/NormalItem.h"
#include "../include/LegolasItem.h"

std::string readGroundtruth(const std::string& filename)
{
    std::ifstream file{filename, std::ifstream::in};
    std::stringstream s;
    s << file.rdbuf();
    return s.str();
};

TEST(FrostfruitCharacterizationTest, Foo)
{
    Frostfruit app;

    app.addItem(ItemPointer{new NormalItem("+7 Yellow Vest", 10, 20)});
    app.addItem(ItemPointer{new CheeseItem("Cheese Brie", 10, 20)});
    app.addItem(ItemPointer{new ConcertTicketItem("Tickets to a concert", 10, 20)});
    app.addItem(ItemPointer{new LegolasItem("Legolas, Hand of Gollum", 10, 20)});

    std::stringstream output;

    for (int day = 0; day < 5; ++day)
    {
        output << "Day is " << day << std::endl;
        app.updateQuality();
        app.printItems(output);
        output << std::endl;
    }

    std::string groundtruth = readGroundtruth("ExpectedTestOutputs.txt");

    EXPECT_EQ(groundtruth, output.str());
}
