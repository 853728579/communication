
#pragma once

class CManage
{
	CSockZy m_sock;
	CAdmin m_admin;

	void Menu();
public:
	void Start();

	CManage();
	~CManage();
};