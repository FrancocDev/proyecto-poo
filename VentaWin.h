#ifndef VENTAWIN_H
#define VENTAWIN_H
#include "wxfb_project.h"
#include "Store.h"
#include "Product.h"

class VentaWin : public WxfbVenta {
	
private:
	Store *m_store;
	vector <Product> products;
protected:
	void addProductToOrder( wxCommandEvent& event )  override;
	void OnDobleClickGrilla( wxGridEvent& event )  override;
	void OnClickGrilla( wxGridEvent& event )  override;
	void OnClickAgregarVenta( wxCommandEvent& event )  override;
	void OnClickCancelarVenta( wxCommandEvent& event )  override;
	
public:
	VentaWin(wxWindow *parent=NULL, Store *store=NULL);
	~VentaWin();
};

#endif

