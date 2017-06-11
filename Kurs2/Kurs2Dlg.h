
// Kurs2Dlg.h : файл заголовка
//

#pragma once


// диалоговое окно CKurs2Dlg
class CKurs2Dlg : public CDialogEx
{
// Создание
public:
	CKurs2Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_KURS2_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
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
