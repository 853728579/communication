
#include "./includes.h"

using namespace std;

void CManage::Menu()
{
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t Welcome to zy_xlj chat room" << endl;
	cout << endl << endl;
	cout << "\t\t (1).Sign in"<< endl;
	cout << endl;
	cout << "\t\t (2).Register an account"<< endl;
	cout << endl;
}

void CManage::Start()
{
	if (!m_sock.Create(0, SOCK_DGRAM))
	{
		cout<<"create error!"<<endl;
		system("pause");
		return ;
	}

	Menu();
	cout << "Please enter the option number above(1 or 2):";
	int type;
	cin >> type;
	switch (type)
	{
	case 1:
		m_admin.Login();
		break;
	case 2:break;
	default:
		cout << "\t\t input error!"<< endl;
		system("pause");
		break;
	}
}

CManage::CManage():m_admin(&m_sock)
{
	
}
CManage::~CManage()
{
	
}

