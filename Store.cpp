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
			while (file.read(reinterpret_cast<char*>(&clientElement), sizeof(Client))) {
				clients.push_back(clientElement);
			}
			break;
		}
		case ORDER: {
			while (file.read(reinterpret_cast<char*>(&orderElement), sizeof(Order))) {
				orders.push_back(orderElement);
			}
			break;
		}
		case SELLER: {
			while (file.read(reinterpret_cast<char*>(&sellerElement), sizeof(Seller))) {
				sellers.push_back(sellerElement);
			}
			break;
		}
		case PRODUCT: {
			while (file.read(reinterpret_cast<char*>(&productElement), sizeof(Product))) {
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
		
		for (int i=0;i<size;i++){
			switch (elem) {
			case CLIENT:
				clientElement = clients[i];
				file.write(reinterpret_cast<char*>(&clientElement), sizeof(Client));
				break;
			case PRODUCT:
				productElement = products[i];
				file.write(reinterpret_cast<char*>(&productElement), sizeof(Product));
				break;
			case SELLER:
				sellerElement = sellers[i];
				file.write(reinterpret_cast<char*>(&sellerElement), sizeof(Seller));
				break;	
			case ORDER:
				orderElement = orders[i];
				file.write(reinterpret_cast<char*>(&orderElement), sizeof(Order));
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

