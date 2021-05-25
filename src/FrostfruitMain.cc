#include "../include/Frostfruit.h"

using namespace std;

int main() {
  Frostfruit app;

  app.addItem(Item("+7 Yellow Vest", 10, 20));

  cout << "HAHAHA!" << endl;
  app.updateQuality();
  app.printItems();
}
