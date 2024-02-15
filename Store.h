#ifndef STORE_H
#define STORE_H

#include "Utils.h"
#include "Client.h"
#include "Product.h"
#include "Seller.h"
#include "Order.h"
#include <algorithm>
#include "Store.h"
using namespace std;

class Store {
public:
	Store();
	Store(std::string param_storeName);
	bool saveAllData();
	bool saveIndividualData(ArrayTypes elem);
	std::string getFileName(ArrayTypes category);
	std::size_t sizeOf(ArrayTypes arr);
	void remove(ArrayTypes arr, int i);
	template <typename T>
	void add(ArrayTypes arr,const T &elem);
	template <typename EnumType, typename ElementType>
	void Sort(ArrayTypes arr, EnumType criteria) {
		switch (arr) {
		case CLIENT:
			sort(clients.begin(), clients.end(), [criteria](ElementType& a, ElementType& b) {
				return sortBy(a, b, criteria);
			});
		break;
		case PRODUCT:
			sort(products.begin(), products.end(), [criteria](ElementType& a, ElementType& b) {
				return sortBy(a, b, criteria);
			});
		break;
		case SELLER:
			sort(sellers.begin(), sellers.end(), [criteria](ElementType& a, ElementType& b) {
				return sortBy(a, b, criteria);
			});
		break;	
		case ORDER:
			sort(orders.begin(), orders.end(), [criteria](ElementType& a, ElementType& b) {
				return sortBy(a, b, criteria);
			});
		break;
		default:
			break;
		}
	};
	template <typename T>
	T get(ArrayTypes arr,int i);
	
private:
	std::string storeName;
	std::vector<Client> clients;
	std::vector<Product> products;
	std::vector<Seller> sellers;
	std::vector<Order> orders;
};


#endif

