#include "include/App.hpp"

wxIMPLEMENT_APP(App);

bool App::OnInit()
{
    MainFrame* mainFrame = new MainFrame("C++ GUI");
    mainFrame->SetClientSize(1024, 728);
    mainFrame->Center();
    mainFrame->Show();
    return true;
}