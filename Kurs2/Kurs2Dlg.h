
// Kurs2Dlg.h : ���� ���������
//

#pragma once


// ���������� ���� CKurs2Dlg
class CKurs2Dlg : public CDialogEx
{
// ��������
public:
	CKurs2Dlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_KURS2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTriangle();
	afx_msg void OnWork();
	afx_msg void OnExit();
	afx_msg void OnAbout();
	afx_msg void OnOpen();
};
