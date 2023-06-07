#include "include/MainFrame.hpp"

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this);

    wxButton* button = new wxButton(panel, wxID_ANY, "RESET", wxPoint(100,100), wxSize(200, 50)); 
    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);

    pos.push_back (new wxTextCtrl(panel, 0, "", wxPoint(100, 175), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 1, "", wxPoint(210, 175), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 2, "", wxPoint(320, 175), wxSize(100, -1)));

    pos.push_back (new wxTextCtrl(panel, 3, "", wxPoint(100, 225), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 4, "", wxPoint(210, 225), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 5, "", wxPoint(320, 225), wxSize(100, -1)));

    pos.push_back (new wxTextCtrl(panel, 6, "", wxPoint(100, 275), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 7, "", wxPoint(210, 275), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 8, "", wxPoint(320, 275), wxSize(100, -1)));

    for (const auto& txt : pos)
    {
        txt->Bind(wxEVT_TEXT, &MainFrame::OnTextCtrlChange, this);
        txt->SetDefaultStyle(wxTextAttr(wxTE_CENTRE));

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
        txt->SetValue("");
        int_out->SetLabel("JENIS SEGITIGA : ");
    }
}

void MainFrame::OnTextCtrlChange(wxCommandEvent& evt)
{
    wxString tes;
    double x;
    evt.GetString().ToDouble(&x);

    switch (evt.GetId())
    {
        case 0:
            T1[0] = (float) x;
            break;

        case 1:
            T1[1] = (float) x;
            break;

        case 2:
            T1[2] = (float) x;
            break;
        
        case 3:
            T2[0] = (float) x;
            break;

        case 4:
            T2[1] = (float) x;
            break;

        case 5:
            T2[2] = (float) x;
            break;
        
        case 6:
            T3[0] = (float) x;
            break;

        case 7:
            T3[1] = (float) x;
            break;

        case 8:
            T3[2] = (float) x;
            break;

        default:
            break;
    }

    tes = wxString::Format("(%.2f, %.2f, %.2f) (%.2f, %.2f, %.2f) (%.2f, %.2f, %.2f)", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
    wxLogStatus(tes);

    triangle.SetT1(stl::Point2D(T1));
    triangle.SetT2(stl::Point2D(T2));
    triangle.SetT3(stl::Point2D(T3));

    wxString str = wxString::Format("JENIS SEGITIGA : %s", triangle.TriangleType());


    int_out->SetLabel(str);
}
