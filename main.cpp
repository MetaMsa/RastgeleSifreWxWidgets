#include <wx/wx.h>
#include <iostream>

class random {
    public:
     wxString sayi;
	 wxString harf;
	 wxString ozelkarakter;

	random(int kar, int ozelkar, int rakam) 
	{
	 srand(time(0));

	 if(kar>0)
	 {
	  for(int i=0;i<kar;i++)
	  {
	   harfgen(i);
	  }
	 }

	 if(ozelkar>0)
	 {
	  for(int i=0;i<ozelkar;i++)
	  {
	   ozelgen(i);
	  }
	 }

	 if(rakam>0)
	 {
	  for(int i=0;i<rakam;i++)
	  {
	   sayigen(i);
	  }
	 }
	}

	void sayigen(int i)
	{
        int x;
        do
        {
	     x=rand()%58;
        } while (x<48);
	    sayi+=char(x);
	}

	void harfgen(int i)
	{
        int x;
     do
     {
	  x=rand()%123;
     } while ((x<97&&x>90)||x<65);
	 harf+=char(x);
	}

	void ozelgen(int i)
	{
        int x;
     do
     {
        x=rand()%48;
     } while (x<33);
	 ozelkarakter+=char(x);
	}

    wxString result()
    {
        wxString s;
        s=harf+ozelkarakter+sayi;
        return s;
    }

	~random()
	{

	}
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};    
 
class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame(L"Rastgele Şifre Üretici", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    frame->Maximize(true);
    frame->SetIcon(wxICON(sample));

    return true;
}
 
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, L"Rastgele Şifre Üretici", pos, size)
{
    random r(5,5,5);

    wxTextCtrl* text = new wxTextCtrl(this, wxID_ANY, "", wxPoint(700, 20), wxSize(150, 50));

    text->SetEditable(false);
    text->AppendText(r.result());

    wxStaticText* label = new wxStaticText(this, wxID_ANY, "", wxPoint(0, 200), wxSize(150, 20));

    label->SetLabel("Harf sayisi: \n\n\nOzel Karakter sayisi: \n\n\nRakam sayisi: ");

    wxTextCtrl* harf = new wxTextCtrl(this, wxID_ANY, "", wxPoint(120, 200), wxSize(40, 30));
    harf->SetEditable(true);

    wxTextCtrl* ozel = new wxTextCtrl(this, wxID_ANY, "", wxPoint(120, 250), wxSize(40, 30));
    ozel->SetEditable(true);

    wxTextCtrl* rakam = new wxTextCtrl(this, wxID_ANY, "", wxPoint(120, 300), wxSize(40, 30));
    rakam->SetEditable(true);

    wxButton* button = new wxButton(this, wxID_ANY, L"Üret", wxPoint(700, 100), wxSize(150, 50));

    button->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event)
    {
        text->Clear();
        random r(wxAtoi(harf->GetValue()),wxAtoi(ozel->GetValue()),wxAtoi(rakam->GetValue()));
        text->AppendText(r.result());
    });
}   