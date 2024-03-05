///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/toolbar.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Principal
///////////////////////////////////////////////////////////////////////////////
class Principal : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_file;
		wxToolBar* tabSelector;
		wxButton* clientsButton;
		wxButton* sellsButton;
		wxButton* productsButton;
		wxButton* sellersButton;
		wxTextCtrl* m_busqueda;
		wxButton* m_button2;
		wxGrid* m_grilla;
		wxButton* m_agregarPrincipal;
		wxButton* m_VerEditar;
		wxButton* m_eliminar;

		// Virtual event handlers, override them in your derived class
		virtual void OnCambiaTamanio( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnClicksavefile( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void onclickventas( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonProductos( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonVendedores( wxCommandEvent& event ) { event.Skip(); }
		virtual void EnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickAgregarprincipal( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEliminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Principal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agenda 1.3"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,460 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Principal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbPersona
///////////////////////////////////////////////////////////////////////////////
class WxfbPersona : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_nombre;
		wxTextCtrl* m_apellido;
		wxTextCtrl* m_telefono;
		wxTextCtrl* m_direccion;
		wxTextCtrl* m_localidad;
		wxTextCtrl* m_email;
		wxTextCtrl* m_dia;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_mes;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_anio;
		wxButton* m_agregar;
		wxButton* m_canelar;

		// Virtual event handlers, override them in your derived class
		virtual void OnClickAgregarPersona( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarPersona( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbPersona( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Persona"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbPersona();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbPersonaEditar
///////////////////////////////////////////////////////////////////////////////
class WxfbPersonaEditar : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_nombre;
		wxTextCtrl* m_apellido;
		wxTextCtrl* m_telefono;
		wxTextCtrl* m_direccion;
		wxTextCtrl* m_localidad;
		wxTextCtrl* m_email;
		wxTextCtrl* m_dia;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_mes;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_anio;
		wxButton* m_agregar;
		wxButton* m_canelar;

		// Virtual event handlers, override them in your derived class
		virtual void OnClickAgregarPersona( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarPersona( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbPersonaEditar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Persona"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbPersonaEditar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbVendedor
///////////////////////////////////////////////////////////////////////////////
class WxfbVendedor : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_nombre;
		wxTextCtrl* m_apellido;
		wxTextCtrl* m_telefono;
		wxTextCtrl* m_email;
		wxButton* m_agregar;
		wxButton* m_canelar;

		// Virtual event handlers, override them in your derived class
		virtual void OnClickAgregarSeller( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarSeller( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbVendedor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Vendedor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbVendedor();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbVendedorEditar
///////////////////////////////////////////////////////////////////////////////
class WxfbVendedorEditar : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_nombre;
		wxTextCtrl* m_apellido;
		wxTextCtrl* m_telefono;
		wxTextCtrl* m_email;
		wxButton* m_agregar;
		wxButton* m_canelar;

		// Virtual event handlers, override them in your derived class
		virtual void OnClickAgregarSeller( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarSeller( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbVendedorEditar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Vendedor"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbVendedorEditar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbProducto
///////////////////////////////////////////////////////////////////////////////
class WxfbProducto : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_nombre;
		wxTextCtrl* m_marca;
		wxTextCtrl* m_precio;
		wxTextCtrl* m_cantidad;
		wxButton* m_agregar;
		wxButton* m_canelar;

		// Virtual event handlers, override them in your derived class
		virtual void OnClickAgregarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarProducto( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbProducto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbProducto();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbProductoEditar
///////////////////////////////////////////////////////////////////////////////
class WxfbProductoEditar : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_nombre;
		wxTextCtrl* m_marca;
		wxTextCtrl* m_precio;
		wxTextCtrl* m_cantidad;
		wxButton* m_agregar;
		wxButton* m_canelar;

		// Virtual event handlers, override them in your derived class
		virtual void OnClickAgregarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarProducto( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbProductoEditar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbProductoEditar();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbVenta
///////////////////////////////////////////////////////////////////////////////
class WxfbVenta : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_vendedor;
		wxTextCtrl* m_cliente;
		wxTextCtrl* m_dia;
		wxTextCtrl* m_mes;
		wxTextCtrl* m_anio;
		wxTextCtrl* m_cantidad;
		wxButton* m_agregarproducto;
		wxGrid* m_orderGrid1;
		wxStaticText* m_total;
		wxButton* m_agregar;
		wxButton* m_canelar;

		// Virtual event handlers, override them in your derived class
		virtual void addProductToOrder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickAgregarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarVenta( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbVenta( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Venta"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 659,446 ), long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbVenta();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbVentaEditar
///////////////////////////////////////////////////////////////////////////////
class WxfbVentaEditar : public wxDialog
{
	private:

	protected:
		wxTextCtrl* m_vendedor;
		wxTextCtrl* m_cliente;
		wxTextCtrl* m_dia;
		wxTextCtrl* m_mes;
		wxTextCtrl* m_anio;
		wxTextCtrl* m_cantidad;
		wxButton* m_agregarproducto;
		wxGrid* m_orderGrid1;
		wxStaticText* m_total;
		wxButton* m_agregar;
		wxButton* m_canelar;

		// Virtual event handlers, override them in your derived class
		virtual void addProductToOrder( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickAgregarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarVenta( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbVentaEditar( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Venta"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 659,446 ), long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbVentaEditar();

};

