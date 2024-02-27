///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Principal::Principal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_menubar1 = new wxMenuBar( 0 );
	m_file = new wxMenu();
	wxMenuItem* m_selectFile;
	m_selectFile = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Seleccionar Archivo") ) , wxEmptyString, wxITEM_RADIO );
	m_file->Append( m_selectFile );

	wxMenuItem* m_saveFileAs;
	m_saveFileAs = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Guardar archivo como...") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_saveFileAs );

	wxMenuItem* m_SaveFile;
	m_SaveFile = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Guardar Archivo") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_SaveFile );

	wxMenuItem* m_optimizeFile;
	m_optimizeFile = new wxMenuItem( m_file, wxID_ANY, wxString( wxT("Optimizar Archivo") ) , wxEmptyString, wxITEM_NORMAL );
	m_file->Append( m_optimizeFile );

	m_menubar1->Append( m_file, wxT("Archivo") );

	m_aboutUs = new wxMenu();
	wxMenuItem* m_info;
	m_info = new wxMenuItem( m_aboutUs, wxID_ANY, wxString( wxT("Información") ) , wxEmptyString, wxITEM_NORMAL );
	m_aboutUs->Append( m_info );

	wxMenuItem* m_githubRepo;
	m_githubRepo = new wxMenuItem( m_aboutUs, wxID_ANY, wxString( wxT("Ver en Github") ) , wxEmptyString, wxITEM_NORMAL );
	m_aboutUs->Append( m_githubRepo );

	m_menubar1->Append( m_aboutUs, wxT("Acerca de...") );

	this->SetMenuBar( m_menubar1 );

	tabSelector = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	clientsButton = new wxButton( tabSelector, wxID_ANY, wxT("Clientes"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );

	clientsButton->SetDefault();
	tabSelector->AddControl( clientsButton );
	sellsButton = new wxButton( tabSelector, wxID_ANY, wxT("Ventas"), wxDefaultPosition, wxDefaultSize, 0 );

	sellsButton->SetDefault();
	tabSelector->AddControl( sellsButton );
	productsButton = new wxButton( tabSelector, wxID_ANY, wxT("Productos"), wxDefaultPosition, wxDefaultSize, 0 );

	productsButton->SetDefault();
	tabSelector->AddControl( productsButton );
	sellersButton = new wxButton( tabSelector, wxID_ANY, wxT("Vendedores"), wxDefaultPosition, wxDefaultSize, 0 );
	tabSelector->AddControl( sellersButton );
	tabSelector->Realize();

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	m_busqueda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer3->Add( m_busqueda, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_button2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );

	m_grilla = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_grilla->CreateGrid( 0, 4 );
	m_grilla->EnableEditing( false );
	m_grilla->EnableGridLines( true );
	m_grilla->EnableDragGridSize( false );
	m_grilla->SetMargins( 0, 0 );

	// Columns
	m_grilla->SetColSize( 0, 219 );
	m_grilla->SetColSize( 1, 142 );
	m_grilla->SetColSize( 2, 132 );
	m_grilla->SetColSize( 3, 177 );
	m_grilla->EnableDragColMove( false );
	m_grilla->EnableDragColSize( true );
	m_grilla->SetColLabelValue( 0, wxT("Apellido y Nombres") );
	m_grilla->SetColLabelValue( 1, wxT("Direccion") );
	m_grilla->SetColLabelValue( 2, wxT("Telefono") );
	m_grilla->SetColLabelValue( 3, wxT("E-mail") );
	m_grilla->SetColLabelSize( 30 );
	m_grilla->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_grilla->EnableDragRowSize( true );
	m_grilla->SetRowLabelSize( 1 );
	m_grilla->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_grilla->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( m_grilla, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_agregarPrincipal = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_agregarPrincipal, 0, wxALL, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button3, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );


	bSizer2->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( Principal::OnCambiaTamanio ) );
	m_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Principal::OnClicksavefile ), this, m_SaveFile->GetId());
	clientsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnButtonClientes ), NULL, this );
	sellsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::onclickventas ), NULL, this );
	productsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnButtonProductos ), NULL, this );
	sellersButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnButtonVendedores ), NULL, this );
	m_busqueda->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Principal::EnterBuscar ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnClickBuscar ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( Principal::OnDobleClickGrilla ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Principal::OnClickGrilla ), NULL, this );
	m_agregarPrincipal->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnClickAgregarprincipal ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnClickEditar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnClickEliminar ), NULL, this );
}

