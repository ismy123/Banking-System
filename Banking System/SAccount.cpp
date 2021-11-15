#include "SAccount.h"
#include <stdlib.h>

void SAccountManager::ShowMenu()
{
	system("cls");

	cout << "----- Menu -----" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 조 회" << endl;
	cout << "5. 전체 조회" << endl;
	cout << "6. 종 료" << endl;

}

void SAccountManager::MakeAccount()
{
	system("cls");

	int id;
	char name[NAMELEN];
	int balance;

	cout << "-- 계좌 개설 --" << endl;
	cout << "1. 계좌 ID : ";	cin >> id;
	cout << "2. 이 름 : ";		cin >> name;
	cout << "3. 입금액 : ";		cin >> balance;

	g_AccountArray[g_index]._id = id;
	g_AccountArray[g_index]._balance = balance;
	strcpy(g_AccountArray[g_index]._szName, name);

	++g_index;

	cout << "개설되었습니다.!!" << endl;

	getchar();
	getchar();
}

void SAccountManager::Deposit()
{
	system("cls");

	int id;
	cout << "-- 입금할 계좌 ID : ";	cin >> id;

	for (int curId = 0; curId < g_index; ++curId)
	{
		if (g_AccountArray[curId]._id == id)
		{
			int money;

			cout << "입금할 금액 : ";	cin >> money;
			g_AccountArray[curId]._balance += money;
			cout << "-- 입금 완료!!--" << endl;
			getchar();
			getchar();
			return;

		}//	if (g_AccountArray[curId]._id == id)

	}//	for (int curId = 0; curId < g_index; ++curId)

	cout << "-- 찾고자 하는 ID가 없습니다. !!--" << endl;

	getchar();
	getchar();
}

void SAccountManager::Withdraw()
{
	system("cls");

	int id;
	cout << "-- 출금할 계좌 ID : ";	cin >> id;

	for (int curId = 0; curId < g_index; ++curId)
	{
		if (g_AccountArray[curId]._id == id)
		{
			int money;

			cout << "출금할 금액 : ";	cin >> money;
			g_AccountArray[curId]._balance -= money;
			cout << "-- 출금 완료!!--" << endl;
			getchar();
			getchar();
			return;

		}//	if (g_AccountArray[curId]._id == id)

	}//	for (int curId = 0; curId < g_index; ++curId)

	cout << "-- 찾고자 하는 ID가 없습니다. !!--" << endl;

	getchar();
	getchar();
}

void SAccountManager::Inquire()
{
	system("cls");

	int id;
	cout << "-- 조회할 계좌 ID : ";	cin >> id;

	for (int curId = 0; curId < g_index; ++curId)
	{
		if (g_AccountArray[curId]._id == id)
		{
			cout << "1. 계좌 ID : " << g_AccountArray[curId]._id << endl;
			cout << "2. 이 름 : " << g_AccountArray[curId]._szName << endl;
			cout << "3. 잔 액 : " << g_AccountArray[curId]._balance << endl;
			getchar();
			getchar();
			return;

		}//	if (g_AccountArray[curId]._id == id)

	}//	for (int curId = 0; curId < g_index; ++curId)

	cout << "-- 찾고자 하는 ID가 없습니다. !!--" << endl;

	getchar();
	getchar();
}

void SAccountManager::InquireAll()
{
	system("cls");

	if (g_index == 0)
		cout << "개설된 계좌가 없습니다.!!" << endl;
	else
	{
		for (int curId = 0; curId < g_index; ++curId)
		{
			cout << "---------" << endl;
			cout << "1. 계좌 ID : " << g_AccountArray[curId]._id << endl;
			cout << "2. 이 름 : " << g_AccountArray[curId]._szName << endl;
			cout << "3. 잔 액 : " << g_AccountArray[curId]._balance << endl;
			cout << endl;

		}//	for (int curId = 0; curId < g_index; ++curId)

	}//	if(g_index == 0)

	getchar();
	getchar();
}

enum
{
	MAKEACCOUNT = 1,
	DEPOSIT,
	WITHDRAW,
	INQUIRE,
	INQUIREALL,
	EXIT,

};

void SAccountManager::StartManagement()
{
	int select;

	while (1)
	{
		ShowMenu();
		cout << "-- 선택 : ";	cin >> select;

		switch (select)
		{
		case MAKEACCOUNT:
			MakeAccount();
			break;

		case DEPOSIT:
			Deposit();
			break;

		case WITHDRAW:
			Withdraw();
			break;

		case INQUIRE:
			Inquire();
			break;

		case INQUIREALL:
			InquireAll();
			break;

		case EXIT:
			return;

		default:
			cout << " 다시 선택하세요 !!" << endl;
			system("pause");
			break;

		}//	switch (select)
	}//	while (1)
}
