#include "VentaWin.h"

VentaWin::VentaWin(wxWindow *parent) : WxfbVenta(parent) {
	
}

void VentaWin::addProductToOrder( wxCommandEvent& event )  {
	event.Skip();
}

void VentaWin::OnDobleClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VentaWin::OnClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VentaWin::OnClickAgregarVenta( wxCommandEvent& event )  {
	event.Skip();
}

void VentaWin::OnClickCancelarVenta( wxCommandEvent& event )  {
	event.Skip();
}

VentaWin::~VentaWin() {
	
}

