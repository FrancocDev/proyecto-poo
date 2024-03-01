#include "VendedorEditar.h"

VendedorEditar::VendedorEditar(wxWindow *parent) : WxfbVendedorEditar(parent) {
	
}

void VendedorEditar::OnClickAgregarSeller( wxCommandEvent& event )  {
	event.Skip();
}

void VendedorEditar::OnClickCancelarSeller( wxCommandEvent& event )  {
	event.Skip();
}

VendedorEditar::~VendedorEditar() {
	
}

