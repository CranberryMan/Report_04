#pragma once
#include <iostream>
#include "RecipeManager.h"


using namespace std;
// AlchemyWorkshop Ŭ����: ������ ����� ����
class AlchemyWorkshop {
private:
	RecipeManager* myRecipeManager;
public :
	AlchemyWorkshop();
	~AlchemyWorkshop();
	void openWorkshop();

	// �������� �ܴ��� cin �Է¹޴� ��� �����ϱ� ���� �� �Լ��� ����
	string userInputString(string coutMsg);

};