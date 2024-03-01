#include "PersonaEditar.h"

PersonaEditar::PersonaEditar(wxWindow *parent) : WxfbPersonaEditar(parent) {
	
}

void PersonaEditar::OnClickAgregarPersona( wxCommandEvent& event )  {
	event.Skip();
}

void PersonaEditar::OnClickCancelarPersona( wxCommandEvent& event )  {
	event.Skip();
}

PersonaEditar::~PersonaEditar() {
	
}

