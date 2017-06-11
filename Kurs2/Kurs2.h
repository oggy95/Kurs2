
// Kurs2.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CKurs2App:
// О реализации данного класса см. Kurs2.cpp
//

class CKurs2App : public CWinApp
{
public:
	CKurs2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CKurs2App theApp;