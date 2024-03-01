#include "ProductoEditar.h"
#include "string_conv.h"
#include <sstream>
#include <iomanip>
#include <wx/msgdlg.h>
using namespace std;

ProductoEditar::ProductoEditar(wxWindow *parent, Store *store,int i)  :
	WxfbProductoEditar(parent), m_store(store),index(i) {
	Product &temp = m_store->getProduct(i);
	originalId = temp.get(PRODUCT_ID);
	m_marca ->SetValue(temp.get(PRODUCT_BRAND));
	m_nombre ->SetValue(temp.get(PRODUCT_NAME));
	string auxcant = to_string(temp.getQuantity());
	/// setprecision para que tenga 2 decimales
	ostringstream ss;
	ss << fixed << setprecision(2) << to_string(temp.getPrice());
	
	m_precio ->SetValue(ss.str());
	m_cantidad ->SetValue(auxcant);
}

void ProductoEditar::OnClickAgregarProducto( wxCommandEvent& event )  {
	
	string marca = wx_to_std(m_marca->GetValue());
	string nombre = wx_to_std(m_nombre->GetValue());
	
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
	temp.edit(PRODUCT_ID, originalId);
	m_store->remove(PRODUCT,index);
	m_store->addProduct(std::move(temp));
	m_store->saveIndividualData(PRODUCT);
	EndModal(1);
}

void ProductoEditar::OnClickCancelarProducto( wxCommandEvent& event )  {
	EndModal(0);
}

ProductoEditar::~ProductoEditar() {
	
}

