#include "SellerWin.h"

SellerWin::SellerWin(wxWindow *parent, Store *store) : WxfbVendedor(parent) {
	
}

void SellerWin::OnClickAgregarSeller( wxCommandEvent& event )  {
	
}

void SellerWin::OnClickCancelarSeller( wxCommandEvent& event )  {
	event.Skip();
}

SellerWin::~SellerWin() {
	
}

