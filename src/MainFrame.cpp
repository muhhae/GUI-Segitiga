#include "include/MainFrame.hpp"

enum Ids{
    BUTTON_ID = 2,
    OUT_ID = 12,

    X_1 = 3,
    X_2 = 4,
    X_3 = 5,

    Y_1 = 6,
    Y_2 = 7,
    Y_3 = 8,

    Z_1 = 9,
    Z_2 = 10,
    Z_3 = 11,
};

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON(BUTTON_ID, MainFrame::OnButtonClick)
    EVT_TEXT(X_1, MainFrame::OnTextCtrlChange)
    EVT_TEXT(X_2, MainFrame::OnTextCtrlChange)
    EVT_TEXT(X_3, MainFrame::OnTextCtrlChange)
    EVT_TEXT(Y_1, MainFrame::OnTextCtrlChange)
    EVT_TEXT(Y_2, MainFrame::OnTextCtrlChange)
    EVT_TEXT(Y_3, MainFrame::OnTextCtrlChange)
    EVT_TEXT(Z_1, MainFrame::OnTextCtrlChange)
    EVT_TEXT(Z_2, MainFrame::OnTextCtrlChange)
    EVT_TEXT(Z_3, MainFrame::OnTextCtrlChange)
wxEND_EVENT_TABLE()

MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title)
{
    wxPanel* panel = new wxPanel(this);

    wxButton* button = new wxButton(panel, BUTTON_ID, "Hitung", wxPoint(100,100), wxSize(200, 50)); 

    wxTextCtrl* x1 = new wxTextCtrl(panel, X_1, "x", wxPoint(100, 175), wxSize(100, -1));
    wxTextCtrl* y1 = new wxTextCtrl(panel, Y_1, "y", wxPoint(210, 175), wxSize(100, -1));
    wxTextCtrl* z1 = new wxTextCtrl(panel, Z_1, "z", wxPoint(320, 175), wxSize(100, -1));

    wxTextCtrl* x2 = new wxTextCtrl(panel, X_2, "x", wxPoint(100, 225), wxSize(100, -1));
    wxTextCtrl* y2 = new wxTextCtrl(panel, Y_2, "y", wxPoint(210, 225), wxSize(100, -1));
    wxTextCtrl* z2 = new wxTextCtrl(panel, Z_2, "z", wxPoint(320, 225), wxSize(100, -1));

    wxTextCtrl* x3 = new wxTextCtrl(panel, X_3, "x", wxPoint(100, 275), wxSize(100, -1));
    wxTextCtrl* y3 = new wxTextCtrl(panel, Y_3, "y", wxPoint(210, 275), wxSize(100, -1));
    wxTextCtrl* z3 = new wxTextCtrl(panel, Z_3, "z", wxPoint(320, 275), wxSize(100, -1));

    int_out = new wxStaticText(panel, OUT_ID,"Jenis Segitiga : ", wxPoint(100, 320), wxSize(-1, -1));

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
        case X_1:
            evt.GetString().ToDouble(&x);
            T1[0] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;

        case Y_1:
            evt.GetString().ToDouble(&x);
            T1[1] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;

        case Z_1:
            evt.GetString().ToDouble(&x);
            T1[2] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;
        
        case X_2:
            evt.GetString().ToDouble(&x);
            T2[0] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;

        case Y_2:
            evt.GetString().ToDouble(&x);
            T2[1] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;

        case Z_2:
            evt.GetString().ToDouble(&x);
            T2[2] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;
        
        case X_3:
            evt.GetString().ToDouble(&x);
            T3[0] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;

        case Y_3:
            evt.GetString().ToDouble(&x);
            T3[1] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;

        case Z_3:
            evt.GetString().ToDouble(&x);
            T3[2] = (float) x;
            tes = wxString::Format("x1 : %f y1 : %f z1 : %f x2 : %f y2 : %f z2 : %f x3 : %f y3 : %f z3 : %f", T1[0], T1[1], T1[2], T2[0], T2[1], T2[2], T3[0], T3[1], T3[2]);
            wxLogStatus(tes);
            break;

        default:
            break;
    } 
}
