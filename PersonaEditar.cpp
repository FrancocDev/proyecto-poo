#include "PersonaEditar.h"
#include "string_conv.h"
#include <ctime>

PersonaEditar::PersonaEditar(wxWindow *parent,Store *store,int i) : WxfbPersonaEditar(parent), m_store(store),index(i) {
	Client &temp = m_store->getClient(i);
	
	pair<string,string>nombres = splitFullName(temp.get(CLIENT_NAME));
	m_nombre ->SetValue(nombres.first);
	m_apellido ->SetValue(nombres.second);
	m_direccion ->SetValue(temp.get(CLIENT_ADDRESS));
	m_localidad ->SetValue(temp.get(CLIENT_CITY));
	m_telefono ->SetValue(temp.get(CLIENT_PHONE));
	m_email->SetValue(temp.get(CLIENT_EMAIL));
	
	time_t date = temp.getBirthday();
	
	m_dia->SetValue(getDateDay(date));
	m_mes->SetValue(getDateMonth(date));
	m_anio->SetValue(getDateYear(date));
	
	
	
}

void PersonaEditar::OnClickAgregarPersona( wxCommandEvent& event )  {
	string nombre = wx_to_std(m_nombre->GetValue())+" "+wx_to_std(m_apellido->GetValue());
	string tel = wx_to_std(m_telefono->GetValue());
	string direccion = wx_to_std(m_direccion->GetValue());
	string localidad = wx_to_std(m_localidad->GetValue());
	string email = wx_to_std(m_email->GetValue());
	
	long dayLong, monthLong, yearLong;
	dayLong = m_dia->GetValue().ToLong(&dayLong);
	monthLong = m_mes->GetValue().ToLong(&monthLong);
	yearLong = m_anio->GetValue().ToLong(&yearLong);
	time_t fecha = editDate(static_cast<int>(dayLong), static_cast<int>(monthLong), static_cast<int>(yearLong));
	
	Client temp(nombre, tel, direccion, localidad, email, fecha);
	
	m_store->remove(CLIENT,index);
	m_store->addClient(std::move(temp));
	m_store->saveIndividualData(CLIENT);
	
	EndModal(1);///ver q onda aca
}

void PersonaEditar::OnClickCancelarPersona( wxCommandEvent& event )  {
	EndModal(0);
}

PersonaEditar::~PersonaEditar() {
	
}

