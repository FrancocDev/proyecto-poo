#include <wx/image.h>
#include "Application.h"
#include "PrincipalWin.h"
#include "PersonWin.h"
IMPLEMENT_APP(Application)

bool Application::OnInit() {
	m_store = new Store("store.dat");
	wxInitAllImageHandlers();
	PrincipalWin *win = new PrincipalWin(m_store);
	win->Show();
	return true;
}

