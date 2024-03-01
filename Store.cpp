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
#include <sstream>
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
				productElement.editPrice(producstruct.price);
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
	
	std::ifstream productBin("product_to_order.dat", std::ios::binary | std::ios::in);
	if(productBin.is_open()){
	productFile productBinAux;
	while (productBin.read(reinterpret_cast<char*>(&productBinAux), sizeof (productFile))){
		cout<<"orderId: "<< productBinAux.orderId << endl ;
		cout<<"productId: "<< productBinAux.productId << endl ; 
		
		for(size_t i = 0; i < orders.size(); i++){
			if(productBinAux.orderId == getOrder(i).get(SELL_ID)){
				std::string productIdString(productBinAux.productId);
				getOrder(i).addProduct(productIdString);
				continue;
			}
		}
	}
	productBin.close();
	} else {
		std::ofstream createFile("product_to_order.dat", std::ios::binary | std::ios::out);
		std::cerr << "No se pudo abrir el archivo: " << "product_to_order.dat" << std::endl;
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
	std::ofstream file(getFileName(elem), std::ios::binary | std::ios::out | std::ios::in);
	std::ofstream productBin("product_to_order.dat", std::ios::binary | std::ios::out | std::ios::in);
	if (!productBin.is_open()) {
		std::cerr << "No se pudo abrir el archivo 'product_to_order.dat'" << std::endl;
		file.close();
		return false;
	}
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
				strcpy(orderstruct.orderId, orderElement.get(SELL_ID).c_str());
				strcpy(orderstruct.sellerid, orderElement.get(SELL_SELLER).c_str());
				strcpy(orderstruct.clientid, orderElement.get(SELL_CLIENT).c_str());
				/// orderstruct.ammount = orderElement.getTotal();
				orderstruct.date = orderElement.getDate();
				file.write(reinterpret_cast<char*>(&orderstruct), sizeof(OrderStruct));	
				
				productFile productTemp;
				for(size_t j = 0; j < numberOfProducts; j++){
				strcpy(productTemp.orderId, orderElement.get(SELL_ID).c_str());
				strcpy(productTemp.productId, orderElement.getProductId(j).c_str());
					
				productBin.write(reinterpret_cast<char*>(&productTemp), sizeof(productFile));
				}
											
				break;
				
			default:
				return false;
				break;
			}
		}
		file.close();
		productBin.close();
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
int Store::GetNumofclients()const{
	return clients.size();
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
Order& Store::getOrder(int i) {
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

Client Store::getClientById(string id) {
	auto clientComparator = [id](const Client& a) -> bool {
		return a.get(CLIENT_ID) == id;
	};
	
	auto it = std::find_if(clients.begin(), clients.end(), clientComparator);
	
	if (it != clients.end()) {
		return *it;
	} else {
		return Client(); 
	}
}

Seller Store::getSellerById(string id) {
	auto sellerComparator = [id](const Seller& s) -> bool {
		return s.get(SELLER_ID) == id;
	};
	
	auto it = std::find_if(sellers.begin(), sellers.end(), sellerComparator);
	
	if (it != sellers.end()) {
		return *it;
	} else {
		return Seller(); 
	}
}
Order Store::getOrderById(string id) {
	auto orderComparator = [id](const Order& o) -> bool {
		return o.get(SELL_ID) == id;
	};
	
	auto it = std::find_if(orders.begin(), orders.end(), orderComparator);
	
	if (it != orders.end()) {
		return *it;
	} else {
		return Order(); 
	}
}
Product Store::getProductById(string id) {
	auto productComparator = [id](const Product& p) -> bool {
		return p.get(PRODUCT_ID) == id;
	};
	
	auto it = std::find_if(products.begin(), products.end(), productComparator);
	
	if (it != products.end()) {
		return *it;
	} else {
		return Product(); 
	}
}

Product Store::getProductByName(string name) {
	auto productComparator = [name](const Product& p) -> bool {
		return p.get(PRODUCT_NAME) == name;
	};
	
	auto it = std::find_if(products.begin(), products.end(), productComparator);
	
	if (it != products.end()) {
		return *it;
	} else {
		return Product(); 
	}
}

Seller Store::getSellerByName(string name) {
	auto sellerComparator = [name](const Seller& s) -> bool {
		return s.get(SELLER_NAME) == name;
	};
	
	auto it = std::find_if(sellers.begin(), sellers.end(), sellerComparator);
	
	if (it != sellers.end()) {
		return *it;
	} else {
		return Seller(); 
	}
}

Client Store::getClientByName(string name) {
	auto clientComparator = [name](const Client& c) -> bool {
		return c.get(CLIENT_NAME) == name;
	};
	
	auto it = std::find_if(clients.begin(), clients.end(), clientComparator);
	
	if (it != clients.end()) {
		return *it;
	} else {
		return Client(); 
	}
}


void Store::sellProduct(string productId){
	Product product = getProductById(productId);
	product.sellProduct();
}
