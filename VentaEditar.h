#ifndef VENTAEDITAR_H
#define VENTAEDITAR_H
#include "wxfb_project.h"

class VentaEditar : public WxfbVentaEditar {
	
private:
	
protected:
	void addProductToOrder( wxCommandEvent& event )  override;
	void OnDobleClickGrilla( wxGridEvent& event )  override;
	void OnClickGrilla( wxGridEvent& event )  override;
	void OnClickAgregarVenta( wxCommandEvent& event )  override;
	void OnClickCancelarVenta( wxCommandEvent& event )  override;
	
public:
	VentaEditar(wxWindow *parent=NULL);
	~VentaEditar();
};

#endif

