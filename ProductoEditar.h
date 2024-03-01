#ifndef PRODUCTOEDITAR_H
#define PRODUCTOEDITAR_H
#include "wxfb_project.h"

class ProductoEditar : public WxfbProductoEditar {
	
private:
	
protected:
	void OnClickAgregarProducto( wxCommandEvent& event )  override;
	void OnClickCancelarProducto( wxCommandEvent& event )  override;
	
public:
	ProductoEditar(wxWindow *parent=NULL);
	~ProductoEditar();
};

#endif