Principal::~Principal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( Principal::OnCambiaTamanio ) );
	clientsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnButtonClientes ), NULL, this );
	sellsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::onclickventas ), NULL, this );
	productsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnButtonProductos ), NULL, this );
	sellersButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnButtonVendedores ), NULL, this );
	m_busqueda->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Principal::EnterBuscar ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnClickBuscar ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( Principal::OnDobleClickGrilla ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Principal::OnClickGrilla ), NULL, this );
	m_agregarPrincipal->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnClickAgregarprincipal ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnClickEditar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Principal::OnClickEliminar ), NULL, this );

}

WxfbPersona::WxfbPersona( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText2;
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_nombre, 1, wxALL, 5 );


	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText3;
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_apellido, 1, wxALL, 5 );


	bSizer4->Add( bSizer6, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText4;
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Telefono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_telefono, 1, wxALL, 5 );


	bSizer4->Add( bSizer7, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText12;
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Direccion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer9->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_direccion, 1, wxALL, 5 );


	bSizer4->Add( bSizer9, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText13;
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Localidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer10->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_localidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_localidad, 1, wxALL, 5 );


	bSizer4->Add( bSizer10, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText14;
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("E-mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer11->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_email, 1, wxALL, 5 );


	bSizer4->Add( bSizer11, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText15;
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Fecha Nacimiento:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer12->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_dia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	bSizer12->Add( m_dia, 1, wxALL, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer12->Add( m_staticText16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_mes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	bSizer12->Add( m_mes, 1, wxALL, 5 );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer12->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_anio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTER );
	bSizer12->Add( m_anio, 1, wxALL, 5 );


	bSizer4->Add( bSizer12, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_agregar, 0, wxALL, 5 );

	m_canelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_canelar, 0, wxALL, 5 );


	bSizer4->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );

	// Connect Events
	m_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPersona::OnClickAgregarPersona ), NULL, this );
	m_canelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPersona::OnClickCancelarPersona ), NULL, this );
}

WxfbPersona::~WxfbPersona()
{
	// Disconnect Events
	m_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPersona::OnClickAgregarPersona ), NULL, this );
	m_canelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPersona::OnClickCancelarPersona ), NULL, this );

}

WxfbVendedor::WxfbVendedor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText2;
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_nombre, 1, wxALL, 5 );


	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText3;
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_apellido, 1, wxALL, 5 );


	bSizer4->Add( bSizer6, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText4;
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Telefono:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer7->Add( m_staticText4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_telefono, 1, wxALL, 5 );


	bSizer4->Add( bSizer7, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText14;
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("E-mail:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer11->Add( m_staticText14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_email = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_email, 1, wxALL, 5 );


	bSizer4->Add( bSizer11, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_agregar, 0, wxALL, 5 );

	m_canelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_canelar, 0, wxALL, 5 );


	bSizer4->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );

	// Connect Events
	m_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVendedor::OnClickAgregarSeller ), NULL, this );
	m_canelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVendedor::OnClickCancelarSeller ), NULL, this );
}

WxfbVendedor::~WxfbVendedor()
{
	// Disconnect Events
	m_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVendedor::OnClickAgregarSeller ), NULL, this );
	m_canelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVendedor::OnClickCancelarSeller ), NULL, this );

}

WxfbProducto::WxfbProducto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText2;
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_nombre, 1, wxALL, 5 );


	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText21;
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Marca:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer51->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_marca = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( m_marca, 1, wxALL, 5 );


	bSizer4->Add( bSizer51, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer511;
	bSizer511 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText211;
	m_staticText211 = new wxStaticText( this, wxID_ANY, wxT("Precio: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText211->Wrap( -1 );
	bSizer511->Add( m_staticText211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_precio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer511->Add( m_precio, 1, wxALL, 5 );


	bSizer4->Add( bSizer511, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5111;
	bSizer5111 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText2111;
	m_staticText2111 = new wxStaticText( this, wxID_ANY, wxT("Cantidad: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2111->Wrap( -1 );
	bSizer5111->Add( m_staticText2111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_cantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5111->Add( m_cantidad, 1, wxALL, 5 );


	bSizer4->Add( bSizer5111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_agregar, 0, wxALL, 5 );

	m_canelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_canelar, 0, wxALL, 5 );


	bSizer4->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );

	// Connect Events
	m_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbProducto::OnClickAgregarProducto ), NULL, this );
	m_canelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbProducto::OnClickCancelarProducto ), NULL, this );
}

WxfbProducto::~WxfbProducto()
{
	// Disconnect Events
	m_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbProducto::OnClickAgregarProducto ), NULL, this );
	m_canelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbProducto::OnClickCancelarProducto ), NULL, this );

}

