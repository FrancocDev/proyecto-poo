#include "VentaEditar.h"

VentaEditar::VentaEditar(wxWindow *parent) : WxfbVentaEditar(parent) {
	
}

void VentaEditar::addProductToOrder( wxCommandEvent& event )  {
	event.Skip();
}

void VentaEditar::OnDobleClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VentaEditar::OnClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VentaEditar::OnClickAgregarVenta( wxCommandEvent& event )  {
	event.Skip();
}

void VentaEditar::OnClickCancelarVenta( wxCommandEvent& event )  {
	event.Skip();
}

VentaEditar::~VentaEditar() {
	
}

