#include "ProductoEditar.h"

ProductoEditar::ProductoEditar(wxWindow *parent, Store *store)  :
	WxfbProductoEditar(parent), m_store(store) {
	
}

void ProductoEditar::OnClickAgregarProducto( wxCommandEvent& event )  {
	event.Skip();
}

void ProductoEditar::OnClickCancelarProducto( wxCommandEvent& event )  {
	event.Skip();
}

ProductoEditar::~ProductoEditar() {
	
}

