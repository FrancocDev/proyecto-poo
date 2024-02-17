#ifndef CLIENT_H
#define CLIENT_H
#include "Utils.h"
#include "EnumDefinitions.h"
struct registro_persona {
	char name[256];
	char phone[256];
	char address[256];
	char city[256];
	char email[2560];
	char id[256];
	int dia_nac, mes_nac, anio_nac;
};
class Client {
public:
	Client();
    Client(std::string a_name, std::string a_phone, std::string a_address, std::string a_city, std::string a_email, time_t a_birthday);
    std::string get(ClientParams params) const;
    time_t getBirthday() const;
    void edit(ClientParams param, std::string value);
    void editBirthday(int a_day, int a_month, int a_year);
	void SaveBinary(std::ofstream &file);
	void ReadBinary(std::ifstream &file);
private:
	std::string id;
	std::string name;
	std::string phone;
	std::string address;
	std::string city;
	std::string email;
	int dia_nac;
	int mes_nac;
	int anio_nac;
	time_t birthday;
};

#endif

