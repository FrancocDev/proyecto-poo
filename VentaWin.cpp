#include "VentaWin.h"
#include "Store.h"
#include "string_conv.h"
#include <wx/msgdlg.h>

VentaWin::VentaWin(wxWindow *parent, Store *store) : WxfbVenta(parent), m_store(store) {
	
}

void VentaWin::addProductToOrder( wxCommandEvent& event )  {
	string productNameInput = wx_to_std(m_cantidad->GetValue());
	Product product = m_store->getProductByName(productNameInput);
	
	
	if(product.get(PRODUCT_NAME) == productNameInput){
		products.push_back(product);
		wxMessageBox("Producto agregado","VENTAS");
	if(m_orderGrid1->GetNumberRows()!=0){
		m_orderGrid1->DeleteRows(0,m_orderGrid1->GetNumberRows());
	}
	for(int i=0; i< products.size() ;i++){
		Product temp = products[i];
		m_orderGrid1->AppendRows();
		m_orderGrid1->SetCellValue(i,0,"asd");
		m_orderGrid1->SetCellValue(i,1,"asd");
		m_orderGrid1->SetCellValue(i,2,"asd");
	}
		}
	else {
		wxMessageBox("Ese producto no existe","VENTAS");
	}
//	event.Skip();
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

