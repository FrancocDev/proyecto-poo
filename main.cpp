#include "Store.h"
#include "Utils.h"
#include <iostream>
#include <ctime>
#include "Client.h"
#include "Product.h"
#include "Seller.h"
using namespace std;

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	// Crear una instancia de la tienda
	Store myStore("Mi Tienda");
	
	// Agregar algunos elementos a la tienda (puedes modificar según tu implementación)
	myStore.addClient(Client("Juan Perez", "341984030", "Crespo 2042", "Santa Fe", "juanperez@gmail.com", editDate(23,10,1995)));
	myStore.addClient(Client("Tomas Gomez", "439876521", "San Juan 1049", "Santa fe", "tomasgomez@hotmail.com", editDate(13,01,1994)));
	myStore.addClient(Client("Laura Rodriguez", "341234567", "Mitre 789", "Santa Fe", "laurarodriguez@yahoo.com", editDate(15,05,1990)));
	myStore.addClient(Client("Ana Martinez", "341111111", "Belgrano 456", "Santa Fe", "anamartinez@gmail.com", editDate(20,12,1988)));
	myStore.addClient(Client("Pedro Sanchez", "342222222", "Urquiza 123", "Santa Fe", "pedrosanchez@gmail.com", editDate(5,7,1992)));
	myStore.addClient(Client("Maria Lopez", "342333333", "Pellegrini 987", "Santa Fe", "marialopez@hotmail.com", editDate(18,9,1998)));
	myStore.addClient(Client("Lucas Fernandez", "340000000", "San Martin 567", "Santa Fe", "lucasfernandez@gmail.com", editDate(2,9,1996)));
	
	myStore.saveIndividualData(CLIENT);
	
	
	myStore.addProduct(Product("S22 Ultra", "Samsung", 1029, 12));
	myStore.addProduct(Product("Galaxy A52", "Samsung", 429, 30));
	myStore.addProduct(Product("14 Pro", "Iphone", 1300, 15));
	myStore.addProduct(Product("Moto G72", "Motorola", 320, 50));
	myStore.saveIndividualData(PRODUCT);
	
	myStore.addSeller(Seller("Franco", "987654321", "franco@tienda.com"));
	myStore.addSeller(Seller("Juan", "123456789", "juan@tienda.com"));
	myStore.addSeller(Seller("Aramis", "123456789", "aramis@tienda.com"));
	myStore.saveIndividualData(SELLER);
	
	myStore.addOrder(Order(myStore.getSeller(0).get(SELLER_ID), myStore.getClient(1).get(CLIENT_ID), 20,2,2020));
	myStore.addOrder(Order(myStore.getSeller(1).get(SELLER_ID), myStore.getClient(0).get(CLIENT_ID), 20,3,2020));
	myStore.addOrder(Order(myStore.getSeller(0).get(SELLER_ID), myStore.getClient(4).get(CLIENT_ID), 22,2,2020));
	
	
	// Guardar datos en archivos
	myStore.saveAllData();
	
	// Ordenar elementos en la tienda (puedes modificar según tus criterios)
	myStore.sortClientsBy(CLIENT_NAME);
	myStore.sortProductsBy(PRODUCT_NAME);
	myStore.sortSellersBy(SELLER_NAME);
	
	// Imprimir elementos ordenados
	std::cout << "Clientes ordenados por nombre:\n";
	for(size_t i = 0; i < myStore.sizeOf(CLIENT) ; i++){
		cout<< myStore.getClient(i).get(CLIENT_NAME)<<endl;
	}
	
	std::cout << "Productos ordenados por nombre:\n";
	for(size_t i = 0; i < myStore.sizeOf(PRODUCT) ; i++){
		cout<< myStore.getProduct(i).get(PRODUCT_NAME)<<endl;
	}
	
	std::cout << "Vendedores ordenados por nombre:\n";
	for(size_t i = 0; i < myStore.sizeOf(SELLER) ; i++){
		cout<< myStore.getSeller(i).get(SELLER_NAME)<<endl;
	}
	
	std::cout << "Órdenes ordenadas por fecha:\n";
	for(int i = 0; i < myStore.sizeOf(ORDER) ; i++){
		cout<< "ID: "<< myStore.getOrder(i).get(SELL_ID)<< " - S:" << myStore.getOrder(i).get(SELL_SELLER) << " - C:" << myStore.getOrder(i).get(SELL_CLIENT)<< endl;
	}

	
	return 0;
}
