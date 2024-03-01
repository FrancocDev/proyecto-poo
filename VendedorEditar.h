#ifndef VENDEDOREDITAR_H
#define VENDEDOREDITAR_H
#include "wxfb_project.h"

class VendedorEditar : public WxfbVendedorEditar {
	
private:
	
protected:
	void OnClickAgregarSeller( wxCommandEvent& event )  override;
	void OnClickCancelarSeller( wxCommandEvent& event )  override;
	
public:
	VendedorEditar(wxWindow *parent=NULL);
	~VendedorEditar();
};

#endif

