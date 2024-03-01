#include "PrincipalWin.h"
#include "PersonWin.h"
#include "Store.h"
#include "Client.h"
#include "Seller.h"
#include "Order.h"
#include "Utils.h"
#include <string>
#include <sstream>
#include <iomanip>
#include "SellerWin.h"
#include "wxfb_project.h"
#include "VentaWin.h"
#include "ProductoWin.h"
#include "string_conv.h"
using namespace std;
PrincipalWin::PrincipalWin(Store *store) : 
	Principal(nullptr) , m_store(store)
{
	RefrescarGrillaClientes();
}

void PrincipalWin::RefrescarGrillaClientes(){
	Client temp = Client();
	Client& c = temp;
		if(m_grilla->GetNumberRows()!=0){
			m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
		}
		for(int i=0; i<m_store->sizeOf(CLIENT);i++){
			temp = m_store->getClient(i);
			m_grilla->AppendRows();
			m_grilla->SetCellValue(i,0,c.get(CLIENT_NAME));
			m_grilla->SetCellValue(i,1,c.get(CLIENT_ADDRESS));
			m_grilla->SetCellValue(i,2,c.get(CLIENT_PHONE));
			m_grilla->SetCellValue(i,3,c.get(CLIENT_ADDRESS));
		}
		m_agregarPrincipal->Disconnect(wxID_ANY);
		m_agregarPrincipal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PrincipalWin::OnClickAgregarprincipal), NULL, this );
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
	
}
void PrincipalWin::EliminarDeTabla(ArrayTypes element,int f) {
	m_store->remove(element,f);
	m_grilla->DeleteRows(f);
	if(element == SELLER){RefrescarGrillaVendedores();}
	if(element == CLIENT){RefrescarGrillaClientes();}
	if(element == ORDER){RefrescarGrillaVentas();}
	if(element == PRODUCT){RefrescarGrillaProductos();}
}

void PrincipalWin::OnClickEliminar( wxCommandEvent& event )  {
	string label = wx_to_std(m_grilla->GetColLabelValue(3));
	int f = m_grilla->GetGridCursorRow();
	if (label == "E-mail") {
		EliminarDeTabla(CLIENT, f);
	} else if (label == "Total") {
		EliminarDeTabla(ORDER, f);
	} else if (label == "Cantidad") {
		EliminarDeTabla(PRODUCT, f);
	} else if (label == "id") {
		EliminarDeTabla(SELLER, f);
	}
}	

void PrincipalWin::EliminarSeller( )  {
	int f = m_grilla->GetGridCursorRow();
	m_store->remove(SELLER,f);
	
	m_grilla->DeleteRows(f);
	RefrescarGrillaVendedores();
}


void PrincipalWin::OnClicksavefile( wxCommandEvent& event ){
	m_store->saveAllData();
}
///								BOTON EDITAR

///								FIN EDIAT
///                            BOTON AGREGAR
void PrincipalWin::OnClickAgregarprincipal( wxCommandEvent& event )  {
	PersonWin *win = new PersonWin(this, m_store);
	///showmodal logra que hasta q no se termine no desaparece
	if(win->ShowModal()==1)///si es 1 refresca
		RefrescarGrillaClientes();
}

void PrincipalWin::OnClickAgregarSeller( wxCommandEvent& event )  {
	SellerWin *win = new SellerWin(this, m_store);
	
	if(win->ShowModal()==1)
	RefrescarGrillaVendedores();
}

void PrincipalWin::OnClickAgregarVenta( wxCommandEvent& event )  {
	VentaWin *win = new VentaWin(this, m_store);
	
	if(win->ShowModal()==1)
	RefrescarGrillaVentas();
}
void PrincipalWin::OnClickAgregarProducto( wxCommandEvent& event )  {
	ProductoWin *win = new ProductoWin(this, m_store);
	
	if(win->ShowModal()==1)
	RefrescarGrillaProductos();
}

