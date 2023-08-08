#pragma once
#include "../Limit/OrderbookEntry.hpp"
#include <vector>

class IOrderbook {
public:
  // Make a class to return success of these operations
  virtual void addOrder() = 0;
  virtual void changeOrder() = 0;
  virtual void removeOrder() = 0;
  // Make a class with al information from matching some orders
  virtual void matchOrders() = 0;
  virtual bool containsOrder(long orderId) = 0;
  virtual int getCount() = 0;
  virtual std::vector<OrderBookEntry> getAskOrders() = 0;
  virtual std::vector<OrderBookEntry> getBidOrders() = 0;
};