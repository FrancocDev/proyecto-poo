#include "Store.h"
#include "Utils.h"
#define NOT_FOUND -1
#include <fstream>
#include <iostream>
#include "Client.h"
#include "Product.h"
#include "Seller.h"
#include "Order.h"
#include <algorithm>
#include <cstring>
using namespace std;

Store::Store(std::string param_storeName) {
	storeName = param_storeName;
	for (int elem = ArrayTypes::CLIENT; elem <= ArrayTypes::ORDER; elem++) {
		std::ifstream file(getFileName(static_cast<ArrayTypes>(elem)), std::ios::binary | std::ios::in);
		
	if (file.is_open()) {
		Client clientElement;
		Product productElement;
		Seller sellerElement;
		Order orderElement;
		
		switch (elem) {
		case CLIENT: {
			clientStruct clientReg;
			while (file.read(reinterpret_cast<char*>(&clientReg), sizeof(clientStruct))) {
				clientElement.edit(CLIENT_ID, clientReg.id);
				clientElement.edit(CLIENT_NAME, clientReg.name);
				clientElement.edit(CLIENT_PHONE, clientReg.phone);
				clientElement.edit(CLIENT_ADDRESS, clientReg.address);
				clientElement.edit(CLIENT_CITY, clientReg.city);
				clientElement.edit(CLIENT_EMAIL, clientReg.email);
				clientElement.editBirthday(clientReg.birthday);
				clients.push_back(clientElement);
			}
			break;
		}
		case ORDER: {
			OrderStruct orderReg;
			while (file.read(reinterpret_cast<char*>(&orderReg), sizeof(OrderStruct))) {
				orderElement.edit(SELL_ID, orderReg.orderId);
				orderElement.edit(SELL_CLIENT, orderReg.clientid);
				orderElement.edit(SELL_SELLER, orderReg.sellerid);
				orderElement.editOrderDate(orderReg.date);
				orderElement.clearProducts();
				
				for (const auto& productId : orderReg.products) {
					auto it = find_if(products.begin(), products.end(), [productId](const Product& product){
						return productId == product.get(PRODUCT_ID);
					});
					if (it != products.end()){
						orderElement.addProduct(*it);
					} else {
						cout << "No se encontro la id del producto: " << productId<<endl;
					}
				}
				orders.push_back(orderElement);
			}
			break;
		}
		case SELLER: {
			SellerStruct sellerstruct;
			while (file.read(reinterpret_cast<char*>(&sellerstruct), sizeof(SellerStruct))) {
				sellerElement.edit(SELLER_ID,sellerstruct.id);
				sellerElement.edit(SELLER_NAME,sellerstruct.name);
				sellerElement.edit(SELLER_PHONE,sellerstruct.phone);
				sellerElement.edit(SELLER_EMAIL,sellerstruct.email);
				sellers.push_back(sellerElement);
			}
			break;
		}
		case PRODUCT: {
			Productstruct producstruct;
			while (file.read(reinterpret_cast<char*>(&producstruct), sizeof(Productstruct))) {
				productElement.edit(PRODUCT_NAME, producstruct.name);
				productElement.edit(PRODUCT_ID, producstruct.id);
				productElement.edit(PRODUCT_BRAND, producstruct.brand);
				productElement.edit(PRODUCT_PRICE, to_string(producstruct.price));
				productElement.edit(PRODUCT_QUANTITY, to_string(producstruct.quantity));
				products.push_back(productElement);
			}
			break;
		}
		}
		
		file.close();
	} else {
		std::ofstream createFile(getFileName(static_cast<ArrayTypes>(elem)), std::ios::binary | std::ios::out);
		std::cerr << "No se pudo abrir el archivo: " << getFileName(static_cast<ArrayTypes>(elem)) << std::endl;
	}
}
};

std::string Store::getFileName(ArrayTypes category) {
	switch (category) {
	case CLIENT:
		return "client.dat";
	case PRODUCT:
		return "product.dat";
	case SELLER:
		return "seller.dat";
	case ORDER:
		return "order.dat";
	default:
		return "";
	}
}

