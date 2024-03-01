#include "VendedorEditar.h"
#include "Store.h"
#include "PrincipalWin.h"
#include "string_conv.h"
#include "Utils.h"
#include <wx/msgdlg.h>
VendedorEditar::VendedorEditar(wxWindow *parent, Store *store,int i) :
	WxfbVendedorEditar(parent), m_store(store),index(i) {
	/*nombre tel id email*/
	
	Seller &temp = m_store->getSeller(i);
	/*m_nombre ->SetValue( temp.get(SELLER_NAME));*/
	pair<string,string>nombres = splitFullName(temp.get(SELLER_NAME));
	m_nombre ->SetValue(nombres.first);
	m_apellido ->SetValue(nombres.second);
	m_telefono ->SetValue(temp.get(SELLER_PHONE));
	
	m_email -> SetValue(temp.get(SELLER_EMAIL));
	
}

void VendedorEditar::OnClickAgregarSeller( wxCommandEvent& event )  {
	string tel = wx_to_std(m_telefono->GetValue());
	string email = wx_to_std(m_email->GetValue());
	
	if(m_nombre->IsEmpty()){
		wxMessageBox("Debes ingresar un nombre", "VENDEDOR");
		return;
	}
	if(m_apellido->IsEmpty()){
		wxMessageBox("Debes ingresar un apellido", "VENDEDOR");
		return;
	}
	string nombre = wx_to_std(m_nombre->GetValue())+" "+wx_to_std(m_apellido->GetValue());
		
	if(m_telefono->IsEmpty()){
		wxMessageBox("Debes ingresar un telefono", "VENDEDOR");
		return;
	}
	
	if(m_email->IsEmpty()){
		wxMessageBox("Debes ingresar un correo electronico", "VENDEDOR");
		return;
	}
	
	Seller temp(nombre, tel, email);
	
	m_store->remove(SELLER,index);
	m_store->addSeller(std::move(temp));
	m_store->saveIndividualData(SELLER);
	
	EndModal(1);
}

void VendedorEditar::OnClickCancelarSeller( wxCommandEvent& event )  {
	EndModal(0);
}

VendedorEditar::~VendedorEditar() {
	
}

