#pragma once
#include "IOrderCore.hpp"
#include "OrderCore.hpp"
#include <memory>

/*
Using an objec tordercore
Will deal with other ordercores with polymorphism later
But currently the current interface should not change much
*/

class Order : public IOrderCore {

public:
  // Constructor
  // Order(const IOrderCore *ordercoreIn, long priceIn, unsigned int quantityIn,
  //       bool isBuySideIn);
  Order(OrderCore ordercoreIn, long priceIn, unsigned int quantityIn,
        bool isBuySideIn)
      : ordercore(ordercoreIn), price(priceIn), initialQuantity(quantityIn),
        currentQuantity(quantityIn), isBuySide(isBuySideIn) {}

  // Order(long orderIdIn, std::string usernameIn, int securityIDIn, long
  // priceIn,
  //       unsigned int quantityIn, bool isBuySideIn)
  //     : Order(new OrderCore(orderIdIn, usernameIn, securityIDIn),
  //     priceIn,
  //             quantityIn, isBuySideIn) {}

  // Change quantity
  void increaseQuantity(unsigned int quantityDelta);
  void decreaseQuantity(unsigned int quantityDelta);

  // Derived getters
  long getOrderId() const;
  std::string getUsername() const;
  int getSecurityId() const;

  // Current class getters
  long getPrice() const;
  unsigned int getInitialQuantity() const;
  unsigned int getCurrentQuantity() const;
  bool getIsBuySide() const;

private:
  OrderCore ordercore;
  long price;
  unsigned int initialQuantity;
  unsigned int currentQuantity;
  bool isBuySide;
};
