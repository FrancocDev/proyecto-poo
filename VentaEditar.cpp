#include "VentaEditar.h"
#include "string_conv.h"
#include <iomanip>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
using namespace std;

VentaEditar::VentaEditar(wxWindow *parent, Store *store, int i) : WxfbVentaEditar(parent), m_store(store), index(i) {
	Order &tempOrder = m_store->getOrder(i);
	originalId = tempOrder.get(SELL_ID);
	Seller &tempSeller = m_store->getSellerById(tempOrder.get(SELL_SELLER));
	Client &tempClient = m_store->getClientById(tempOrder.get(SELL_CLIENT));
	
	
	time_t date = tempOrder.getDate();
	
	m_vendedor->SetValue(tempSeller.get(SELLER_NAME));
	m_cliente->SetValue(tempClient.get(CLIENT_NAME));
	m_dia->SetValue(getDateDay(date));
	m_mes->SetValue(getDateMonth(date));
	m_anio->SetValue(getDateYear(date));
	
	for(int j=0; j < tempOrder.getNumOfProducts(); j++){
		string productId = tempOrder.getProductId(j);
		addProductToOrderId(productId);
	}
}

void VentaEditar::OnDobleClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VentaEditar::OnClickGrilla( wxGridEvent& event )  {
	event.Skip();
}

void VentaEditar::OnClickCancelarVenta( wxCommandEvent& event )  {
	event.Skip();
}

void VentaEditar::addProductToOrder( wxCommandEvent& event )  {
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
	
}

/// Agrega el producto por la id a el map products de la orden.
void VentaEditar::addProductToOrderId(string productId)  { 
	Product &product = m_store->getProductById(productId);
	
	if(product.get(PRODUCT_ID) == productId){
		auto it = products.find(product);
		if(it != products.end()){
			it -> second++;
		} else {
			products[product] = 1;
		}
		
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
}

void VentaEditar::OnClickAgregarVenta( wxCommandEvent& event )  {
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
	
	///Re agregar productos al stock
	Order &originalOrder = m_store->getOrderById(originalId); 
	for(int j=0; j < originalOrder.getNumOfProducts(); j++){
		string productId = originalOrder.getProductId(j);
		m_store->restoreProduct(productId);
	}
		
	for (const auto& data : products) {
		const Product& temp = data.first;
		Product sourceProduct = m_store->getProductById(temp.get(PRODUCT_ID));
		int quantity = data.second;
		
		if (sourceProduct.getQuantity() < quantity){
			wxMessageBox("No hay suficientes " + sourceProduct.get(PRODUCT_NAME) + " en stock.", "VENTAS");
			return;
		}
	}
	
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
	tempOrder.edit(SELL_ID, originalId);
	
	m_store->remove(ORDER, index);
	m_store->addOrder(std::move(tempOrder));
	m_store->saveIndividualData(ORDER);
	EndModal(1);
}	



VentaEditar::~VentaEditar() {
	
}

