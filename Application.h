#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Store.h"
class Application : public wxApp {
public:
	Store *m_store;
	virtual bool OnInit();
};

#endif
