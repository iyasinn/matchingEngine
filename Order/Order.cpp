#include "Order.hpp"
#include <stdexcept>
using namespace std;

// Constructor
Order::Order(const IOrderCore *ordercoreIn, long priceIn,
             unsigned int quantityIn, bool isBuySideIn)
    : price(priceIn), initialQuantity(quantityIn), currentQuantity(quantityIn),
      isBuySide(isBuySideIn), ordercore(ordercoreIn) {}

long Order::getPrice() const { return price; }
unsigned int Order::getInitialQuantity() const { return initialQuantity; }
unsigned int Order::getCurrentQuantity() const { return currentQuantity; }
bool Order::getIsBuySide() const { return isBuySide; }

void Order::increaseQuantity(unsigned int quantityDelta) {
  currentQuantity += quantityDelta;
}
void Order::decreaseQuantity(unsigned int quantityDelta) {
  if (quantityDelta > currentQuantity) {
    throw std::invalid_argument(
        "Quantity Delta > Current Quantity for OrderID=" +
        to_string(ordercore->getOrderId()));
  }
  currentQuantity = min(currentQuantity, currentQuantity - quantityDelta);
}

long Order::getOrderId() const { return ordercore->getOrderId(); }
string Order::getUsername() const { return ordercore->getUsername(); }
int Order::getSecurityId() const { return ordercore->getSecurityId(); }