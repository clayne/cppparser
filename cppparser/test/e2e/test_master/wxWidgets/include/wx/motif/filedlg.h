/////////////////////////////////////////////////////////////////////////////
// Name:        wx/motif/filedlg.h
// Purpose:     wxFileDialog class
// Author:      Julian Smart
// Modified by:
// Created:     17/09/98
// Copyright:   (c) Julian Smart
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////
#ifndef _WX_FILEDLG_H_
#  define _WX_FILEDLG_H_
//-------------------------------------------------------------------------
// wxFileDialog
//-------------------------------------------------------------------------
class WXDLLIMPEXP_CORE wxFileDialog : public wxFileDialogBase
{
  wxDECLARE_DYNAMIC_CLASS(wxFileDialog);
public:
    // For Motif
  static wxString m_fileSelectorAnswer;
  static bool m_fileSelectorReturned;
public:
  wxFileDialog(wxWindow* parent, const wxString& message = wxASCII_STR(wxFileSelectorPromptStr), const wxString& defaultDir = wxEmptyString, const wxString& defaultFile = wxEmptyString, const wxString& wildCard = wxASCII_STR(wxFileSelectorDefaultWildcardStr), long style = wxFD_DEFAULT_STYLE, const wxPoint& pos = wxDefaultPosition, const wxSize& sz = wxDefaultSize, const wxString& name = wxASCII_STR(wxFileDialogNameStr));
  virtual int ShowModal();
};
#endif
