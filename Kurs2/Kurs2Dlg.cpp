
// Kurs2Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Kurs2.h"
#include "Kurs2Dlg.h"
#include "afxdialogex.h"
#include "Triangle.h"
#include "Line.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
extern int count=0;


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CKurs2Dlg




CKurs2Dlg::CKurs2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CKurs2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKurs2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKurs2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_Triangle, &CKurs2Dlg::OnTriangle)
	ON_COMMAND(ID_Work, &CKurs2Dlg::OnWork)
	ON_COMMAND(ID_Exit, &CKurs2Dlg::OnExit)
	ON_COMMAND(ID_About, &CKurs2Dlg::OnAbout)
	ON_COMMAND(ID_Open, &CKurs2Dlg::OnOpen)
END_MESSAGE_MAP()


// обработчики сообщений CKurs2Dlg

BOOL CKurs2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	ShowWindow(SW_MAXIMIZE);

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CKurs2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CKurs2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if(count>0)
		{
			CPaintDC dc(this);

	
		FILE *f = fopen("T.txt","r+");//відкриття файлу для зчитування
		
		int x1,y1,x2,y2,x3,y3,k=0;

		while(!feof(f))//підрахунок кількості трикутників
		{
			fscanf(f,"%i",&x1);
			fscanf(f,"%i",&y1);
			fscanf(f,"%i",&x2);
			fscanf(f,"%i",&y2);
			fscanf(f,"%i",&x3);
			fscanf(f,"%i",&y3);
			k++;
		}

		fseek(f,0,SEEK_SET);//повернення на початок файлу

		Triangle *t = new Triangle[k];//створення динамічного масиву трикутників

		int i=0;

		while (!feof(f))//занесення в масив трикутників
		{  
			fscanf(f,"%d%d",&x1,&y1);
			fscanf(f,"%d%d",&x2,&y2);
			fscanf(f,"%d%d",&x3,&y3);
			t[i++]=Triangle(x1,y1,x2,y2,x3,y3);
		}
				
		fclose(f);

		FILE *f1 = fopen("T.txt","w+");//відкритя файлу для запису
		
		double *cos1 = new double[k];//створення динамічного масиву під значення тупих кутів трикутника
		int m=0;
		
		for(int i=0;i<k;i++)
		{
			t[i].setColorTriangle(RGB(0,0,0));//вивід трикутників на графічний екран
			t[i].draw(dc);

			if (t[i].st())//якщо трикутник тупий
			{
				double a = acos(t[i].cos_a());//значення кутів трикутника
				double b = acos(t[i].cos_b());
				double c = acos(t[i].cos_c());
				fprintf(f,"Triangle %i: ",i);//запис у файл координат тупих трикунтиків
				fprintf(f,"x1=%i, ",t[i].x1);			
				fprintf(f,"y1=%i, ",t[i].y1);			
				fprintf(f,"x2=%i, ",t[i].x2);			
				fprintf(f,"y2=%i, ",t[i].y2);			
				fprintf(f,"x3=%i, ",t[i].x3);			
				fprintf(f,"y3=%i;\n",t[i].y3);
				if(a>1.57){cos1[m] = a;m++;}//вибір кута для запису у масив кутів
				else if(b>1.57){cos1[m] = b;m++;}
				else if(c>1.57){cos1[m] = c;m++;}
			}
			else m++;//якщо трикутник не тупий, значення масиву = 0
		}

		fclose(f1);

		bool r;
		for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			{
				if(i!=j)
				{
				if(t[i].intersection(t[j]))//перевірка перетину трикутників
					r=TRUE;
				}
			}

		if(r) MessageBox(L"Трикутники перетинаються!", _T("Повідомлення"), MB_OK);

		double max=0,min=0;
		int y=0,z=0;

		for(int i=0;i<k;i++)//визначення трикутника з найбільшим та найменшим тупим кутом
			{
					if(cos1[i]!=0)
					{
						if(max<cos1[i])
						{
							max = cos1[i];
							y=i;
						}

						if(min>cos1[i])
						{
							min = cos1[i];
							z=i;
						}
					}
			}

		t[y].setColorTriangle(RGB(255,0,0));//перефарбування трикутників з найбільшим та найменшим тупим кутом у інші кольори
		t[z].setColorTriangle(RGB(0,255,0));
		t[y].draw(dc);
		t[z].draw(dc);

		delete []t;//звільнення пам'яті динамічного масиву
		delete []cos1;

		}
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CKurs2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKurs2Dlg::OnTriangle()
{
	// TODO: добавьте свой код обработчика команд
	WinExec("notepad.exe T.txt", SW_SHOWNORMAL);
}


void CKurs2Dlg::OnWork()
{
	// TODO: добавьте свой код обработчика команд
	count = 1;
	count++;
	Invalidate();
}


void CKurs2Dlg::OnExit()
{
	// TODO: добавьте свой код обработчика команд
	exit(0);
}


void CKurs2Dlg::OnAbout()
{
	// TODO: добавьте свой код обработчика команд
	CAboutDlg AboutDlg;
	AboutDlg.DoModal();
}


void CKurs2Dlg::OnOpen()
{
	// TODO: добавьте свой код обработчика команд
	//ShellExecuteA( m_hWnd, "open", "try.bat", "", "", SW_SHOWNORMAL);
	WinExec("try.bat", SW_SHOWNORMAL);
}
