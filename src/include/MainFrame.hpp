#ifndef _MAINFRAME_HPP
#define _MAINFRAME_HPP

#include <wx/wx.h>
#include <wx/spinctrl.h>

class MainFrame : public wxFrame
{
    public: 
        MainFrame(const wxString& title);
    private:
        int A;
        int B;
        int hasil = 0;

        wxStaticText* int_out;

        void OnButtonClick(wxCommandEvent& evt);
        void OnSliderChange(wxCommandEvent& evt);
        void OnTextCtrlChange(wxCommandEvent& evt);
        wxDECLARE_EVENT_TABLE();
};

#endif