#ifndef CLIENT_H
#define CLIENT_H
#include "Utils.h"
#include "EnumDefinitions.h"

struct clientStruct{
	char id[16];
	char name[64];
	char phone[32];
	char address[128];
	char city[64];
	char email[64];
	time_t birthday;
};

class Client {
public:
	Client();
    Client(std::string a_name, std::string a_phone, std::string a_address, std::string a_city, std::string a_email, time_t a_birthday);
    std::string get(ClientParams params) const;
    time_t getBirthday() const;
    void edit(ClientParams param, std::string value);
	void editBirthday(time_t date);
    void editBirthday(int a_day, int a_month, int a_year);
private:
	std::string id;
	std::string name;
	std::string phone;
	std::string address;
	std::string city;
	std::string email;
	time_t birthday;
};

#endif

