#include "ProductoWin.h"

ProductoWin::ProductoWin(wxWindow *parent) : WxfbProducto(parent) {
	
}

void ProductoWin::OnClickAgregarProducto( wxCommandEvent& event )  {
	event.Skip();
}

void ProductoWin::OnClickCancelarProducto( wxCommandEvent& event )  {
	event.Skip();
}

ProductoWin::~ProductoWin() {
	
}

