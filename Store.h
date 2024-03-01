#ifndef STORE_H
#define STORE_H

#include "Utils.h"
#include "Client.h"
#include "Product.h"
#include "Seller.h"
#include "Order.h"
#include <algorithm>
using namespace std;

class Store {
public:
	Store();
	Store(std::string param_storeName);
	bool saveAllData();
	bool saveIndividualData(ArrayTypes elem);
	std::string getFileName(ArrayTypes category);
	std::size_t sizeOf(ArrayTypes arr);
    void addClient(Client &&elem);
    void addSeller(Seller &&elem);
    void addOrder(Order &&elem);
    void addProduct(Product &&elem);
    Client getClient(int i);
    Seller getSeller(int i);
	Order& getOrder(int i);
    Product getProduct(int i);
    void remove(ArrayTypes arr, int i);
    template <typename T>
	void add(ArrayTypes arr,const T &elem);
	int GetNumofclients()const;
	void sortClientsBy(ClientParams criteria) {
		sort(clients.begin(), clients.end(), [criteria](Client& a, Client& b) {
			return sortBy(a, b, criteria);
		});
	};
	
	void sortProductsBy(ProductParams criteria) {
		sort(products.begin(), products.end(), [criteria](Product& a, Product& b) {
			return sortBy(a, b, criteria);
		});
	};
	
	void sortSellersBy(SellerParams criteria) {
		sort(sellers.begin(), sellers.end(), [criteria](Seller& a, Seller& b) {
			return sortBy(a, b, criteria);
		});
	};
	
	void sortOrdersBy(OrderParams criteria) {
		sort(orders.begin(), orders.end(), [criteria](Order& a, Order& b) {
			return sortBy(a, b, criteria);
		});
	};
	Client getClientById(string id);
	Seller getSellerById(string id);
	Order getOrderById(string id);
	Product &getProductById(string id);
	Product getProductByName(string name);
	Seller getSellerByName(string name);
	Client getClientByName(string name);
	template <typename T>
	T get(ArrayTypes arr,int i);
	void sellProduct(string productId);
	
private:
	std::string storeName;
	std::vector<Client> clients;
	std::vector<Product> products;
	std::vector<Seller> sellers;
	std::vector<Order> orders;
};


#endif

