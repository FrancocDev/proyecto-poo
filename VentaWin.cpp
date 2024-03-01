#include "VentaWin.h"
#include "Store.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
#include <iomanip>
#include "Utils.h"
#include <ctime>
using namespace std;

VentaWin::VentaWin(wxWindow *parent, Store *store) : WxfbVenta(parent), m_store(store) {
	
}

void VentaWin::addProductToOrder( wxCommandEvent& event )  {
	string productNameInput = wx_to_std(m_cantidad->GetValue());
	Product product = m_store->getProductByName(productNameInput);
	
	if(product.get(PRODUCT_NAME) == productNameInput){
		auto it = products.find(product);
		if(it != products.end()){
			it -> second++;
		} else {
			products[product] = 1;
		}
		
		wxMessageBox("Producto agregado","VENTAS");
		float total = 0.00;
	if(m_orderGrid1->GetNumberRows()!=0){
		m_orderGrid1->DeleteRows(0,m_orderGrid1->GetNumberRows());
	}
	
	int i = 0;
	for (const auto& data : products) {
		const Product& temp = data.first;
		int quantity = data.second;
		
		ostringstream ss;
		ss << fixed << setprecision(2) << product.getPrice();
		
		m_orderGrid1->AppendRows();
		m_orderGrid1->SetCellValue(i, 0, wx_to_std(temp.get(PRODUCT_NAME)));
		m_orderGrid1->SetCellValue(i, 1, wx_to_std(temp.get(PRODUCT_BRAND)));
		m_orderGrid1->SetCellValue(i, 2, to_string(quantity));
		m_orderGrid1->SetCellValue(i, 3, wx_to_std(ss.str()));
		
		total += temp.getPrice() * quantity;
		i++;
	}
	
	ostringstream totalstring;
	totalstring << fixed << setprecision(2) << total;
	string printTotal = "Total: $" + totalstring.str();
	m_total->SetLabel(wx_to_std(printTotal));
	}
	else {
		wxMessageBox("Ese producto no existe","VENTAS");
	}

//	event.Skip();
}

void VentaWin::OnDobleClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VentaWin::OnClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VentaWin::OnClickAgregarVenta( wxCommandEvent& event )  {
	string sellerName = wx_to_std(m_vendedor->GetValue());
	Seller seller = m_store->getSellerByName(sellerName);
	string clientName = wx_to_std(m_cliente->GetValue());
	Client client = m_store->getClientByName(clientName);
	
	if(seller.get(SELLER_NAME) != sellerName || sellerName.size() == 0){
		wxMessageBox("No existe el vendedor", "VENTAS");
		return;
	}
	
	if(client.get(CLIENT_NAME) != clientName || clientName.size() == 0){
		wxMessageBox("No existe el cliente", "VENTAS");
		return;
	}
	
	if(m_dia->IsEmpty() || m_mes->IsEmpty() || m_anio->IsEmpty()){
		wxMessageBox("Debes ingresar una fecha", "VENTAS");
		return;
	}
	
	int day =  stoi(wx_to_std(m_dia->GetValue()));
	int month = stoi(wx_to_std(m_mes->GetValue()));
	int year = stoi(wx_to_std(m_anio->GetValue()));
	
	if(!isValidDate(day, month, year)){
		wxMessageBox("La fecha no es valida", "VENTAS");
		return;
	}
	
	if(products.size() == 0){
		wxMessageBox("Debes agregar productos","VENTAS");
		return;
	}
	
	// Checkeo si es valido el inventario
	for (const auto& data : products) {
		const Product& temp = data.first;
		int quantity = data.second;
		
			if (temp.getQuantity() < quantity){
				wxMessageBox("No hay suficientes " + temp.get(PRODUCT_NAME) + " en stock.", "VENTAS");
				return;
			}
	}
	
	//Arma la orden
	Order tempOrder(seller.get(SELLER_ID), client.get(CLIENT_ID), day, month, year);
	for (const auto& data : products) {
		const Product& temp = data.first;
		int quantity = data.second;
		string productId = temp.get(PRODUCT_ID);
		
		for(int j = 0; j < quantity; j++){
			tempOrder.addProduct(productId);
			m_store->sellProduct(productId);
		}
	}
	
	for(int k = 0; k < tempOrder.getNumOfProducts(); k++){
		cout<<tempOrder.getProductId(k)<<endl;
	}
	
	m_store->addOrder(std::move(tempOrder));
	m_store->saveIndividualData(ORDER);
	EndModal(1);
}

void VentaWin::OnClickCancelarVenta( wxCommandEvent& event )  {
	EndModal(0);
}

VentaWin::~VentaWin() {
	
}

