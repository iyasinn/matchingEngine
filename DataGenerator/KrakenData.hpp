#include "../external/nlohmann/json.hpp"
#include <ctime>
#include <curl/curl.h>
#include <iostream>
#include <vector>

using namespace std;

struct KrakenOrder {
  int name;
  time_t timeCreated;
  double price;
  double volume;
  bool isBuySide;
  bool limitOrder;
};

class KrakenData {

public:
  KrakenData(std::string securityIn, uint numOrdersIn)
      : security(securityIn), numOrders(numOrdersIn) {}

  std::vector<KrakenOrder> getOrders() {

    std::string jsonString = makeRequest();
    nlohmann::json data = nlohmann::json::parse(jsonString);
    auto orders = data["result"]["XXBTZUSD"];
    double order = stod(string(orders[0][0]));
    std::cout << order << std::endl;

    // std::string lastValue = data["last"];
    // std::cout << lastValue;
    return {};
  }

  auto handleOrder(auto order) {}

private:
  // const std::string url = "https://api.kraken.com/0/public/Trades?";
  std::string url =
      "https://api.kraken.com/0/public/Trades?pair=XBTUSD&count=10";

  std::string security;
  uint numOrders;

  static size_t WriteCallback(void *contents, size_t size, size_t nmemb,
                              void *userp) {
    ((std::string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
  }

  std::string makeRequest() {
    CURL *curl;
    CURLcode res = CURLcode();
    std::string readBuffer;

    curl = curl_easy_init();
    if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      res = curl_easy_perform(curl);
      curl_easy_cleanup(curl);
    }

    if (res != 0) {
      std::cerr << "Error getting trades\n";
    }

    return readBuffer;
  }

  KrakenOrder createOrder() { return KrakenOrder(); }
  // std::time_t lastTime;
};