#ifndef PERSONWIN_H
#define PERSONWIN_H
#include "wxfb_project.h"
#include "Store.h"
#include "Client.h"
class PersonWin : public WxfbPersona {
	
private:
	Store *m_store;
protected:
	void OnClickAgregarPersona( wxCommandEvent& event )  override;
	void OnClickCancelarPersona( wxCommandEvent& event )  override;
	
	
public:
	PersonWin(wxWindow *parent, Store *store);
	
};

#endif