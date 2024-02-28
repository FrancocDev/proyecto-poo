#ifndef SELLERWIN_H
#define SELLERWIN_H
#include "wxfb_project.h"
#include "Store.h"

class SellerWin : public WxfbVendedor {
	
private:
	
protected:
	void OnClickAgregarSeller( wxCommandEvent& event );
	void OnClickCancelarSeller( wxCommandEvent& event );

public:
	SellerWin(wxWindow *parent=NULL, Store *store=NULL);
	~SellerWin();
};

#endif

