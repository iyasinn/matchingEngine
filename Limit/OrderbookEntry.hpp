#pragma once
#include "../Order/Order.hpp"
#include <ctime>

// Generic Orderbook
class OrderBookEntry {
public:
  OrderBookEntry(Order orderIn) : order(orderIn), creationTime(time(NULL)) {}
  OrderBookEntry(Order orderIn, std::time_t timeIn)
      : order(orderIn), creationTime(timeIn) {}
  const Order getOrder() { return order; }
  const time_t getCreationTime() { return creationTime; }

private:
  Order order;
  const std::time_t creationTime;
};
