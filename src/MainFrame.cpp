#include "include/MainFrame.hpp"

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this);

    wxButton* button = new wxButton(panel, wxID_ANY, "Hitung", wxPoint(100,100), wxSize(200, 50)); 
    button->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClick, this);

    std::vector<wxTextCtrl*> pos;

    pos.push_back (new wxTextCtrl(panel, 0, "x", wxPoint(100, 175), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 1, "y", wxPoint(210, 175), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 2, "z", wxPoint(320, 175), wxSize(100, -1)));

    pos.push_back (new wxTextCtrl(panel, 3, "x", wxPoint(100, 225), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 4, "y", wxPoint(210, 225), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 5, "z", wxPoint(320, 225), wxSize(100, -1)));

    pos.push_back (new wxTextCtrl(panel, 6, "x", wxPoint(100, 275), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 7, "y", wxPoint(210, 275), wxSize(100, -1)));
    pos.push_back (new wxTextCtrl(panel, 8, "z", wxPoint(320, 275), wxSize(100, -1)));

    for (const auto& txt : pos)
    {
        txt->Bind(wxEVT_TEXT, &MainFrame::OnTextCtrlChange, this);
    }

    int_out = new wxStaticText(panel, wxID_ANY,"Jenis Segitiga : ", wxPoint(100, 320), wxSize(-1, -1));

    int_out->SetFont(this->GetFont().Scale(2));

    CreateStatusBar();
}

void MainFrame::OnButtonClick(wxCommandEvent& evt)
{
    triangle.SetT1(stl::Point2D(T1));
    triangle.SetT2(stl::Point2D(T2));
    triangle.SetT3(stl::Point2D(T3));

    wxString str = wxString::Format("Jenis Segitiga : %s", triangle.TriangleType());


    int_out->SetLabel(str);
}

void MainFrame::OnSliderChange(wxCommandEvent& evt)
{
    wxString str = wxString::Format("Slider Value: %f", evt.GetInt());
    wxLogStatus(str);
}

void MainFrame::OnTextCtrlChange(wxCommandEvent& evt)
{
    wxString tes;
    double x;

    switch (evt.GetId())
    {
        case 0:
            evt.GetString().ToDouble(&x);
            T1[0] = (float) x;
            break;

        case 1:
            evt.GetString().ToDouble(&x);
            T1[1] = (float) x;
            break;

        case 2:
            evt.GetString().ToDouble(&x);
            T1[2] = (float) x;
            break;
        
        case 3:
            evt.GetString().ToDouble(&x);
            T2[0] = (float) x;
            break;

        case 4:
            evt.GetString().ToDouble(&x);
            T2[1] = (float) x;
            break;

        case 5:
            evt.GetString().ToDouble(&x);
            T2[2] = (float) x;
            break;
        
        case 6:
            evt.GetString().ToDouble(&x);
            T3[0] = (float) x;
            break;

        case 7:
            evt.GetString().ToDouble(&x);
            T3[1] = (float) x;
            break;

        case 8:
            evt.GetString().ToDouble(&x);
            T3[2] = (float) x;
            break;

        default:
            break;
    }

    tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
    wxLogStatus(tes);
}
