#pragma once
#include "../Limit/OrderbookEntry.hpp"
#include <string>
#include <vector>

class IOrderbook {
public:
  IOrderbook(std::string securityIn) : security(securityIn) {}
  // Make a class to return success of these operations
  virtual void addOrder(Order order) = 0;
  virtual void changeOrder(Order order) = 0;
  virtual void removeOrder(Order order) = 0;
  // Make a class with al information from matching some orders
  virtual void matchOrders() = 0;
  // virtual bool containsOrder(long orderId) = 0;
  std::string getSecurity() { return security; }
  virtual std::vector<OrderBookEntry> getAskOrders() = 0;
  virtual std::vector<OrderBookEntry> getBidOrders() = 0;
  virtual int getCount() = 0;
  virtual bool empty() = 0;

private:
  std::string security;
};