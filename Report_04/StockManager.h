#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class StockManager
{

public:
	StockManager();
	~StockManager();

	// 최초 포션 추가시 MAX_STOCK으로 세팅
	void initStock(string potionName);
	// 현재 포션 갯수확인
	int getStock(string potionName);
	// 포션을 반출함
	bool getOutPotion(string potionName);
	// 포션을 반납받음
	void returnPotion(string potionName);

private:
	map<string, int> potionStock;
	const int MAX_STOCK = 3;
};

