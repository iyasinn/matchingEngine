#pragma once
#include "../Limit/LimitComparer.hpp"
#include "../Limit/LimitTree.hpp"
#include "IOrderbook.hpp"
#include <set>

class fifoBstOrderbook : protected IOrderbook {
public:
  fifoBstOrderbook(std::string securityIn) : IOrderbook(securityIn) {}
  // Make a class to return success of these operations
  void addOrder(Order order) override;
  void changeOrder(Order order) override;
  void removeOrder(Order order) override;
  // Make a class with al information from matching some orders
  void matchOrders() override;
  // bool containsOrder(long orderId);
  int getCount() override;
  bool empty() override { return count == 0; }
  std::vector<OrderBookEntry> getAskOrders() override;
  std::vector<OrderBookEntry> getBidOrders() override;

private:
  std::set<LimitTree, decltype(BidComparer())> buyOrders;
  std::set<LimitTree, decltype(AskComparer())> askOrders;
  int count = 0;
};