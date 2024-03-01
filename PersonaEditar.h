#ifndef PERSONAEDITAR_H
#define PERSONAEDITAR_H
#include "wxfb_project.h"

class PersonaEditar : public WxfbPersonaEditar {
	
private:
	
protected:
	void OnClickAgregarPersona( wxCommandEvent& event )  override;
	void OnClickCancelarPersona( wxCommandEvent& event )  override;
	
public:
	PersonaEditar(wxWindow *parent=NULL);
	~PersonaEditar();
};

#endif

