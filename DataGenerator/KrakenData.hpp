#include "../external/nlohmann/json.hpp"
#include <ctime>
#include <curl/curl.h>
#include <iostream>
class KrakenData {

public:
  KrakenData(std::string securityIn, uint numOrdersIn)
      : security(securityIn), numOrders(numOrdersIn) {}

  void makeRequest() {
    std::cout << numOrders << std::endl;
    CURL *curl = curl_easy_init();
    if (!curl) {
      std::cout << "Failed to initialize cURL\n";
      return;
    }

    std::string responseBuffer;
    // Set the URL and write callback function
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
                     WriteCallback); // Uncomment this line if needed

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      std::cerr << "cURL request failed: " << curl_easy_strerror(res)
                << std::endl;
      curl_easy_cleanup(curl);
      return;
    }

    curl_easy_cleanup(curl);

    // Parse JSON response
    using json = nlohmann::json;

    try {
      json jsonData = json::parse(responseBuffer);
      std::string value = jsonData["key"];
      std::cout << "Value from JSON: " << value << std::endl;
    } catch (const std::exception &e) {
      std::cerr << "JSON parsing error: " << e.what() << std::endl;
      return;
    }
  }

  // const std::string url = "https://api.kraken.com/0/public/Trades?";
  std::string url = "https://api.kraken.com/0/public/Trades?pair=XBTUSD";

  std::string security;
  uint numOrders;
  // std::time_t lastTime;
};