#include "./Order/Order.hpp"
#include "./Orderbook/fifoBSTOrderbook.hpp"
#include "DataGenerator/KrakenData.hpp"
#include "Order/OrderCore.hpp"
#include <ctime>
#include <iostream>
using namespace std;

int main() {

  KrakenData k("Bobby", 10);
  k.makeRequest();

  //   fifoBstOrderbook orderbook("Apple");
  //   int orderId = 1;
  //   string username = "shadowIo";
  //   long securityId = 10;

  //   bool buySide = true;
  //   bool sellSide = false;

  //   orderbook.addOrder(
  //       Order(OrderCore(orderId++, username, securityId), 18, 100, buySide));
  //   orderbook.addOrder(
  //       Order(OrderCore(orderId++, username, securityId), 17, 100,
  //       sellSide));
  //   orderbook.addOrder(
  //       Order(OrderCore(orderId++, username, securityId), 17, 100,
  //       sellSide));
  //   orderbook.addOrder(
  //       Order(OrderCore(orderId++, username, securityId), 20, 100,
  //       sellSide));

  //   // PRINTING RNADOM
  //   orderbook.printOrders();
  //   // REMOVE 17
  //   orderbook.changeOrder(
  //       Order(OrderCore(orderId - 2, username, securityId), 20, 50,
  //       sellSide));

  //   orderbook.printOrders();
}