#include "ProductoEditar.h"
#include "string_conv.h"
#include <sstream>
#include <iomanip>
using namespace std;

ProductoEditar::ProductoEditar(wxWindow *parent, Store *store,int i)  :
	WxfbProductoEditar(parent), m_store(store),index(i) {
	Product &temp = m_store->getProduct(i);
	
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
	float precio = stof(auxprecio);
	int cantidad = stoi(auxcantidad);
	
	Product temp(nombre,marca,precio,cantidad);
	
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

