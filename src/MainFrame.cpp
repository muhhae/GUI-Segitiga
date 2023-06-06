#include "include/MainFrame.hpp"

enum Ids{
    BUTTON_ID = 2,
    NUM_1 = 3,
    NUM_2 = 4,
    OUT_ID = 5
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClick)
    EVT_TEXT(NUM_1, MainFrame::OnTextCtrlChange)
    EVT_TEXT(NUM_2, MainFrame::OnTextCtrlChange)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this);

    wxButton* button = new wxButton(panel, BUTTON_ID, "Hitung", wxPoint(100,100), wxSize(200, 50)); 

    wxTextCtrl* num1 = new wxTextCtrl(panel, NUM_1, "Angka 1", wxPoint(100, 175), wxSize(200, -1));
    wxTextCtrl* num2 = new wxTextCtrl(panel, NUM_2, "Angka 2", wxPoint(100, 225), wxSize(200, -1));

    int_out = new wxStaticText(panel, OUT_ID, wxString::Format("Hasil Penjumlahan : %d", hasil), wxPoint(100, 270), wxSize(-1, -1));

    CreateStatusBar();
}

void MainFrame::OnButtonClick(wxCommandEvent& evt)
{
    hasil = A + B;
    wxString str = wxString::Format("Hasil Penjumlahan : %d", hasil);
    wxLogStatus(str);
    int_out->SetLabel(str);
}

void MainFrame::OnSliderChange(wxCommandEvent& evt)
{
    wxString str = wxString::Format("Slider Value: %d", evt.GetInt());
    wxLogStatus(str);
}

void MainFrame::OnTextCtrlChange(wxCommandEvent& evt)
{
    switch (evt.GetId())
    {
        case NUM_1:
            A = wxAtoi(evt.GetString());
            break;

        case NUM_2:
            B = wxAtoi(evt.GetString());
            break;
        
        default:
            break;
    } 
}
