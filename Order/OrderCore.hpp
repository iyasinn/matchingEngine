
#pragma once
#include "./IOrderCore.hpp"

class OrderCore : public IOrderCore {
public:
  OrderCore(long orderIdIn, std::string usernameIn, int securityIdIn) {
    orderId = orderIdIn;
    username = usernameIn;
    securityId = securityIdIn;
  }

  long getOrderId() const override { return orderId; }
  std::string getUsername() const override { return username; }
  int getSecurityId() const override { return securityId; }

private:
  long orderId;
  std::string username;
  int securityId;
};