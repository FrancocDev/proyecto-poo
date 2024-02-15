#ifndef SELLER_H
#define SELLER_H

#include "Order.h"
#include <vector>
#include "EnumDefinitions.h"

class Order; // Evita deps circulares

class Seller {
public:
	Seller();
    Seller(std::string a_name, std::string a_phone, std::string a_email);
    std::string get(SellerParams param) const;
    int getNumberOfOrders() const;
    float getTotalOrders() const;
    void edit(SellerParams param, std::string value);
	void addOrder(Order a_order);

private:
    std::string id;
	std::string name;
	std::string phone;
	std::string email;
	std::vector<Order> orders;
};

#endif

