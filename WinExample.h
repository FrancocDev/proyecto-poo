#ifndef WIN_EXAMPLE_H
#define WIN_EXAMPLE_H
#include "wxfb_project.h"

class PrincipalWin : public PrincipalWin {
public:
	WinExample(wxWindow *parent=NULL);
	void OnButtonClose(wxCommandEvent &evt);
};

#endif
