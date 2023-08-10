#include "Order.hpp"
#include <stdexcept>
using namespace std;

unsigned int Order::getInitialQuantity() const { return initialQuantity; }
unsigned int Order::getCurrentQuantity() const { return currentQuantity; }
bool Order::getIsBuySide() const { return isBuySide; }
long Order::getPrice() const { return price; }

void Order::increaseQuantity(unsigned int quantityDelta) {
  currentQuantity += quantityDelta;
}

void Order::decreaseQuantity(unsigned int quantityDelta) {
  if (quantityDelta > currentQuantity) {
    throw std::invalid_argument(
        "Quantity Delta > Current Quantity for OrderID=" +
        to_string(ordercore.getOrderId()));
  }
  currentQuantity = min(currentQuantity, currentQuantity - quantityDelta);
}

long Order::getOrderId() const { return ordercore.getOrderId(); }
string Order::getUsername() const { return ordercore.getUsername(); }
int Order::getSecurityId() const { return ordercore.getSecurityId(); }
