#pragma once
#include <iostream>

class IOrderCore {
public:
  virtual long getOrderId() const = 0;         // Pure virtual function
  virtual std::string getUsername() const = 0; // Pure virtual function
  virtual int getSecurityId() const = 0;       // Pure virtual function
};