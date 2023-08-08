#pragma once
#include "OrderCore.hpp"

class Order : public IOrderCore {

public:
  // Constructor
  Order(const IOrderCore *ordercoreIn, long priceIn, unsigned int quantityIn,
        bool isBuySideIn);

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
  long price;
  unsigned int initialQuantity;
  unsigned int currentQuantity;
  bool isBuySide;
  const IOrderCore *ordercore;
};
