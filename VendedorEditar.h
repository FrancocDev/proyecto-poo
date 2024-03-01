#ifndef VENDEDOREDITAR_H
#define VENDEDOREDITAR_H
#include "wxfb_project.h"
#include "Store.h"
class VendedorEditar : public WxfbVendedorEditar {
	
private:
	Store *m_store,
	int index;
protected:
	void OnClickAgregarSeller( wxCommandEvent& event )  override;
	void OnClickCancelarSeller( wxCommandEvent& event )  override;
	
public:
	VendedorEditar(wxWindow *parent, Store *store,int i);
	~VendedorEditar();
};

#endif

