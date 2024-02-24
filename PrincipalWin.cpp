#include "PrincipalWin.h"
#include "PersonWin.h"
#include "Store.h"
#include "Client.h"
#include "Seller.h"
#include "Order.h"
#include "Utils.h"
PrincipalWin::PrincipalWin(Store *store) : 
	Principal(nullptr) , m_store(store)
{
	RefrescarGrilla();
}

void PrincipalWin::RefrescarGrilla(){
	Client temp = Client();
	Client& c = temp;
		if(m_grilla->GetNumberRows()!=0){
			m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
		}
		for(int i=0; i<m_store->GetNumofclients();i++){
			temp = m_store->getClient(i);
			m_grilla->AppendRows();
			m_grilla->SetCellValue(i,0,c.get(CLIENT_NAME));
			m_grilla->SetCellValue(i,1,c.get(CLIENT_ADDRESS));
			m_grilla->SetCellValue(i,2,c.get(CLIENT_PHONE));
			m_grilla->SetCellValue(i,3,c.get(CLIENT_ADDRESS));
		}
	}




void PrincipalWin::OnCambiaTamanio( wxSizeEvent& event )  {
	event.Skip();
}

void PrincipalWin::EnterBuscar( wxCommandEvent& event )  {
	event.Skip();
}

void PrincipalWin::OnClickBuscar( wxCommandEvent& event )  {
	event.Skip();
}

void PrincipalWin::OnDobleClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void PrincipalWin::OnClickGrilla( wxGridEvent& event )  {
	event.Skip();
}



void PrincipalWin::OnClickEditar( wxCommandEvent& event )  {
	event.Skip();
}

void PrincipalWin::OnClickEliminar( wxCommandEvent& event )  {
	int f = m_grilla->GetGridCursorRow();
		m_store->remove(CLIENT,f);
		
		m_grilla->DeleteRows(f);
		RefrescarGrilla();
}



void PrincipalWin::OnClicksavefile( wxCommandEvent& event ){
	m_store->saveAllData();
}
///se crea con new para que quede viva
void PrincipalWin::OnClickAgregarprincipal( wxCommandEvent& event )  {
	PersonWin *win = new PersonWin(this, m_store);
	///showmodal logra que hasta q no se termine no desaparece
	if(win->ShowModal()==1)///si es 1 refresca
		RefrescarGrilla();
}

