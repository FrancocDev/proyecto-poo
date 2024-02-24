#include "PersonWin.h"
#include "Store.h"
#include "Client.h"
#include "string_conv.h"
#include "Utils.h"
PersonWin::PersonWin(wxWindow *parent, Store *store) :
	WxfbPersona(parent), m_store(store) {
	
}

 

///con el modal, finaliza el cuadro
void PersonWin::OnClickAgregarPersona( wxCommandEvent& event )  {
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
	m_store->addClient(std::move(temp));
	
	EndModal(1);///ver q onda aca
}

void PersonWin::OnClickCancelarPersona( wxCommandEvent& event )  {
	EndModal(0);
}

