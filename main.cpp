#include "./Order/Order.hpp"
#include "./Orderbook/fifoBSTOrderbook.hpp"
#include "Order/OrderCore.hpp"
#include <ctime>
#include <iostream>
using namespace std;

int main() {

  fifoBstOrderbook orderbook("Apple");

  orderbook.addOrder(Order(new OrderCore(10, "shadowio", 15), 30, 100, true));

  orderbook.addOrder(Order(new OrderCore(10, "shadowio", 15), 25, 100, true));

  orderbook.addOrder(Order(new OrderCore(10, "shadowio", 15), 10, 100, true));

  orderbook.addOrder(Order(new OrderCore(10, "shadowio", 15), 10, 100, true));

  orderbook.addOrder(Order(new OrderCore(10, "shadowio", 15), 10, 100, true));

  orderbook.changeOrder(
      Order(new OrderCore(10, "shadowio", 15), 30, 100, true));
}