bool Store::saveIndividualData(ArrayTypes elem) {
	std::ofstream file(getFileName(elem), std::ios::binary | std::ios::out);
	if (file.is_open()) {
		int size = sizeOf(elem);
		
		Client clientElement;
		Product productElement;
		Seller sellerElement;
		Order orderElement;
		int numberOfProducts;
		OrderStruct orderstruct;
		
		for (int i=0;i<size;i++){
			switch (elem) {
			case CLIENT:
				clientElement = clients[i];
				clientStruct reg;
				
				strcpy(reg.id, clientElement.get(CLIENT_ID).c_str());
				strcpy(reg.name, clientElement.get(CLIENT_NAME).c_str());
				strcpy(reg.phone, clientElement.get(CLIENT_PHONE).c_str());
				strcpy(reg.address, clientElement.get(CLIENT_ADDRESS).c_str());
				strcpy(reg.city, clientElement.get(CLIENT_CITY).c_str());
				strcpy(reg.email, clientElement.get(CLIENT_EMAIL).c_str());
				reg.birthday = clientElement.getBirthday();
				
				file.write(reinterpret_cast<char*>(&reg), sizeof(clientStruct));
				break;
			case PRODUCT:
				productElement = products[i];
				Productstruct productreg;
				
				strcpy(productreg.id, productElement.get(PRODUCT_ID).c_str());
				strcpy(productreg.name, productElement.get(PRODUCT_NAME).c_str());
				strcpy(productreg.brand, productElement.get(PRODUCT_BRAND).c_str());
				productreg.price = productElement.getPrice();
				productreg.quantity = productElement.getQuantity();
				
				file.write(reinterpret_cast<char*>(&productreg), sizeof(Productstruct));
				break;
				
			case SELLER:
				sellerElement = sellers[i];
				SellerStruct sellerstruct;
				
				strcpy(sellerstruct.id, sellerElement.get(SELLER_ID).c_str());
				strcpy(sellerstruct.name, sellerElement.get(SELLER_NAME).c_str());
				strcpy(sellerstruct.phone, sellerElement.get(SELLER_PHONE).c_str());
				strcpy(sellerstruct.email, sellerElement.get(SELLER_EMAIL).c_str());
	
				file.write(reinterpret_cast<char*>(&sellerstruct), sizeof(SellerStruct));
				break;	
			case ORDER:
				orderElement = orders[i];
				numberOfProducts = orderElement.getNumOfProducts();
				orderstruct.products.clear();
				
				strcpy(orderstruct.orderId, orderElement.get(SELL_ID).c_str());
				strcpy(orderstruct.sellerid, orderElement.get(SELL_SELLER).c_str());
				strcpy(orderstruct.clientid, orderElement.get(SELL_CLIENT).c_str());
				orderstruct.ammount = orderElement.getAmmount();
				orderstruct.date = orderElement.getDate();
				for (int j = 0; j < numberOfProducts; j++) {
					orderstruct.products.push_back(products[j].get(PRODUCT_ID));
				}
				file.write(reinterpret_cast<char*>(&orderstruct), sizeof(OrderStruct));
				
				cout<< "----------ESCRITURA----------"<<endl;
				cout<< "ST OrderId: "<< orderstruct.orderId<<endl;
				cout<< "ST SellerId: "<< orderstruct.sellerid<<endl;
				cout<< "ST ClientId: "<< orderstruct.clientid<<endl;
				cout<< "CL OrderId:"<< orderElement.get(SELL_ID)<<endl;
				cout<< "CL SellerId:"<< orderElement.get(SELL_SELLER)<<endl;
				cout<< "CL ClientId:"<< orderElement.get(SELL_CLIENT)<<endl;
				
				break;
				
			default:
				return false;
				break;
			}
		}
		file.close();
		return true;
	} else {
		std::cerr << "No se pudo abrir el archivo: " << getFileName(elem) << std::endl;
		return false;
	}
}

bool Store::saveAllData(){
	int counter = 0;
	for(ArrayTypes elem : {ArrayTypes::CLIENT, ArrayTypes::PRODUCT, ArrayTypes::ORDER, ArrayTypes::SELLER} ){
		if(saveIndividualData(elem)) counter++;
	}
	return counter == 4;
}

std::size_t Store::sizeOf(ArrayTypes arr) {
	switch (arr) {
		case CLIENT:
			return clients.size();
			break;
		case PRODUCT:
			return products.size();
			break;
		case SELLER:
			return sellers.size();
			break;	
		case ORDER:
			return orders.size();
			break;
		default:
			return 0;
		break;
		}
	return 0;
}

void Store::addClient(Client &&elem) {
	clients.push_back(elem);
}

void Store::addSeller(Seller &&elem) {
	sellers.push_back(elem);
}

void Store::addOrder(Order &&elem) {
	orders.push_back(elem);
}

void Store::addProduct(Product &&elem) {
	products.push_back(elem);
}

Client Store::getClient(int i) {
	return clients[i];
}
Seller Store::getSeller(int i) {
	return sellers[i];
}
Order Store::getOrder(int i) {
	return orders[i];
}
Product Store::getProduct(int i) {
	return products[i];
}

void Store::remove(ArrayTypes arr, int i) {
		switch (arr) {
		case CLIENT:
			clients.erase(clients.begin()+i);
			break;
		case PRODUCT:
			products.erase(products.begin()+i);
			break;
		case SELLER:
			sellers.erase(sellers.begin()+i);
			break;	
		case ORDER:
			orders.erase(orders.begin()+i);
			break;
		default:
			break;
	}
}

