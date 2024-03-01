#include "ProductoWin.h"
#include "Store.h"
#include "ProductoWin.h"
#include "Product.h"
#include "Utils.h"
#include "string_conv.h"

ProductoWin::ProductoWin(wxWindow *parent, Store *store) :
	WxfbProducto(parent), m_store(store) {
	
}

void ProductoWin::OnClickAgregarProducto( wxCommandEvent& event )  {
	string nombre = wx_to_std(m_nombre->GetValue());
	string marca = wx_to_std(m_marca->GetValue());
	string auxprecio = wx_to_std(m_precio->GetValue());
	string auxcantidad = wx_to_std(m_cantidad->GetValue());
	float precio = stof(auxprecio);
	int cantidad = stoi(auxcantidad);
	
	Product temp(nombre,marca,precio,cantidad);
	m_store->addProduct(std::move(temp));
	m_store->saveIndividualData(PRODUCT);
	EndModal(1);
}

void ProductoWin::OnClickCancelarProducto( wxCommandEvent& event )  {
	EndModal(2);
}


