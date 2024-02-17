///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

WxfbPrincipal::WxfbPrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );

	m_menubar1 = new wxMenuBar( 0 );
	m_file = new wxMenu();
	m_selectFile = new wxMenu();
	wxMenuItem* m_selectFileItem = new wxMenuItem( m_file, wxID_ANY, wxT("Seleccionar Archivo"), wxEmptyString, wxITEM_NORMAL, m_selectFile );
	m_file->Append( m_selectFileItem );

	m_saveFileAs = new wxMenu();
	wxMenuItem* m_saveFileAsItem = new wxMenuItem( m_file, wxID_ANY, wxT("Guardar archivo como..."), wxEmptyString, wxITEM_NORMAL, m_saveFileAs );
	m_file->Append( m_saveFileAsItem );

	m_SaveFile = new wxMenu();
	wxMenuItem* m_SaveFileItem = new wxMenuItem( m_file, wxID_ANY, wxT("Guardar Archivo"), wxEmptyString, wxITEM_NORMAL, m_SaveFile );
	m_file->Append( m_SaveFileItem );

	m_optimizeFile = new wxMenu();
	wxMenuItem* m_optimizeFileItem = new wxMenuItem( m_file, wxID_ANY, wxT("Optimizar Archivo"), wxEmptyString, wxITEM_NORMAL, m_optimizeFile );
	m_file->Append( m_optimizeFileItem );

	m_menubar1->Append( m_file, wxT("Archivo") );

	m_aboutUs = new wxMenu();
	m_info = new wxMenu();
	wxMenuItem* m_infoItem = new wxMenuItem( m_aboutUs, wxID_ANY, wxT("Información"), wxEmptyString, wxITEM_NORMAL, m_info );
	m_aboutUs->Append( m_infoItem );

	m_githubRepo = new wxMenu();
	wxMenuItem* m_githubRepoItem = new wxMenuItem( m_aboutUs, wxID_ANY, wxT("Ver en Github"), wxEmptyString, wxITEM_NORMAL, m_githubRepo );
	m_aboutUs->Append( m_githubRepoItem );

	m_menubar1->Append( m_aboutUs, wxT("Acerca de...") );

	this->SetMenuBar( m_menubar1 );

	tabSelector = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY );
	clientsButton = new wxButton( tabSelector, wxID_ANY, wxT("Clientes"), wxDefaultPosition, wxDefaultSize, wxBORDER_NONE );
	tabSelector->AddControl( clientsButton );
	sellsButton = new wxButton( tabSelector, wxID_ANY, wxT("Ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	tabSelector->AddControl( sellsButton );
	productsButton = new wxButton( tabSelector, wxID_ANY, wxT("Productos"), wxDefaultPosition, wxDefaultSize, 0 );
	tabSelector->AddControl( productsButton );
	sellersButton = new wxButton( tabSelector, wxID_ANY, wxT("Vendedores"), wxDefaultPosition, wxDefaultSize, 0 );
	tabSelector->AddControl( sellersButton );
	tabSelector->Realize();

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );

	currentTabName = new wxStaticText( this, wxID_ANY, wxT("Clientes"), wxDefaultPosition, wxDefaultSize, 0 );
	currentTabName->Wrap( -1 );
	currentTabName->SetMinSize( wxSize( 200,-1 ) );

	bSizer3->Add( currentTabName, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_busqueda = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER );
	bSizer3->Add( m_busqueda, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	m_button2 = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );

	m_button2->SetDefault();
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

	m_button6 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button6, 0, wxALL, 5 );

	m_button3 = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button3, 0, wxALL, 5 );

	m_button4 = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button4, 0, wxALL, 5 );


	bSizer2->Add( bSizer4, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( WxfbPrincipal::OnCambiaTamanio ) );
	m_busqueda->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( WxfbPrincipal::EnterBuscar ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickBuscar ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( WxfbPrincipal::OnDobleClickGrilla ), NULL, this );
	m_grilla->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( WxfbPrincipal::OnClickGrilla ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickAgregar ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickEditar ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickEliminar ), NULL, this );
}

WxfbPrincipal::~WxfbPrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( WxfbPrincipal::OnCambiaTamanio ) );
	m_busqueda->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( WxfbPrincipal::EnterBuscar ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickBuscar ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( WxfbPrincipal::OnDobleClickGrilla ), NULL, this );
	m_grilla->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( WxfbPrincipal::OnClickGrilla ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickAgregar ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickEditar ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickEliminar ), NULL, this );

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

	m_boton1 = new wxButton( this, wxID_ANY, wxT("Boton1"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_boton1, 0, wxALL, 5 );

	m_boton2 = new wxButton( this, wxID_ANY, wxT("Boton2"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_boton2, 0, wxALL, 5 );


	bSizer4->Add( bSizer13, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );

	// Connect Events
	m_boton1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPersona::OnClickBoton1 ), NULL, this );
	m_boton2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPersona::OnClickBoton2 ), NULL, this );
}

WxfbPersona::~WxfbPersona()
{
	// Disconnect Events
	m_boton1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPersona::OnClickBoton1 ), NULL, this );
	m_boton2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPersona::OnClickBoton2 ), NULL, this );

}
