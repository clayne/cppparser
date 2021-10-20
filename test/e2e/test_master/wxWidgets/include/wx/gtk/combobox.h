/////////////////////////////////////////////////////////////////////////////
// Name:        wx/gtk/combobox.h
// Purpose:
// Author:      Robert Roebling
// Created:     01/02/97
// Copyright:   (c) 1998 Robert Roebling
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////
#ifndef _WX_GTK_COMBOBOX_H_
#  define _WX_GTK_COMBOBOX_H_
#  include "wx/choice.h"
typedef struct _GtkEntry GtkEntry;
//-----------------------------------------------------------------------------
// wxComboBox
//-----------------------------------------------------------------------------
class WXDLLIMPEXP_CORE wxComboBox : public wxChoice, public wxTextEntry
{
public:
  wxComboBox()
    :  wxChoice(), wxTextEntry()
  {
        Init();
  }
  wxComboBox(wxWindow* parent, wxWindowID id, const wxString& value = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int n = 0, const wxString choices[] = NULL, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxASCII_STR(wxComboBoxNameStr))
    :  wxChoice(), wxTextEntry()
  {
        Init();
        Create(parent, id, value, pos, size, n, choices, style, validator, name);
  }
  wxComboBox(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxASCII_STR(wxComboBoxNameStr))
    :  wxChoice(), wxTextEntry()
  {
        Init();
        Create(parent, id, value, pos, size, choices, style, validator, name);
  }
  ~wxComboBox();
  bool Create(wxWindow* parent, wxWindowID id, const wxString& value = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int n = 0, const wxString choices[] = (const wxString*) NULL, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxASCII_STR(wxComboBoxNameStr));
  bool Create(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos, const wxSize& size, const wxArrayString& choices, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxASCII_STR(wxComboBoxNameStr));
    // Set/GetSelection() from wxTextEntry and wxChoice
  void SetSelection(int n) override
  {
 wxChoice::SetSelection(n);
  }
  void SetSelection(long from, long to) override
  {
 wxTextEntry::SetSelection(from, to);
  }
  int GetSelection() const override
  {
 return wxChoice::GetSelection();
  }
  void GetSelection(long* from, long* to) const override
  {
 return wxTextEntry::GetSelection(from, to);
  }
  wxString GetStringSelection() const override
  {
        return wxItemContainer::GetStringSelection();
  }
  void SetString(unsigned int n, const wxString& string) override;
  virtual void Popup();
  virtual void Dismiss();
  void Clear() override;
    // See wxComboBoxBase discussion of IsEmpty().
  bool IsListEmpty() const
  {
 return wxItemContainer::IsEmpty();
  }
  bool IsTextEmpty() const
  {
 return wxTextEntry::IsEmpty();
  }
  void OnChar(wxKeyEvent& event);
  void SetValue(const wxString& value) override;
    // Standard event handling
  void OnCut(wxCommandEvent& event);
  void OnCopy(wxCommandEvent& event);
  void OnPaste(wxCommandEvent& event);
  void OnUndo(wxCommandEvent& event);
  void OnRedo(wxCommandEvent& event);
  void OnDelete(wxCommandEvent& event);
  void OnSelectAll(wxCommandEvent& event);
  void OnUpdateCut(wxUpdateUIEvent& event);
  void OnUpdateCopy(wxUpdateUIEvent& event);
  void OnUpdatePaste(wxUpdateUIEvent& event);
  void OnUpdateUndo(wxUpdateUIEvent& event);
  void OnUpdateRedo(wxUpdateUIEvent& event);
  void OnUpdateDelete(wxUpdateUIEvent& event);
  void OnUpdateSelectAll(wxUpdateUIEvent& event);
  void GTKDisableEvents() override;
  void GTKEnableEvents() override;
  GtkWidget* GetConnectWidget() override;
  static wxVisualAttributes GetClassDefaultAttributes(wxWindowVariant variant = wxWINDOW_VARIANT_NORMAL);
  const wxTextEntry* WXGetTextEntry() const override
  {
 return this;
  }
protected:
    // From wxWindowGTK:
  GdkWindow* GTKGetWindow(wxArrayGdkWindows& windows) const override;
    // Widgets that use the style->base colour for the BG colour should
    // override this and return true.
  bool UseGTKStyleBase() const override
  {
 return true;
  }
    // Override in derived classes to create combo box widgets with
    // custom list stores.
  virtual void GTKCreateComboBoxWidget();
  wxSize DoGetSizeFromTextSize(int xlen, int ylen = -1) const override;
  GtkEntry* GetEntry() const override
  {
 return m_entry;
  }
  int GTKIMFilterKeypress(GdkEventKey* event) const override
  {
 return GTKEntryIMFilterKeypress(event);
  }
  GtkEntry* m_entry;
private:
    // From wxTextEntry:
  wxWindow* GetEditableWindow() override
  {
 return this;
  }
  GtkEditable* GetEditable() const override;
  void Init();
  wxDECLARE_DYNAMIC_CLASS_NO_COPY(wxComboBox);
  wxDECLARE_EVENT_TABLE();
};
#endif
