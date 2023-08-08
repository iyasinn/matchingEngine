#pragma once
#include "../Order/Order.hpp"
#include <ctime>
#include <iostream>

// Forward declare Limit so we can use it
class Limit;

class OrderBookEntry {
public:
  // Getter and Setter for CurrentOrder
  const Order &getCurrentOrder() const { return currentOrder; }

  // Getter for CreationTime
  const std::time_t &getCreationTime() const { return creationTime; }

  // Getter and Setter for ParentLimit
  Limit *const getParentLimit() const { return parentLimit; }

  // Getter and Setter for Next
  OrderBookEntry *getNext() const { return next; }
  void setNext(OrderBookEntry *entry) { next = entry; }

  // Getter and Setter for Previous
  OrderBookEntry *getPrevious() const { return previous; }
  void setPrevious(OrderBookEntry *entry) { previous = entry; }

private:
  Order currentOrder;
  std::time_t creationTime;
  Limit *parentLimit;
  OrderBookEntry *next;
  OrderBookEntry *previous;
};