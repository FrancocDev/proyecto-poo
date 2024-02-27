#ifndef VENTAWIN_H
#define VENTAWIN_H
#include "wxfb_project.h"

class VentaWin : public WxfbVenta {
	
private:
	
protected:
	void addProductToOrder( wxCommandEvent& event )  override;
	void OnDobleClickGrilla( wxGridEvent& event )  override;
	void OnClickGrilla( wxGridEvent& event )  override;
	void OnClickAgregarVenta( wxCommandEvent& event )  override;
	void OnClickCancelarVenta( wxCommandEvent& event )  override;
	
public:
	VentaWin(wxWindow *parent=NULL);
	~VentaWin();
};

#endif

