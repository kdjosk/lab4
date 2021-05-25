#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <streambuf>
#include "../include/Frostfruit.h"
#include "../include/NormalItem.h"

std::string EMPTY_STRING = "";

class MockItem : public IItem{
  public:
  MOCK_METHOD0(update, void());
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
  app.addItem(ItemPointer{new NormalItem("+7 Yellow Vest", 10, 20)});
  app.printItems(output);

  EXPECT_EQ(output.str(), "+7 Yellow Vest, 10, 20");
}

TEST(FrostfruitTest, updateQuality) {

  Frostfruit app = Frostfruit();
  std::stringstream output;
  // TODO(kdjosk) Mock item so the test doesn't depend on it
  ItemPointer item = ItemPointer{new MockItem()};
  app.addItem(item);
  app.updateQuality();
  app.printItems(output);

  EXPECT_CALL(item, update()).Times(1)

  EXPECT_TRUE(output.str()), "+7 Yellow Vest, 9, 19");
}

