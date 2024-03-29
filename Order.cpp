#include "Order.h"
#include <vector>
#include "Utils.h"
#include "Product.h"
#include <iostream>
#include "Store.h"

using namespace std;

Order::Order(){};
Order::Order(std::string a_sellerId, std::string a_clientId, int a_day, int a_month, int a_year)
{
    id=generateRandomID(11); /// No deberia colisionar nunca
	sellerId= a_sellerId;
    clientId= a_clientId;
	products=std::vector<string>();
    ammount=0;
    date=editDate(a_day, a_month, a_year);
}

std::string Order::get(OrderParams param) const {
	switch (param)
    {
    case SELL_ID:
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

//float Order::getTotal() const {
//    float total=0;
//    for (auto &product : products) {
//        total+=product.getPrice();
//    }
   /* return total;*/
/*}*/
///agregue
int Order::getNumOfProducts(){
	return products.size();
}
///
void Order::edit(OrderParams param, std::string value) { 
    switch (param)
    {
	case SELL_ID:
		id = value;
		break;
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

void Order::addProduct(const std::string& a_product) {
	products.push_back(a_product);
}

time_t Order::getDate() const {
    return date;
};
///agregue
float Order:: getAmmount(Store& store){
	int total = 0;
	for(int i = 0; i < products.size(); i++){
		total += store.getProductById(getProductId(i)).getPrice();
	}
	return total;
}
time_t Order::editOrderDate(time_t newDate){
	date = newDate;
};

void Order::clearProducts(){
	products.clear();
}

string Order::getProductId(int i) {
	return products[i];
}

