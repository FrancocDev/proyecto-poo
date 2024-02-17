///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/toolbar.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WxfbPrincipal
///////////////////////////////////////////////////////////////////////////////
class WxfbPrincipal : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_file;
		wxMenu* m_selectFile;
		wxMenu* m_saveFileAs;
		wxMenu* m_SaveFile;
		wxMenu* m_optimizeFile;
		wxMenu* m_aboutUs;
		wxMenu* m_info;
		wxMenu* m_githubRepo;
		wxToolBar* tabSelector;
		wxButton* clientsButton;
		wxButton* sellsButton;
		wxButton* productsButton;
		wxButton* sellersButton;
		wxStaticText* currentTabName;
		wxTextCtrl* m_busqueda;
		wxButton* m_button2;
		wxGrid* m_grilla;
		wxButton* m_button6;
		wxButton* m_button3;
		wxButton* m_button4;

		// Virtual event handlers, override them in your derived class
		virtual void OnCambiaTamanio( wxSizeEvent& event ) { event.Skip(); }
		virtual void EnterBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDobleClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickAgregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditar( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEliminar( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbPrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agenda 1.3"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 700,500 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~WxfbPrincipal();

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
		wxButton* m_boton1;
		wxButton* m_boton2;

		// Virtual event handlers, override them in your derived class
		virtual void OnClickBoton1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBoton2( wxCommandEvent& event ) { event.Skip(); }


	public:

		WxfbPersona( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Persona"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~WxfbPersona();

};

