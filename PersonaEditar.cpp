#include "PersonaEditar.h"
#include "string_conv.h"
#include <ctime>
#include <wx/msgdlg.h>

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
	string tel = wx_to_std(m_telefono->GetValue());
	string direccion = wx_to_std(m_direccion->GetValue());
	string localidad = wx_to_std(m_localidad->GetValue());
	string email = wx_to_std(m_email->GetValue());
	
	if(m_nombre->IsEmpty()){
		wxMessageBox("Debes ingresar un nombre", "CLIENTES");
		return;
	}
	if(m_apellido->IsEmpty()){
		wxMessageBox("Debes ingresar un apellido", "CLIENTES");
		return;
	}
	string nombre = wx_to_std(m_nombre->GetValue())+" "+wx_to_std(m_apellido->GetValue());
	
	if(m_telefono->IsEmpty()){
		wxMessageBox("Debes ingresar un telefono", "CLIENTES");
		return;
	}
	if(m_direccion->IsEmpty()){
		wxMessageBox("Debes ingresar una direccion", "CLIENTES");
		return;
	}
	if(m_email->IsEmpty()){
		wxMessageBox("Debes ingresar un correo electronico", "CLIENTES");
		return;
	}
	if(m_localidad->IsEmpty()){
		wxMessageBox("Debes ingresar una localidad", "CLIENTES");
		return;
	}
	
	if(m_dia->IsEmpty() || m_mes->IsEmpty() || m_anio->IsEmpty()){
		wxMessageBox("Debes ingresar una fecha", "VENTAS");
		return;
	}
	
	int day =  stoi(wx_to_std(m_dia->GetValue()));
	int month = stoi(wx_to_std(m_mes->GetValue()));
	int year = stoi(wx_to_std(m_anio->GetValue()));
	
	if(!isValidDate(day, month, year)){
		wxMessageBox("La fecha no es valida", "VENTAS");
		return;
	}
	
	time_t fecha = editDate(day,month,year);
	
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

