#pragma once
#include <iostream>

class ILimit {
public:
  ILimit(long priceIn) : price(priceIn) {}

  virtual uint getTotalOrders() = 0;
  virtual uint getTotalQuantity() = 0;
  virtual void changeTotalOrders(uint delta) = 0;
  virtual void changeTotalQuantity(uint delta) = 0;
  virtual bool empty() = 0;
  long getPrice() const { return price; }

private:
  long price;
};