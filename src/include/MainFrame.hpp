#ifndef _MAINFRAME_HPP
#define _MAINFRAME_HPP

#include <wx/wx.h>
#include <wx/spinctrl.h>

#include "triangles.hpp"

class MainFrame : public wxFrame
{
    public: 
        MainFrame(const wxString& title);
    private:

        stl::Triangle triangle;
        wxStaticText* int_out;
        std::vector<wxTextCtrl*> pos;

        float T[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

        void OnButtonClick(wxCommandEvent& evt);
        void OnTextCtrlChange(wxCommandEvent& evt);
};

#endif