#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <streambuf>
#include "../include/Frostfruit.h"
#include "../include/NormalItem.h"

std::string EMPTY_STRING = "";

class MockItem : public IItem{
  public:
  MOCK_METHOD0(update, void());
  MOCK_CONST_METHOD0(getName, std::string());
  MOCK_CONST_METHOD0(getDaysRemaining, int());
  MOCK_CONST_METHOD0(getQuality, int());
}

TEST(FrostfruitTest, newIsEmpty) {

  Frostfruit app = Frostfruit();
  std::stringstream output;
  app.printItems(output);

  EXPECT_EQ(output.str(), EMPTY_STRING);
}

TEST(FrostfruitTest, addItem) {

  Frostfruit app = Frostfruit();
  std::stringstream output;
  app.addItem(new NormalItem("+7 Yellow Vest", 10, 20));
  app.printItems(output);

  EXPECT_EQ(output.str(), "+7 Yellow Vest, 10, 20");
}

TEST(FrostfruitTest, updateQuality) {

  Frostfruit app = Frostfruit();
  std::stringstream output;
  MockItem item;

  EXPECT_CALL(item, update()).Times(1);
  EXPECT_CALL(item, getName()).WillOnce(Return("+7 Yellow Vest"));
  EXPECT_CALL(item, getDaysRemaining()).WillOnce(Return(2));
  EXPECT_CALL(item, getQuality()).Times(1).WillOnce(Return(2));

  app.addItem(item);
  app.updateQuality();
  app.printItems(output);



  EXPECT_TRUE(output.str()), "+7 Yellow Vest, 2, 2");
}

