#include "ProductoEditar.h"

ProductoEditar::ProductoEditar(wxWindow *parent, Store *store,int i)  :
	WxfbProductoEditar(parent), m_store(store),index(i) {
	
}

void ProductoEditar::OnClickAgregarProducto( wxCommandEvent& event )  {
	event.Skip();
}

void ProductoEditar::OnClickCancelarProducto( wxCommandEvent& event )  {
	event.Skip();
}

ProductoEditar::~ProductoEditar() {
	
}

