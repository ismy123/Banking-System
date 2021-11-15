//==================================================
#include<iostream>
#pragma warning( disable : 4996)
using namespace std;
//==================================================
//-------------------------------
#define NAMELEN 20	//	이름 길이

class SAccount
{
public:
	int _id;				//	계좌번호.
	int _balance;			//	잔액
	char _szName[NAMELEN];	//	이름.
};

class SAccountManager : public SAccount
{
public:
	SAccount g_AccountArray[100];	//	계좌정보 배열.
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
