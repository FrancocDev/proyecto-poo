#ifndef ORDER_H
#define ORDER_H
#include "Utils.h"
#include "Product.h"
#include <vector>
#include "EnumDefinitions.h"
#include <string>
using namespace std;
///agregue

class Store;
class Product; // Evita deps circulares
struct OrderStruct{
	char orderId[12];
	char sellerid[12];
	char clientid[12];
	float ammount;
	time_t date;
};
class Order {
public:
	Order();
    Order(std::string a_sellerId, std::string a_clientId, int a_day, int a_month, int a_year);
    float getTotal() const;
    void edit(OrderParams param, std::string value);
	void addProduct(const std::string& a_product);
    time_t getDate() const;
    std::string get(OrderParams param) const;
	float getAmmount(Store& store);
	int getNumOfProducts();
	time_t editOrderDate(time_t newDate);
	void clearProducts();
	string getProductId(int i);
private:
	std::string id;
	std::string sellerId;
	std::string clientId;
	time_t date;
	std::vector<string> products;
	float ammount;
};

#endif