///                     TERMINA BOTON AGREGAR
void PrincipalWin::RefrescarGrillaVentas(){
	Order temp = Order();
	Order& o = temp;
	if(m_grilla->GetNumberRows()!=0){
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	}
	for(int i=0; i<m_store->sizeOf(ORDER);i++){
		temp = m_store->getOrder(i);
		ostringstream ss;
		ss<<fixed<<setprecision(2)<<o.getAmmount(*m_store);
		
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i,0,m_store->getSellerById(o.get(SELL_SELLER)).get(SELLER_NAME));
		m_grilla->SetCellValue(i,1,printDate(o.getDate()));
		m_grilla->SetCellValue(i,2,to_string(o.getNumOfProducts()));
		m_grilla->SetCellValue(i,3,ss.str());
	}
	m_agregarPrincipal->Disconnect(wxID_ANY);
	m_agregarPrincipal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PrincipalWin::OnClickAgregarVenta), NULL, this );
	
	
}

///terminar cambuia de grilla
void PrincipalWin::onclickventas( wxCommandEvent& event )  {
	
	m_grilla->SetColLabelValue(0,"Nombre ");
	m_grilla->SetColLabelValue(1,"Fecha");
	m_grilla->SetColLabelValue(2,"Cant. productos");
	m_grilla->SetColLabelValue(3,"Total");
	RefrescarGrillaVentas();
}
void PrincipalWin::RefrescarGrillaProductos(){
	Product temp = Product();
	Product& p = temp;
	if(m_grilla->GetNumberRows()!=0){
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	}
	for(int i=0; i<m_store->sizeOf(PRODUCT);i++){
		ostringstream ss;
		ss<<fixed<<setprecision(2)<<p.getPrice();
		temp = m_store->getProduct(i);
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i,0,p.get(PRODUCT_NAME));
		m_grilla->SetCellValue(i,1,p.get(PRODUCT_BRAND));
		m_grilla->SetCellValue(i,2,ss.str());
		m_grilla->SetCellValue(i,3,to_string(p.getQuantity()));
	}
	m_agregarPrincipal->Disconnect(wxID_ANY);
	m_agregarPrincipal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PrincipalWin::OnClickAgregarProducto), NULL, this );	
}
void PrincipalWin::OnButtonProductos( wxCommandEvent& event )  {
	m_grilla->SetColLabelValue(0,"Marca");
	m_grilla->SetColLabelValue(1,"Nombre");
	m_grilla->SetColLabelValue(2,"Precio");
	m_grilla->SetColLabelValue(3,"Cantidad");
	RefrescarGrillaProductos();
}

void PrincipalWin::RefrescarGrillaVendedores(){
	Seller temp = Seller();
	Seller& s = temp;
	if(m_grilla->GetNumberRows()!=0){
		m_grilla->DeleteRows(0,m_grilla->GetNumberRows());
	}
	for(int i=0; i<m_store->sizeOf(SELLER);i++){
		temp = m_store->getSeller(i);
		m_grilla->AppendRows();
		m_grilla->SetCellValue(i,0,s.get(SELLER_NAME));
		m_grilla->SetCellValue(i,1,s.get(SELLER_PHONE));
		m_grilla->SetCellValue(i,2,s.get(SELLER_EMAIL));
		m_grilla->SetCellValue(i,3,s.get(SELLER_ID));
	}
	m_agregarPrincipal->Disconnect(wxID_ANY);
	m_agregarPrincipal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PrincipalWin::OnClickAgregarSeller ), NULL, this );

//	m_eliminar->Disconnect(wxID_ANY);
//	m_eliminar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(PrincipalWin::EliminarSeller ), NULL, this );
}
void PrincipalWin::OnButtonVendedores( wxCommandEvent& event )  {
	m_grilla->SetColLabelValue(0,"Nombre");
	m_grilla->SetColLabelValue(1,"Telefono");
	m_grilla->SetColLabelValue(2,"Email");
	m_grilla->SetColLabelValue(3,"id");
	RefrescarGrillaVendedores();
	
}

void PrincipalWin::OnButtonClientes( wxCommandEvent& event )  {
	
		m_grilla->SetColLabelValue(0,"Apellido y nombre");
		m_grilla->SetColLabelValue(1,"Direccion");
		m_grilla->SetColLabelValue(2,"Telefono");
		m_grilla->SetColLabelValue(3,"E-mail");
		RefrescarGrillaVendedores();
		
	
	RefrescarGrillaClientes();
}
