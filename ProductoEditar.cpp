#include "ProductoEditar.h"

ProductoEditar::ProductoEditar(wxWindow *parent) : WxfbProductoEditar(parent) {
	
}

void ProductoEditar::OnClickAgregarProducto( wxCommandEvent& event )  {
	event.Skip();
}

void ProductoEditar::OnClickCancelarProducto( wxCommandEvent& event )  {
	event.Skip();
}

ProductoEditar::~ProductoEditar() {
	
}

