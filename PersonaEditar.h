#ifndef PERSONAEDITAR_H
#define PERSONAEDITAR_H
#include "wxfb_project.h"
#include "Store.h"
class PersonaEditar : public WxfbPersonaEditar {
	
private:
	Store *m_store,
protected:
	void OnClickAgregarPersona( wxCommandEvent& event )  override;
	void OnClickCancelarPersona( wxCommandEvent& event )  override;
	
public:
	PersonaEditar(wxWindow *parent, Store *store);
	~PersonaEditar();
};

#endif

