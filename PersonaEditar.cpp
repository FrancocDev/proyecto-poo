#include "PersonaEditar.h"

PersonaEditar::PersonaEditar(wxWindow *parent,Store *store,int i) : WxfbPersonaEditar(parent), m_store(store),index(i) {
	
}

void PersonaEditar::OnClickAgregarPersona( wxCommandEvent& event )  {
	event.Skip();
}

void PersonaEditar::OnClickCancelarPersona( wxCommandEvent& event )  {
	event.Skip();
}

PersonaEditar::~PersonaEditar() {
	
}

