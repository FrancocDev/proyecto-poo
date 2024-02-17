#ifndef ORDER_H
#define ORDER_H
#include "Utils.h"
#include "Product.h"
#include <vector>
#include "EnumDefinitions.h"

class Product; // Evita deps circulares

class Order {
public:
	Order();
    Order(std::string a_sellerId, std::string a_clientId, int a_day, int a_month, int a_year);
    float getTotal() const;
    void edit(OrderParams param, std::string value);
	void addProduct(Product a_product);
    time_t getDate() const;
    std::string get(OrderParams param) const;
private:
	std::string id;
	std::string sellerId;
	std::string clientId;
	time_t date;
	std::vector<Product> products;
	float ammount;
};

#endif

