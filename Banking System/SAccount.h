//==================================================
#include<iostream>
#pragma warning( disable : 4996)
using namespace std;
//==================================================
//-------------------------------
#define NAMELEN 20	//	�̸� ����

class SAccount
{
public:
	int _id;				//	���¹�ȣ.
	int _balance;			//	�ܾ�
	char _szName[NAMELEN];	//	�̸�.
};

class SAccountManager : public SAccount
{
public:
	SAccount g_AccountArray[100];	//	�������� �迭.
	int g_index = 0;
public:
	void ShowMenu();
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void Inquire();
	void InquireAll();
	void StartManagement();
};
