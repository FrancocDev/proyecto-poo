#include "VendedorEditar.h"
#include "Store.h"
#include "PrincipalWin.h"
VendedorEditar::VendedorEditar(wxWindow *parent, Store *store,int i) :
	WxfbVendedorEditar(parent), m_store(store),index(i) {
	/*nombre tel id email*/
	Seller &temp = m_store->getSeller(i);
	m_nombre = temp.name;
	m_telefono = temp.phone;
	
	m_email = temp.email;
	
}

void VendedorEditar::OnClickAgregarSeller( wxCommandEvent& event )  {
	event.Skip();
}

void VendedorEditar::OnClickCancelarSeller( wxCommandEvent& event )  {
	event.Skip();
}

VendedorEditar::~VendedorEditar() {
	
}

