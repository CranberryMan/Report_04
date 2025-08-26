#pragma once
#include <vector>
#include <string>
#include "PotionRecipe.h"
#include "StockManager.h";

using namespace std;

class RecipeManager
{
private:
    std::vector<PotionRecipe> recipes;
    StockManager* SM;

public:
    RecipeManager();
    ~RecipeManager();

    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // 모든 레시피 출력 메서드
    void displayAllRecipes() const;

    // 과제 내용 중 같은 레시피 명은 없다고 가정한다를 확고히 하기 위해 같은 레시피 명은
    // 등록하기 못하게 한다.
    bool isValidName(const string& name);

    ///  과제를 위해 추가한 물약 검색 기능
    /* 시간 복잡도상 한 함수에서 처리하는게 좋다고 판단하여 한 함수에서 둘 다 검색한다. */
    void findRecipesByNameAndJaryo(const string& name);
    void findRecipesPrint(vector<PotionRecipe> _PR) const;

    // 포션을 받아오기 위한 함수.
    void potionGetout(const string& name);
    void potionGetin(const string& name);
};

