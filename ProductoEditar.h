#ifndef PRODUCTOEDITAR_H
#define PRODUCTOEDITAR_H
#include "wxfb_project.h"
#include "Store.h"
class ProductoEditar : public WxfbProductoEditar {
	
private:
	Store *m_store;
	int index;
protected:
void OnClickAgregarProducto( wxCommandEvent& event )  override;
void OnClickCancelarProducto( wxCommandEvent& event )  override;
	
public:
	ProductoEditar(wxWindow *parent, Store *store,int i);
	~ProductoEditar();
};

#endif

