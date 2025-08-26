#pragma once
#include <iostream>
#include "RecipeManager.h"


using namespace std;
// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
	RecipeManager* myRecipeManager;
public :
	AlchemyWorkshop();
	~AlchemyWorkshop();
	void openWorkshop();

	// 유저에게 단답형 cin 입력받는 경우 재사용하기 위해 이 함수로 통일
	string userInputString(string coutMsg);

};