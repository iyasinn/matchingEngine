#include "../IOrderbook.hpp"

class Orderbook : public IOrderbook {
  // Make a class to return success of these operations
  void addOrder();
  void changeOrder();
  void removeOrder();
  // Make a class with al information from matching some orders
  void matchOrders();
  bool containsOrder(long orderId);
  int getCount();
  std::vector<OrderBookEntry> getAskOrders();
  std::vector<OrderBookEntry> getBidOrders();
};