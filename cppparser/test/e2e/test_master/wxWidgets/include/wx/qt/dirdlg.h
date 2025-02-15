/////////////////////////////////////////////////////////////////////////////
// Name:        wx/qt/dirdlg.h
// Author:      Sean D'Epagnier
// Copyright:   (c) 2014 Sean D'Epagnier
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////
#ifndef _WX_QT_DIRDLG_H_
#  define _WX_QT_DIRDLG_H_
class QFileDialog;
class WXDLLIMPEXP_CORE wxDirDialog : public wxDirDialogBase
{
public:
  wxDirDialog()
  {
  }
  wxDirDialog(wxWindow* parent, const wxString& message = wxASCII_STR(wxDirSelectorPromptStr), const wxString& defaultPath = wxEmptyString, long style = wxDD_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, const wxString& name = wxASCII_STR(wxDirDialogNameStr));
  bool Create(wxWindow* parent, const wxString& message = wxASCII_STR(wxDirSelectorPromptStr), const wxString& defaultPath = wxEmptyString, long style = wxDD_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, const wxString& name = wxASCII_STR(wxDirDialogNameStr));
public:
  wxString GetPath() const override;
  void SetPath(const wxString& path) override;
private:
  virtual QFileDialog* GetQFileDialog() const;
  wxDECLARE_DYNAMIC_CLASS(wxDirDialog);
};
#endif
