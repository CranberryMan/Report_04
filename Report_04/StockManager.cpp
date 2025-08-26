#include "StockManager.h"

StockManager::StockManager()
{

}

StockManager::~StockManager()
{

}

void StockManager::initStock(string potionName)
{
	potionStock.insert(pair<string, int>(potionName, MAX_STOCK));
}

int StockManager::getStock(string potionName)
{
	int rtrInt = -1;
	auto it = potionStock.find(potionName);
	if (it == potionStock.end())
		cout << "[" << potionName << "]�� ���� �������Դϴ�." << endl;
	else
		rtrInt = it->second;

	return rtrInt;
}

bool StockManager::getOutPotion(string potionName)
{
	bool rtrFlag = false;

	auto it = potionStock.find(potionName);
	if (it == potionStock.end())
		cout << "[" << potionName << "]�� ���� �������Դϴ�." << endl;
	else
	{
		if (it->second <= 0)
		{
			cout << "[" << potionName << "]�� ��� �����ϴ�." << endl;
		}
		else
		{
			it->second -= 1;
			cout << "[" << potionName << "]�� �����߽��ϴ�." << endl;
			cout << "[" << potionName << "]�� ���� ��� :" << it->second << endl;
			rtrFlag = true;
		}
	}


	return rtrFlag;
}

void StockManager::returnPotion(string potionName)
{
	auto it = potionStock.find(potionName);
	if (it == potionStock.end())
		cout << "[" << potionName << "]�� ���� �������Դϴ�." << endl;
	else
	{
		if (it->second >= MAX_STOCK)
		{
			cout << "[" << potionName << "]�� ���� �̹� �ִ�ġ �Դϴ�." << endl;
		}
		else
		{
			it->second += 1;
			cout << "[" << potionName << "]�� ��ȯ�߽��ϴ�." << endl;
			cout << "[" << potionName << "]�� ���� ��� :" << it->second << endl;
		}
	}
}