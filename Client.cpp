#include "Utils.h"
#include "Client.h"
#include <string>

Client::Client(){};

Client::Client(std::string a_name,std::string a_phone,
				 std::string a_address, std::string a_city, std::string a_email, 
				 time_t a_birthday) 
{
    id=generateRandomID(12); /// No deberia colisionar nunca
	name=a_name;
    phone=a_phone;
    address=a_address;
    city=a_city;
	email=a_email;
    birthday=a_birthday;
}

std::string Client::get(ClientParams param) const {
	switch (param)
    {
    case CLIENT_ID:
        return id;
        break;
    case CLIENT_NAME:
        return name;
        break;
    case CLIENT_PHONE:
        return phone;
        break;
    case CLIENT_ADDRESS:
        return address;
        break;
    case CLIENT_CITY:
        return city;
        break;
    case CLIENT_EMAIL:
        return email;
        break;
    default:
		return "";
        break;
    }; 
}
time_t Client::getBirthday() const {
    return birthday;
}

void Client::edit(ClientParams param, std::string value) { 
    switch (param)
    {
    case CLIENT_NAME:
        name = value;
        break;
    case CLIENT_PHONE:
        phone = value;
        break;
    case CLIENT_ADDRESS:
        address = value;
        break;
    case CLIENT_CITY:
        city = value;
        break;
    case CLIENT_EMAIL:
        email = value;
        break;
    default:
        break;
    }; 
}

void Client::editBirthday(int a_day, int a_month, int a_year) { 
	birthday = editDate(a_day, a_month, a_year);
}
