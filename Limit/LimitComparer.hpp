// relies on the Limit interface, which requires a Limit to have a getPrice
// function
#pragma once
#include "./ILimit.hpp"

class BidComparer {
public:
  bool operator()(const ILimit &first, const ILimit &second) const {
    return first.getPrice() < second.getPrice();
  }
};

class AskComparer {
public:
  bool operator()(const ILimit &first, const ILimit &second) const {
    return first.getPrice() < second.getPrice();
  }
};