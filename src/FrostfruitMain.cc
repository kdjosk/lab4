#include "../include/Frostfruit.h"
#include "../include/NormalItem.h"
#include "../include/CheeseItem.h"
#include "../include/ConcertTicketItem.h"
#include "../include/LegolasItem.h"

using namespace std;

int main() {
  Frostfruit app;

  app.addItem(new NormalItem("+7 Yellow Vest", 10, 20));
  app.addItem(new CheeseItem("cheese", 10, 20));
  app.addItem(new ConcertTicketItem("ticket", 10, 20));
  app.addItem(new LegolasItem("legolas", 10, 20));

  app.updateQuality();

  app.printItems();
}
