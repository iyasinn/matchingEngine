#pragma once
#include "../Order/Order.hpp"
#include "./ILimit.hpp"
#include "./OrderbookEntry.hpp"

class OrderBookEntryTree;

class LimitTree : public ILimit {
public:
  LimitTree(long priceIn) : ILimit(priceIn) {}
  // Interface functions
  uint getTotalOrders() { return totalOrders; }
  void changeTotalOrders(uint delta) { totalOrders += delta; }
  uint getTotalQuantity() { return totalQuantity; }
  void changeTotalQuantity(uint delta) { totalQuantity += delta; }
  bool empty() { return headPointer == tailPointer && tailPointer == nullptr; }

  // Member specific functions
  OrderBookEntryTree *head() const { return headPointer; }
  OrderBookEntryTree *tail() const { return tailPointer; }

private:
  OrderBookEntryTree *headPointer = nullptr;
  OrderBookEntryTree *tailPointer = nullptr;
  uint totalOrders = 0;
  uint totalQuantity = 0;
};

class OrderBookEntryTree : OrderBookEntry {
public:
  OrderBookEntryTree(Order orderIn) : OrderBookEntry(orderIn) {}
  LimitTree *getParentLimit() { return parentLimit; }
  OrderBookEntryTree *next;
  OrderBookEntryTree *prev;

private:
  LimitTree *parentLimit;
};