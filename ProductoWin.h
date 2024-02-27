#ifndef PRODUCTOWIN_H
#define PRODUCTOWIN_H
#include "wxfb_project.h"

class ProductoWin : public WxfbProducto {
	
private:
	
protected:
	void OnClickAgregarProducto( wxCommandEvent& event )  override;
	void OnClickCancelarProducto( wxCommandEvent& event )  override;
	
public:
	ProductoWin(wxWindow *parent=NULL);
	~ProductoWin();
};

#endif

