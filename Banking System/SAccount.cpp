#include "SAccount.h"
#include <stdlib.h>

void SAccountManager::ShowMenu()
{
	system("cls");

	cout << "----- Menu -----" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �� ȸ" << endl;
	cout << "5. ��ü ��ȸ" << endl;
	cout << "6. �� ��" << endl;

}

void SAccountManager::MakeAccount()
{
	system("cls");

	int id;
	char name[NAMELEN];
	int balance;

	cout << "-- ���� ���� --" << endl;
	cout << "1. ���� ID : ";	cin >> id;
	cout << "2. �� �� : ";		cin >> name;
	cout << "3. �Աݾ� : ";		cin >> balance;

	g_AccountArray[g_index]._id = id;
	g_AccountArray[g_index]._balance = balance;
	strcpy(g_AccountArray[g_index]._szName, name);

	++g_index;

	cout << "�����Ǿ����ϴ�.!!" << endl;

	getchar();
	getchar();
}

void SAccountManager::Deposit()
{
	system("cls");

	int id;
	cout << "-- �Ա��� ���� ID : ";	cin >> id;

	for (int curId = 0; curId < g_index; ++curId)
	{
		if (g_AccountArray[curId]._id == id)
		{
			int money;

			cout << "�Ա��� �ݾ� : ";	cin >> money;
			g_AccountArray[curId]._balance += money;
			cout << "-- �Ա� �Ϸ�!!--" << endl;
			getchar();
			getchar();
			return;

		}//	if (g_AccountArray[curId]._id == id)

	}//	for (int curId = 0; curId < g_index; ++curId)

	cout << "-- ã���� �ϴ� ID�� �����ϴ�. !!--" << endl;

	getchar();
	getchar();
}

void SAccountManager::Withdraw()
{
	system("cls");

	int id;
	cout << "-- ����� ���� ID : ";	cin >> id;

	for (int curId = 0; curId < g_index; ++curId)
	{
		if (g_AccountArray[curId]._id == id)
		{
			int money;

			cout << "����� �ݾ� : ";	cin >> money;
			g_AccountArray[curId]._balance -= money;
			cout << "-- ��� �Ϸ�!!--" << endl;
			getchar();
			getchar();
			return;

		}//	if (g_AccountArray[curId]._id == id)

	}//	for (int curId = 0; curId < g_index; ++curId)

	cout << "-- ã���� �ϴ� ID�� �����ϴ�. !!--" << endl;

	getchar();
	getchar();
}

void SAccountManager::Inquire()
{
	system("cls");

	int id;
	cout << "-- ��ȸ�� ���� ID : ";	cin >> id;

	for (int curId = 0; curId < g_index; ++curId)
	{
		if (g_AccountArray[curId]._id == id)
		{
			cout << "1. ���� ID : " << g_AccountArray[curId]._id << endl;
			cout << "2. �� �� : " << g_AccountArray[curId]._szName << endl;
			cout << "3. �� �� : " << g_AccountArray[curId]._balance << endl;
			getchar();
			getchar();
			return;

		}//	if (g_AccountArray[curId]._id == id)

	}//	for (int curId = 0; curId < g_index; ++curId)

	cout << "-- ã���� �ϴ� ID�� �����ϴ�. !!--" << endl;

	getchar();
	getchar();
}

void SAccountManager::InquireAll()
{
	system("cls");

	if (g_index == 0)
		cout << "������ ���°� �����ϴ�.!!" << endl;
	else
	{
		for (int curId = 0; curId < g_index; ++curId)
		{
			cout << "---------" << endl;
			cout << "1. ���� ID : " << g_AccountArray[curId]._id << endl;
			cout << "2. �� �� : " << g_AccountArray[curId]._szName << endl;
			cout << "3. �� �� : " << g_AccountArray[curId]._balance << endl;
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
		cout << "-- ���� : ";	cin >> select;

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
			cout << " �ٽ� �����ϼ��� !!" << endl;
			system("pause");
			break;

		}//	switch (select)
	}//	while (1)
}
