
// Kurs2.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CKurs2App:
// � ���������� ������� ������ ��. Kurs2.cpp
//

class CKurs2App : public CWinApp
{
public:
	CKurs2App();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CKurs2App theApp;