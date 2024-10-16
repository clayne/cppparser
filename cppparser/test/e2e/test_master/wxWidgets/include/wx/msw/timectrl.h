///////////////////////////////////////////////////////////////////////////////
// Name:        wx/msw/timectrl.h
// Purpose:     wxTimePickerCtrl for Windows.
// Author:      Vadim Zeitlin
// Created:     2011-09-22
// Copyright:   (c) 2011 Vadim Zeitlin <vadim@wxwidgets.org>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////
#ifndef _WX_MSW_TIMECTRL_H_
#  define _WX_MSW_TIMECTRL_H_
// ----------------------------------------------------------------------------
// wxTimePickerCtrl
// ----------------------------------------------------------------------------
class WXDLLIMPEXP_ADV wxTimePickerCtrl : public wxTimePickerCtrlBase
{
public:
    // ctors
  wxTimePickerCtrl()
  {
  }
  wxTimePickerCtrl(wxWindow* parent, wxWindowID id, const wxDateTime& dt = wxDefaultDateTime, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTP_DEFAULT, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTimePickerCtrlNameStr)
  {
    Create(parent, id, dt, pos, size, style, validator, name);
  }
  bool Create(wxWindow* parent, wxWindowID id, const wxDateTime& dt = wxDefaultDateTime, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTP_DEFAULT, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTimePickerCtrlNameStr)
  {
    return MSWCreateDateTimePicker(parent, id, dt, pos, size, style, validator, name);
  }
    // Override MSW-specific functions used during control creation.
  WXDWORD MSWGetStyle(long style, WXDWORD* exstyle) const override;
protected:
#  if  wxUSE_INTL
  wxLocaleInfo MSWGetFormat() const override;
#  endif
  bool MSWAllowsNone() const override
  {
    return false;
  }
  bool MSWOnDateTimeChange(const tagNMDATETIMECHANGE& dtch) override;
  wxDECLARE_DYNAMIC_CLASS_NO_COPY(wxTimePickerCtrl);
};
#endif
