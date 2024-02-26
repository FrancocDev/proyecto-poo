#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Client.h"
#include "Product.h"
#include "Order.h"
#include "Seller.h"
#include "EnumDefinitions.h"

// Forward declarations
class Seller;
class Order;
class Product;

struct productFile {
	char productId[12];
	char orderId[12];
};

bool sortBy(const Client& elem1, const Client& elem2, ClientParams criteria);
bool sortBy(const Order& elem1, const Order& elem2, OrderParams criteria);
bool sortBy(const Product& elem1, const Product& elem2, ProductParams criteria);
bool sortBy(const Seller& elem1, const Seller& elem2, SellerParams criteria);

void tolower(std::string &s);
std::string generateRandomID(int length);
time_t editDate(int day, int month, int year);
time_t parseDateToTimeT(std::string dateStr);
#endif
