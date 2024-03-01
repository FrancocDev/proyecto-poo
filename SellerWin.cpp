#include "SellerWin.h"
#include "Utils.h"
#include "string_conv.h"
#include "Store.h"
#include "Seller.h"
SellerWin::SellerWin(wxWindow *parent, Store *store) :
	WxfbVendedor(parent),m_store(store) {
	
}
	
void SellerWin::OnClickAgregarSeller( wxCommandEvent& event )  {
	string nombre = wx_to_std(m_nombre->GetValue())+" "+wx_to_std(m_apellido->GetValue());
	string tel = wx_to_std(m_telefono->GetValue());
	string email = wx_to_std(m_email->GetValue());
	Seller temp(nombre,tel,email);
	m_store->addSeller(std::move(temp));
	m_store->saveIndividualData(SELLER);
	EndModal(1);
}

void SellerWin::OnClickCancelarSeller( wxCommandEvent& event )  {
	EndModal(0);}


