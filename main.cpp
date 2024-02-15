#include "Store.h"
#include "Utils.h"
#include <iostream>
#include <ctime>
#include "Client.h"
#include "Product.h"
#include "Seller.h"
using namespace std;

int main() {
	// Crear una instancia de la tienda
	Store myStore("Mi Tienda");
	
	// Agregar algunos elementos a la tienda (puedes modificar según tu implementación)
	myStore.add(ArrayTypes::CLIENT, Client("Juan Perez", "341984030", "Crespo 2042", "Santa Fe", "juanperez@gmail.com", editDate(23,10,1995)));
	myStore.add(ArrayTypes::CLIENT, Client("Tomas Gomez", "439876521", "San Juan 1049", "Santa fe", "tomasgomez@hotmail.com", editDate(13,01,1994)));
	myStore.add(ArrayTypes::CLIENT, Client("Laura Rodriguez", "341234567", "Mitre 789", "Santa Fe", "laurarodriguez@yahoo.com", editDate(15,05,1990)));
	myStore.add(ArrayTypes::CLIENT, Client("Ana Martinez", "341111111", "Belgrano 456", "Santa Fe", "anamartinez@gmail.com", editDate(20,12,1988)));
	myStore.add(ArrayTypes::CLIENT, Client("Pedro Sanchez", "342222222", "Urquiza 123", "Santa Fe", "pedrosanchez@gmail.com", editDate(5,7,1992)));
	myStore.add(ArrayTypes::CLIENT, Client("Maria Lopez", "342333333", "Pellegrini 987", "Santa Fe", "marialopez@hotmail.com", editDate(18,9,1998)));
	myStore.add(ArrayTypes::CLIENT, Client("Lucas Fernandez", "340000000", "San Martin 567", "Santa Fe", "lucasfernandez@gmail.com", editDate(2,9,1996)));
	
	myStore.saveIndividualData(ArrayTypes::CLIENT);
	
	
	myStore.add<Product>(ArrayTypes::PRODUCT, Product("S22 Ultra", "Samsung", 1029, 12));
	myStore.add(ArrayTypes::PRODUCT, Product("Galaxy A52", "Samsung", 429, 30));
	myStore.add(ArrayTypes::PRODUCT, Product("14 Pro", "Iphone", 1300, 15));
	myStore.add(ArrayTypes::PRODUCT, Product("Moto G72", "Motorola", 320, 50));
	myStore.saveIndividualData(ArrayTypes::PRODUCT);
	
	myStore.add(ArrayTypes::SELLER, Seller("Franco", "987654321", "franco@tienda.com"));
	myStore.add(ArrayTypes::SELLER, Seller("Juan", "123456789", "juan@tienda.com"));
	myStore.add(ArrayTypes::SELLER, Seller("Aramis", "123456789", "aramis@tienda.com"));
	myStore.saveIndividualData(ArrayTypes::SELLER);
	
	// Guardar datos en archivos
	myStore.saveAllData();
	
	// Ordenar elementos en la tienda (puedes modificar según tus criterios)
	myStore.Sort<ClientParams>(CLIENT, CLIENT_NAME);
	myStore.Sort<Product>(PRODUCT, PRODUCT_NAME);
	myStore.Sort<Seller>(SELLER, SELLER_NAME);
	
	// Imprimir elementos ordenados
	std::cout << "Clientes ordenados por nombre:\n";
	for(int i = 0; i < myStore.sizeOf(CLIENT) ; i++){
		cout<< myStore.get<Client>(CLIENT, i).get(CLIENT_NAME)<<endl;
	}
//	
//	std::cout << "Productos ordenados por nombre:\n";
//	myStore.printElements(ArrayTypes::PRODUCT);
//	
//	std::cout << "Vendedores ordenados por nombre:\n";
//	myStore.printElements(ArrayTypes::SELLER);
//	
//	std::cout << "Órdenes ordenadas por fecha:\n";
//	myStore.printElements(ArrayTypes::ORDER);
	
	return 0;
}
