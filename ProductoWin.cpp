#include "ProductoWin.h"
#include "Store.h"
#include "ProductoWin.h"
#include "Product.h"
#include "Utils.h"
#include "string_conv.h"
#include <wx/msgdlg.h>

ProductoWin::ProductoWin(wxWindow *parent, Store *store) :
	WxfbProducto(parent), m_store(store) {
	
}

void ProductoWin::OnClickAgregarProducto( wxCommandEvent& event )  {
	string nombre = wx_to_std(m_nombre->GetValue());
	string marca = wx_to_std(m_marca->GetValue());
	string auxprecio = wx_to_std(m_precio->GetValue());
	string auxcantidad = wx_to_std(m_cantidad->GetValue());
	
	if(m_nombre->IsEmpty()){
		wxMessageBox("Debes ingresar un nombre del producto", "PRODUCTO");
		return;
	}
	if(m_marca->IsEmpty()){
		wxMessageBox("Debes ingresar la marca del producto", "PRODUCTO");
		return;
	}
	if(m_precio->IsEmpty()){
		wxMessageBox("Debes ingresar un precio de producto", "PRODUCTO");
		return;
	}
	float precio = stof(auxprecio);
	
	if(m_cantidad->IsEmpty()){
		wxMessageBox("Debes agregar una cantidad al producto", "PRODUCTO");
		return;
	}
	
	int cantidad = stoi(auxcantidad);
	
	Product temp(nombre,marca,precio,cantidad);
	m_store->addProduct(std::move(temp));
	m_store->saveIndividualData(PRODUCT);
	EndModal(1);
}

void ProductoWin::OnClickCancelarProducto( wxCommandEvent& event )  {
	EndModal(0);
}


