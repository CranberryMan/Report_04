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

	// ���� ���� �߰��� MAX_STOCK���� ����
	void initStock(string potionName);
	// ���� ���� ����Ȯ��
	int getStock(string potionName);
	// ������ ������
	bool getOutPotion(string potionName);
	// ������ �ݳ�����
	void returnPotion(string potionName);

private:
	map<string, int> potionStock;
	const int MAX_STOCK = 3;
};

