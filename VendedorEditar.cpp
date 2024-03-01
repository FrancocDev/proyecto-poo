#include "VendedorEditar.h"
#include "Store.h"
#include "PrincipalWin.h"
#include "string_conv.h"
VendedorEditar::VendedorEditar(wxWindow *parent, Store *store,int i) :
	WxfbVendedorEditar(parent), m_store(store),index(i) {
	/*nombre tel id email*/
	
	Seller &temp = m_store->getSeller(i);
	m_nombre ->SetValue( temp.get(SELLER_NAME));
	
	m_telefono ->SetValue(temp.get(SELLER_PHONE));
	
	m_email -> SetValue(temp.get(SELLER_EMAIL));
	
}

void VendedorEditar::OnClickAgregarSeller( wxCommandEvent& event )  {
	string nombre = wx_to_std(m_nombre->GetValue())+" "+wx_to_std(m_apellido->GetValue());
	string tel = wx_to_std(m_telefono->GetValue());
	string email = wx_to_std(m_email->GetValue());
	
	Seller temp(nombre, tel, email);
	
	m_store->remove(SELLER,index);
	m_store->addSeller(std::move(temp));
	m_store->saveIndividualData(SELLER);
	
	EndModal(1);///ver q onda aca
}

void VendedorEditar::OnClickCancelarSeller( wxCommandEvent& event )  {
	EndModal(0);
}

VendedorEditar::~VendedorEditar() {
	
}