WxfbVenta::WxfbVenta( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText2;
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Vendedor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl56 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxPoint( -1,-1 ), wxDefaultSize, 0 );
	bSizer5->Add( m_textCtrl56, 1, wxALL|wxEXPAND, 5 );


	bSizer4->Add( bSizer5, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText21;
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Cliente"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer51->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_textCtrl57 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( m_textCtrl57, 1, wxALL, 5 );


	bSizer4->Add( bSizer51, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer511;
	bSizer511 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText211;
	m_staticText211 = new wxStaticText( this, wxID_ANY, wxT("Fecha "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText211->Wrap( -1 );
	bSizer511->Add( m_staticText211, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_dia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer511->Add( m_dia, 0, wxALL, 5 );

	m_mes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer511->Add( m_mes, 0, wxALL, 5 );

	m_anio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer511->Add( m_anio, 0, wxALL, 5 );


	bSizer4->Add( bSizer511, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5111;
	bSizer5111 = new wxBoxSizer( wxHORIZONTAL );

	wxStaticText* m_staticText2111;
	m_staticText2111 = new wxStaticText( this, wxID_ANY, wxT("Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2111->Wrap( -1 );
	bSizer5111->Add( m_staticText2111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_cantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5111->Add( m_cantidad, 1, wxALL, 5 );

	m_agregarproducto = new wxButton( this, wxID_ANY, wxT("Agregar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5111->Add( m_agregarproducto, 0, wxALL, 5 );


	bSizer4->Add( bSizer5111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer51111;
	bSizer51111 = new wxBoxSizer( wxHORIZONTAL );

	m_orderGrid1 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_orderGrid1->CreateGrid( 0, 4 );
	m_orderGrid1->EnableEditing( false );
	m_orderGrid1->EnableGridLines( true );
	m_orderGrid1->EnableDragGridSize( false );
	m_orderGrid1->SetMargins( 0, 0 );

	// Columns
	m_orderGrid1->SetColSize( 0, 219 );
	m_orderGrid1->SetColSize( 1, 142 );
	m_orderGrid1->SetColSize( 2, 132 );
	m_orderGrid1->SetColSize( 3, 177 );
	m_orderGrid1->EnableDragColMove( false );
	m_orderGrid1->EnableDragColSize( true );
	m_orderGrid1->SetColLabelValue( 0, wxT("Nombre") );
	m_orderGrid1->SetColLabelValue( 1, wxT("Marca") );
	m_orderGrid1->SetColLabelValue( 2, wxT("Precio") );
	m_orderGrid1->SetColLabelValue( 3, wxT("Cantidad") );
	m_orderGrid1->SetColLabelSize( 30 );
	m_orderGrid1->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_orderGrid1->EnableDragRowSize( true );
	m_orderGrid1->SetRowLabelSize( 1 );
	m_orderGrid1->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_orderGrid1->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer51111->Add( m_orderGrid1, 0, wxALL, 5 );


	bSizer4->Add( bSizer51111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer511111;
	bSizer511111 = new wxBoxSizer( wxHORIZONTAL );

	m_total = new wxStaticText( this, wxID_ANY, wxT("Total:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_total->Wrap( -1 );
	bSizer511111->Add( m_total, 0, wxALL, 5 );


	bSizer4->Add( bSizer511111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_agregar = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_agregar, 0, wxALL, 5 );

	m_canelar = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_canelar, 0, wxALL, 5 );


	bSizer4->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );

	// Connect Events
	m_agregarproducto->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVenta::addProductToOrder ), NULL, this );
	m_orderGrid1->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( WxfbVenta::OnDobleClickGrilla ), NULL, this );
	m_orderGrid1->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( WxfbVenta::OnClickGrilla ), NULL, this );
	m_agregar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVenta::OnClickAgregarVenta ), NULL, this );
	m_canelar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVenta::OnClickCancelarVenta ), NULL, this );
}

WxfbVenta::~WxfbVenta()
{
	// Disconnect Events
	m_agregarproducto->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVenta::addProductToOrder ), NULL, this );
	m_orderGrid1->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( WxfbVenta::OnDobleClickGrilla ), NULL, this );
	m_orderGrid1->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( WxfbVenta::OnClickGrilla ), NULL, this );
	m_agregar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVenta::OnClickAgregarVenta ), NULL, this );
	m_canelar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVenta::OnClickCancelarVenta ), NULL, this );

}
