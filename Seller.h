#ifndef SELLER_H
#define SELLER_H

#include "Order.h"
#include <vector>
#include "EnumDefinitions.h"

class Order; // Evita deps circulares
struct SellerStruct{
	char id[25];
	char name[50];
	char phone[20];
	char email[250];
	
};
class Seller {
public:
	Seller();
    Seller(std::string a_name, std::string a_phone, std::string a_email);
    std::string get(SellerParams param) const;
    int getNumberOfOrders() const;
    float getTotalOrders() const;
    void edit(SellerParams param, std::string value);
	

private:
    std::string id;
	std::string name;
	std::string phone;
	std::string email;
};

#endif

