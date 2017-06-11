
// Kurs2Dlg.cpp : ���� ����������
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


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
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


// ���������� ���� CKurs2Dlg




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


// ����������� ��������� CKurs2Dlg

BOOL CKurs2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
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

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	ShowWindow(SW_MAXIMIZE);

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CKurs2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		if(count>0)
		{
			CPaintDC dc(this);

	
		FILE *f = fopen("T.txt","r+");//�������� ����� ��� ����������
		
		int x1,y1,x2,y2,x3,y3,k=0;

		while(!feof(f))//��������� ������� ����������
		{
			fscanf(f,"%i",&x1);
			fscanf(f,"%i",&y1);
			fscanf(f,"%i",&x2);
			fscanf(f,"%i",&y2);
			fscanf(f,"%i",&x3);
			fscanf(f,"%i",&y3);
			k++;
		}

		fseek(f,0,SEEK_SET);//���������� �� ������� �����

		Triangle *t = new Triangle[k];//��������� ���������� ������ ����������

		int i=0;

		while (!feof(f))//��������� � ����� ����������
		{  
			fscanf(f,"%d%d",&x1,&y1);
			fscanf(f,"%d%d",&x2,&y2);
			fscanf(f,"%d%d",&x3,&y3);
			t[i++]=Triangle(x1,y1,x2,y2,x3,y3);
		}
				
		fclose(f);

		FILE *f1 = fopen("T.txt","w+");//������� ����� ��� ������
		
		double *cos1 = new double[k];//��������� ���������� ������ �� �������� ����� ���� ����������
		int m=0;
		
		for(int i=0;i<k;i++)
		{
			t[i].setColorTriangle(RGB(0,0,0));//���� ���������� �� ��������� �����
			t[i].draw(dc);

			if (t[i].st())//���� ��������� �����
			{
				double a = acos(t[i].cos_a());//�������� ���� ����������
				double b = acos(t[i].cos_b());
				double c = acos(t[i].cos_c());
				fprintf(f,"Triangle %i: ",i);//����� � ���� ��������� ����� ����������
				fprintf(f,"x1=%i, ",t[i].x1);			
				fprintf(f,"y1=%i, ",t[i].y1);			
				fprintf(f,"x2=%i, ",t[i].x2);			
				fprintf(f,"y2=%i, ",t[i].y2);			
				fprintf(f,"x3=%i, ",t[i].x3);			
				fprintf(f,"y3=%i;\n",t[i].y3);
				if(a>1.57){cos1[m] = a;m++;}//���� ���� ��� ������ � ����� ����
				else if(b>1.57){cos1[m] = b;m++;}
				else if(c>1.57){cos1[m] = c;m++;}
			}
			else m++;//���� ��������� �� �����, �������� ������ = 0
		}

		fclose(f1);

		bool r;
		for(int i=0;i<k;i++)
		for(int j=0;j<k;j++)
			{
				if(i!=j)
				{
				if(t[i].intersection(t[j]))//�������� �������� ����������
					r=TRUE;
				}
			}

		if(r) MessageBox(L"���������� �������������!", _T("�����������"), MB_OK);

		double max=0,min=0;
		int y=0,z=0;

		for(int i=0;i<k;i++)//���������� ���������� � ��������� �� ��������� ����� �����
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

		t[y].setColorTriangle(RGB(255,0,0));//�������������� ���������� � ��������� �� ��������� ����� ����� � ���� �������
		t[z].setColorTriangle(RGB(0,255,0));
		t[y].draw(dc);
		t[z].draw(dc);

		delete []t;//��������� ���'�� ���������� ������
		delete []cos1;

		}
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CKurs2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CKurs2Dlg::OnTriangle()
{
	// TODO: �������� ���� ��� ����������� ������
	WinExec("notepad.exe T.txt", SW_SHOWNORMAL);
}


void CKurs2Dlg::OnWork()
{
	// TODO: �������� ���� ��� ����������� ������
	count = 1;
	count++;
	Invalidate();
}


void CKurs2Dlg::OnExit()
{
	// TODO: �������� ���� ��� ����������� ������
	exit(0);
}


void CKurs2Dlg::OnAbout()
{
	// TODO: �������� ���� ��� ����������� ������
	CAboutDlg AboutDlg;
	AboutDlg.DoModal();
}


void CKurs2Dlg::OnOpen()
{
	// TODO: �������� ���� ��� ����������� ������
	//ShellExecuteA( m_hWnd, "open", "try.bat", "", "", SW_SHOWNORMAL);
	WinExec("try.bat", SW_SHOWNORMAL);
}
