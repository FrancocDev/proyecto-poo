#include "PersonaEditar.h"

PersonaEditar::PersonaEditar(wxWindow *parent,Store *store) : WxfbPersonaEditar(parent), m_store(store) {
	
}

void PersonaEditar::OnClickAgregarPersona( wxCommandEvent& event )  {
	event.Skip();
}

void PersonaEditar::OnClickCancelarPersona( wxCommandEvent& event )  {
	event.Skip();
}

PersonaEditar::~PersonaEditar() {
	
}

