#include "fifoBSTOrderbook.hpp"
#include <vector>

using namespace std;

void fifoBstOrderbook::addOrder(Order order) {

  LimitTree limit(order.getPrice());
  if (buyOrders.find(limit) == buyOrders.end()) {
    cout << "FOUND\n";
  } else {
    buyOrders.insert(limit);
  }
  return;
}

void fifoBstOrderbook::changeOrder(Order order) {
  cout << "PRINTING\n";
  for (auto limit : buyOrders) {
    cout << limit.getPrice() << endl;
  }
}

void fifoBstOrderbook::removeOrder(Order order) {}

void fifoBstOrderbook::matchOrders() {}

int fifoBstOrderbook::getCount() { return count; }
vector<OrderBookEntry> fifoBstOrderbook::getAskOrders() { return {}; }
vector<OrderBookEntry> fifoBstOrderbook::getBidOrders() { return {}; }
