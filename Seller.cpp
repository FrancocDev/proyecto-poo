#include "Seller.h"
#include "Order.h"
#include <vector>

Seller::Seller(){};
Seller::Seller(std::string a_name,std::string a_phone, std::string a_email) 
{
    id=generateRandomID(12); /// No deberia colisionar nunca
	name=a_name;
    phone=a_phone;
	email=a_email;
    orders=std::vector<Order>();
}

std::string Seller::get(SellerParams param) const {
	switch (param)
    {
    case SELLER_ID:
        return id;
        break;
    case SELLER_NAME:
        return name;
        break;
    case SELLER_PHONE:
        return phone;
        break;
    case SELLER_EMAIL:
        return email;
        break;
    default:
		return "";
        break;
    }; 
}
int Seller::getNumberOfOrders() const {
    return orders.size();
}

float Seller::getTotalOrders() const {
    float total=0;
    for (auto &order : orders) {
        total+=order.getTotal();
    }
    return total;
};

void Seller::edit(SellerParams param, std::string value) { 
    switch (param)
    {
    case SELLER_NAME:
        name = value;
        break;
    case SELLER_PHONE:
        phone = value;
        break;
    case SELLER_EMAIL:
        email = value;
        break;
    default:
        break;
    }; 
}

void Seller::addOrder(Order a_order) {
    orders.push_back(a_order);
}
