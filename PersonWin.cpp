#include "PersonWin.h"
#include "Store.h"
#include "Client.h"
#include "string_conv.h"
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
	string cumple = wx_to_std(m_dia->GetValue())+"/"+ wx_to_std(m_mes->GetValue())+"/"+ wx_to_std(m_anio->GetValue());
	Client temp = Client();
	Client& c = temp;
	temp(nombre, tel, direccion, localidad, email, cumple);
	m_store-> addClient(temp);
	EndModal(1);///ver q onda aca
}

void PersonWin::OnClickCancelarPersona( wxCommandEvent& event )  {
	EndModal(0);
}

