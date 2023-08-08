#pragma once
#include "../Order/Order.hpp"
#include "./OrderbookEntry.hpp"

class Limit {
public:
  // Getter and Setter for Next
  OrderBookEntry *getNext() const { return head; }
  void setNext(OrderBookEntry *entry) { head = entry; }

  // Getter and Setter for Previous
  OrderBookEntry *getPrevious() const { return tail; }
  void setPrevious(OrderBookEntry *entry) { previous = entry; }

private:
  long price;
  OrderBookEntry *head;
  OrderBookEntry *tail;
  uint totalOrders;
  uint totalQuantity;
};