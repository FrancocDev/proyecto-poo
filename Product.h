#ifndef PRODUCT_H
#define PRODUCT_H
#include "Utils.h"
#include "EnumDefinitions.h"
struct Productstruct{
	char id[16];
	char name[25];
	char brand[25];
	float price;
	int quantity;
	char orderId[12];
};
class Product {
public:
	Product();
    Product(std::string a_name, std::string a_brand, float a_price, int a_quantity);
    std::string get(ProductParams param) const;

    float getPrice() const;
	void editPrice(float value);

    int getQuantity() const;

    void edit(ProductParams param, std::string value);

private:
    std::string id;
	std::string name;
	std::string brand;
	float price;
	int quantity;
};

#endif

