#pragma once
#include "../Order/Order.hpp"
#include "./ILimit.hpp"
#include "./OrderbookEntry.hpp"

class OrderBookEntryTree;

class LimitTree : public ILimit {
public:
  LimitTree() : ILimit(0) {}
  LimitTree(long priceIn) : ILimit(priceIn) {}
  // Interface functions
  uint getTotalOrders() { return totalOrders; }
  void changeTotalOrders(uint delta) { totalOrders += delta; }
  uint getTotalQuantity() { return totalQuantity; }
  void changeTotalQuantity(uint delta) { totalQuantity += delta; }
  bool empty() { return headPointer == tailPointer && tailPointer == nullptr; }

  // Member specific functions
  // Reference to pointer lets us actually change the pointer itself
  OrderBookEntryTree *&head() { return headPointer; }
  OrderBookEntryTree *&tail() { return tailPointer; }

private:
  OrderBookEntryTree *headPointer = nullptr;
  OrderBookEntryTree *tailPointer = nullptr;
  uint totalOrders = 0;
  uint totalQuantity = 0;
};

class OrderBookEntryTree : public OrderBookEntry {
public:
  OrderBookEntryTree(Order orderIn, LimitTree *parentLimitIn)
      : OrderBookEntry(orderIn), parentLimit(parentLimitIn) {}
  LimitTree *getParentLimit() { return parentLimit; }
  OrderBookEntryTree *next;
  OrderBookEntryTree *prev;

private:
  LimitTree *parentLimit;
};