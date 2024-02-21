#include "Product.h"
#include "Utils.h"

Product::Product(){};
Product::Product(std::string a_name,std::string a_brand, float a_price, int a_quantity) 
{
    id=generateRandomID(11); /// No deberia colisionar nunca
	name=a_name;
    brand=a_brand;
    price=a_price;
    quantity=a_quantity;
}

std::string Product::get(ProductParams param) const {
	switch (param)
    {
    case PRODUCT_ID:
        return id;
        break;
    case PRODUCT_NAME:
        return name;
        break;
    case PRODUCT_BRAND:
        return brand;
        break;
    default:
		return "";
        break;
    };
}

float Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::edit(ProductParams param, std::string value) { 
    switch (param)
    {
    case PRODUCT_NAME:
        name = value;
        break;
    case PRODUCT_BRAND:
        brand = value;
        break;
    case PRODUCT_PRICE:
        price = std::stof(value);
        break;
    case PRODUCT_QUANTITY:
        quantity = std::stoi(value);
        break;
	case PRODUCT_ID:
		id = value;
    default:
        break;
    }; 
}
