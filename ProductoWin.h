#ifndef PRODUCTOWIN_H
#define PRODUCTOWIN_H
#include "wxfb_project.h"

#include "Store.h"
#include "Product.h"
class ProductoWin : public WxfbProducto {
	
private:
	Store *m_store;
protected:
	void OnClickAgregarProducto( wxCommandEvent& event )  override;
	void OnClickCancelarProducto( wxCommandEvent& event )  override;
	
public:
	ProductoWin(wxWindow *parent, Store *store);
	
};

#endif

