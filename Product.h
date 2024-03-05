#ifndef PRODUCT_H
#define PRODUCT_H
#include "Utils.h"
#include "EnumDefinitions.h"
#include <string>
using namespace std;
struct Productstruct{
	char id[16];
	char name[25];
	char brand[25];
	float price;
	int quantity;
};
class Product {
public:
	Product();
    Product(std::string a_name, std::string a_brand, float a_price, int a_quantity);
    std::string get(ProductParams param) const;

    float getPrice() const;
	void editPrice(float value);

    int getQuantity() const;
	void sellProduct();
    void edit(ProductParams param, std::string value);
//	string getbrand()const;
//	string getname()const;
	bool operator<(const Product& other) const;
	void restoreProduct();
private:
    std::string id;
	std::string name;
	std::string brand;
	float price;
	int quantity;
};

#endif

