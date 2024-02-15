#include "Order.h"
#include <vector>
#include "Utils.h"
#include "Product.h"

Order::Order(){};
Order::Order(std::string a_sellerId, std::string a_clientId, int a_day, int a_month, int a_year)
{
    id=generateRandomID(12); /// No deberia colisionar nunca
	sellerId= a_sellerId;
    clientId= a_clientId;
    products=std::vector<Product>();
    ammount=0;
    date=editDate(a_day, a_month, a_year);
}

std::string Order::get(OrderParams param) const {
	switch (param)
    {
    case SELLER_ID:
        return id;
        break;
    case SELL_CLIENT:
        return clientId;
        break;
    case SELL_SELLER:
        return sellerId;
        break;
    default:
		return "";
        break;
    };
};

float Order::getTotal() const {
    float total=0;
    for (auto &product : products) {
        total+=product.getPrice();
    }
    return total;
}

void Order::edit(OrderParams param, std::string value) { 
    switch (param)
    {
    case SELL_CLIENT:
        clientId = value;
        break;
    case SELL_SELLER:
        sellerId = value;
        break;
    default:
        break;
    }; 
};

void Order::addProduct(Product a_product) {
    products.push_back(a_product);
};

time_t Order::getDate() const {
    return date;
};
