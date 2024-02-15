#include "Utils.h"
#include <string>
#include <ctime>

void tolower(std::string &s) {
	int i,c=s.size();
	for (i=0;i<c;i++)
		s[i]=std::tolower(s[i]);
}

bool compareString(const std::string &s1, const std::string &s2) {
	std::string string1 = s1;
	std::string string2 = s2;
	tolower(string1);
	tolower(string2);
	return string1<string2;
}

std::string generateRandomID(int length) {
	const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string randomID;
	
	/// random seed
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	for (int i = 0; i < length; ++i) {
		randomID += characters[std::rand() % characters.length()];
	}
	return randomID;
}

time_t editDate(int day, int month, int year) {
	struct tm date;
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	date.tm_hour = 0;
	date.tm_min = 0;
	date.tm_sec = 0;
	return mktime(&date);
}

// Esta aca para evitar problemas de dependencias circulares
bool sortBy(const Client& elem1, const Client& elem2, ClientParams criteria) {
	return elem1.get(criteria) < elem2.get(criteria);
}

bool sortBy(const Order& elem1, const Order& elem2, OrderParams criteria) {
	return elem1.get(criteria) < elem2.get(criteria);
}
bool sortBy(const Product& elem1, const Product& elem2, ProductParams criteria) {
	return elem1.get(criteria) < elem2.get(criteria);
}
bool sortBy(const Seller& elem1, const Seller& elem2, SellerParams criteria) {
	return elem1.get(criteria) < elem2.get(criteria);
}
