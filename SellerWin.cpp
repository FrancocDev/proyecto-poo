#include "SellerWin.h"
#include "Utils.h"
#include "string_conv.h"
#include "Store.h"
#include "Seller.h"
#include <wx/msgdlg.h>
SellerWin::SellerWin(wxWindow *parent, Store *store) :
	WxfbVendedor(parent),m_store(store) {
	
}
	
void SellerWin::OnClickAgregarSeller( wxCommandEvent& event )  {
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
	
	Seller temp(nombre,tel,email);
	m_store->addSeller(std::move(temp));
	m_store->saveIndividualData(SELLER);
	EndModal(1);
}

void SellerWin::OnClickCancelarSeller ( wxCommandEvent& event )  {
	EndModal(0);
}


