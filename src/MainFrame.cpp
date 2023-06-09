#include "include/MainFrame.hpp"

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this);
    // this->SetBackgroundColour(wxColor("white"));

    wxButton* button = new wxButton(panel, wxID_ANY, "RESET", wxPoint(100,100), wxSize(200, 50)); 
    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);

    pos.push_back (new wxTextCtrl(panel, 0, "", wxPoint(100, 175), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));
    pos.push_back (new wxTextCtrl(panel, 1, "", wxPoint(210, 175), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));
    pos.push_back (new wxTextCtrl(panel, 2, "", wxPoint(320, 175), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));

    pos.push_back (new wxTextCtrl(panel, 3, "", wxPoint(100, 225), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));
    pos.push_back (new wxTextCtrl(panel, 4, "", wxPoint(210, 225), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));
    pos.push_back (new wxTextCtrl(panel, 5, "", wxPoint(320, 225), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));

    pos.push_back (new wxTextCtrl(panel, 6, "", wxPoint(100, 275), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));
    pos.push_back (new wxTextCtrl(panel, 7, "", wxPoint(210, 275), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));
    pos.push_back (new wxTextCtrl(panel, 8, "", wxPoint(320, 275), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL));

    for (const auto& txt : pos)
    {
        txt->Bind(wxEVT_TEXT, &MainFrame::OnTextCtrlChange, this);

        if(txt->GetId() % 3 == 0) txt->SetHint("X");
        if(txt->GetId() % 3 == 1) txt->SetHint("Y");
        if(txt->GetId() % 3 == 2) txt->SetHint("Z");
    }

    int_out = new wxStaticText(panel, wxID_ANY,"JENIS SEGITIGA : ", wxPoint(100, 320), wxSize(-1, -1));

    int_out->SetFont(this->GetFont().Scale(1.5));


    CreateStatusBar();
}

void MainFrame::OnButtonClick(wxCommandEvent& evt)
{
    for (const auto& txt : pos)
    {
        txt->Clear();
    }
    int_out->SetLabel("JENIS SEGITIGA : ");
}

void MainFrame::OnTextCtrlChange(wxCommandEvent& evt)
{
    wxString tes;
    double x;
    evt.GetString().ToDouble(&x);

    int i = evt.GetId() / 3;
    int j = evt.GetId() % 3;

    T[i][j] = (float) x;

    tes = wxString::Format("(%.2f, %.2f, %.2f) (%.2f, %.2f, %.2f) (%.2f, %.2f, %.2f)", T[0][0], T[0][1], T[0][2], T[1][0], T[1][1], T[1][2], T[2][0], T[2][1], T[2][2]);
    wxLogStatus(tes);

    triangle.SetT1(stl::Point2D(T[0]));
    triangle.SetT2(stl::Point2D(T[1]));
    triangle.SetT3(stl::Point2D(T[2]));

    wxString str = wxString::Format("JENIS SEGITIGA : %s", triangle.TriangleType());


    int_out->SetLabel(str);
}
