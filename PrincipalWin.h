#ifndef PRINCIPALWIN_H
#define PRINCIPALWIN_H
#include "wxfb_project.h"
#include "Store.h"
class PrincipalWin : public Principal {
	
private:
	
protected:
	void OnClickAgregarprincipal( wxCommandEvent& event )  override;
	void OnClicksavefile( wxCommandEvent& event )  override;
	
	void OnCambiaTamanio( wxSizeEvent& event )  override;
	void EnterBuscar( wxCommandEvent& event )  override;
	void OnClickBuscar( wxCommandEvent& event )  override;
	void OnDobleClickGrilla( wxGridEvent& event )  override;
	void OnClickGrilla( wxGridEvent& event )  override;
	
	void OnClickEditar( wxCommandEvent& event )  override;
	void OnClickEliminar( wxCommandEvent& event )  override;
	Store *m_store;
	void RefrescarGrilla();
public:
	PrincipalWin(Store *store);

};

#endif

