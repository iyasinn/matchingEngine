#pragma once
#include "../Order/Order.hpp"
#include "./OrderbookEntry.hpp"

class Limit {
public:
  Limit(long priceIn) : price(priceIn) {}

  // Getter and Setter for Previous
  OrderBookEntry *getHead() const { return head; }
  void setHead(OrderBookEntry *entry) { head = tail; }

  OrderBookEntry *getTail() const { return tail; }
  void setTail(OrderBookEntry *entry) { head = tail; }

  uint getTotalOrders() { return totalOrders; }
  uint getTotalQuantity() { return totalQuantity; }
  bool empty() { return head == tail && tail == nullptr; }

  long getPrice() { return price; }

private:
  long price;
  OrderBookEntry *head = nullptr;
  OrderBookEntry *tail = nullptr;
  uint totalOrders = 0;
  uint totalQuantity = 0;
};