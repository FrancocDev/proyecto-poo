#ifndef VENTAEDITAR_H
#define VENTAEDITAR_H
#include "wxfb_project.h"
#include "Store.h"
#include "Product.h"
#include <map>
using namespace std;

class VentaEditar : public WxfbVentaEditar {
	
private:
	Store *m_store;
	map <Product, int> products;
	int index;
protected:
	void addProductToOrder( wxCommandEvent& event )  override;
	void OnDobleClickGrilla( wxGridEvent& event )  override;
	void OnClickGrilla( wxGridEvent& event )  override;
	void OnClickAgregarVenta( wxCommandEvent& event )  override;
	void OnClickCancelarVenta( wxCommandEvent& event )  override;
	void addProductToOrderId( string productId );
public:
	VentaEditar(wxWindow *parent=NULL, Store *store=NULL, int i=NULL);
	~VentaEditar();
};

#endif

