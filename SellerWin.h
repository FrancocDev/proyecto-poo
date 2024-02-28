#ifndef SELLERWIN_H
#define SELLERWIN_H
#include "wxfb_project.h"
#include "Store.h"
#include "Seller.h"

class SellerWin : public WxfbVendedor {
	
private:
	Store *m_store;
protected:
	void OnClickAgregarSeller( wxCommandEvent& event );
	void OnClickCancelarSeller( wxCommandEvent& event );

public:
	SellerWin(wxWindow *parent, Store *store);
	
};

#endif

