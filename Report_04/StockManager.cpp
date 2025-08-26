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
		cout << "[" << potionName << "]은 없는 레시피입니다." << endl;
	else
		rtrInt = it->second;

	return rtrInt;
}

bool StockManager::getOutPotion(string potionName)
{
	bool rtrFlag = false;

	auto it = potionStock.find(potionName);
	if (it == potionStock.end())
		cout << "[" << potionName << "]은 없는 레시피입니다." << endl;
	else
	{
		if (it->second <= 0)
		{
			cout << "[" << potionName << "]의 재고가 없습니다." << endl;
		}
		else
		{
			it->second -= 1;
			cout << "[" << potionName << "]를 반출했습니다." << endl;
			cout << "[" << potionName << "]의 현재 재고 :" << it->second << endl;
			rtrFlag = true;
		}
	}


	return rtrFlag;
}

void StockManager::returnPotion(string potionName)
{
	auto it = potionStock.find(potionName);
	if (it == potionStock.end())
		cout << "[" << potionName << "]은 없는 레시피입니다." << endl;
	else
	{
		if (it->second >= MAX_STOCK)
		{
			cout << "[" << potionName << "]의 재고는 이미 최대치 입니다." << endl;
		}
		else
		{
			it->second += 1;
			cout << "[" << potionName << "]를 반환했습니다." << endl;
			cout << "[" << potionName << "]의 현재 재고 :" << it->second << endl;
		}
	}
}