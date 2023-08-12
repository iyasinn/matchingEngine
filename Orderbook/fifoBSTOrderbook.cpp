#include "fifoBSTOrderbook.hpp"
#include <vector>

using namespace std;

// We create an order then pass it in like this
void fifoBstOrderbook::addOrder(Order order) {

  // See if order exists
  if (orders.find(order.getOrderId()) != orders.end()) {
    // Info that order is already in here is nice to return
    cout << "Order already present\n";
    return;
  }

  // Look at which book we need
  std::map<long, LimitTree> &book =
      (order.getIsBuySide()) ? buyOrders : askOrders;

  // See if limit exists
  if (book.find(order.getPrice()) == book.end()) {
    book[order.getPrice()] = LimitTree(order.getPrice());
  }

  LimitTree &limit = book[order.getPrice()];
  OrderBookEntryTree *entry = new OrderBookEntryTree(order, &limit);

  if (limit.empty()) {
    limit.head() = limit.tail() = entry;
  } else {
    limit.tail()->next = entry;
    entry->prev = limit.tail();
    limit.tail() = entry;
  }
  limit.changeTotalOrders(1);
  limit.changeTotalQuantity(entry->getOrder().getInitialQuantity());
  orders[order.getOrderId()] = entry;
  cout << "Added order " << order.getOrderId() << " to "
       << (order.getIsBuySide() ? " buySide " : " sellSide ") << "\n";
}

void fifoBstOrderbook::removeOrder(Order order) {

  if (orders.find(order.getOrderId()) == orders.end()) {
    cout << "Order doesn't exist\n";
    return;
  }

  OrderBookEntryTree *entry = orders[order.getOrderId()];
  LimitTree *parentLimit = entry->getParentLimit();

  if (entry->prev && entry->next) {
    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;
  } else if (entry->prev) {
    entry->prev->next = nullptr;
    parentLimit->tail() = entry->prev;
  } else if (entry->next) {
    entry->next->prev = nullptr;
    parentLimit->head() = entry->next;
  } else {
    parentLimit->head() = parentLimit->tail() = nullptr; // added
  }

  parentLimit->changeTotalOrders(-1);
  parentLimit->changeTotalQuantity(entry->getOrder().getCurrentQuantity() * -1);
  orders.erase(entry->getOrder().getOrderId());
  // Memory menagement need to dleete
  cout << "Erased " << order.getOrderId() << endl;
  delete entry;

  // Other method potentially
  // if (parentLimit->head() == entry && parentLimit->tail() == entry) {
  //   parentLimit->head() = parentLimit->tail() = nullptr;
  // } else if (parentLimit->head() == entry) {
  //   parentLimit->head() = entry->next;
  // } else if (parentLimit->tail() == entry) {
  //   parentLimit->tail() = entry;
  // }
}

void fifoBstOrderbook::changeOrder(Order order) {
  if (orders.find(order.getOrderId()) == orders.end()) {
    cout << "Order doesn't exist\n";
    return;
  }
  removeOrder(order);
  addOrder(order);
}

void fifoBstOrderbook::printOrders() {
  cout << "PRINTING\n";
  for (auto p : orders) {
    auto entry = p.second;
    cout << "Limit price: " << entry->getParentLimit()->getPrice()
         << " | Limit size: " << entry->getParentLimit()->getTotalOrders()
         << " | Limit quantity: " << entry->getParentLimit()->getTotalQuantity()
         << " | ID: " << entry->getOrder().getOrderId() << endl;
  }
}

void fifoBstOrderbook::matchOrders() { return; }

int fifoBstOrderbook::getCount() { return count; }
vector<OrderBookEntry> fifoBstOrderbook::getAskOrders() {
  return vector<OrderBookEntry>();
}

vector<OrderBookEntry> fifoBstOrderbook::getBidOrders() {
  return vector<OrderBookEntry>();
}
