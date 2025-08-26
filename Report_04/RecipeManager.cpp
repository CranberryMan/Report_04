#include "RecipeManager.h"

RecipeManager::RecipeManager()
{
    SM = new StockManager();

}

RecipeManager::~RecipeManager()
{
    SM = nullptr;
    delete SM;
}

void RecipeManager::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    recipes.push_back(PotionRecipe(name, ingredients));
    SM->initStock(name);
    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

void RecipeManager::displayAllRecipes() const
{
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    findRecipesPrint(this->recipes); // 아래에 출력 기능을 만들었음으로 통일해서 사용

    // **기존 코드 폐기**
    //for (size_t i = 0; i < recipes.size(); ++i) {
    //    std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl;
    //    std::cout << "  > 필요 재료: ";

    //    // 재료 목록을 순회하며 출력
    //    for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
    //        std::cout << recipes[i].ingredients[j];
    //        // 마지막 재료가 아니면 쉼표로 구분
    //        if (j < recipes[i].ingredients.size() - 1) {
    //            std::cout << ", ";
    //        }
    //    }
    //    std::cout << std::endl;
    //}
    //std::cout << "---------------------------\n";
}

bool RecipeManager::isValidName(const std::string& name)
{
    bool rtrFlag = true;
    for (PotionRecipe PR : this->recipes)
    {
        if (PR.potionName == name)
        {
            cout << "ERROR 동일한 이름의 레시피가 존재합니다." << endl;
            rtrFlag = false;
            break;
        }
    }

    return rtrFlag;
}

void RecipeManager::findRecipesByNameAndJaryo(const std::string& name)
{
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }
    // 유저가 인지하기 편하도록 이름이 검색 결과와 재료 검색 결과를 별도로 출력한다.
    // 검색부
    std::vector<PotionRecipe> tempRecipes_name;
    std::vector<PotionRecipe> tempRecipes_jaryo;
    for (PotionRecipe PR : this->recipes)
    {
        // 이름에 해당하는 포션을 push back
        if (PR.potionName == name)
        {
            tempRecipes_name.push_back(PR);
        }
        // 재료에 해당하는 포션을 push back
        for (string s : PR.ingredients)
        {
            if (s == name)
            {
                tempRecipes_jaryo.push_back(PR);
            }
        }
    }
    // 검색부
    // 
    // 출력부
    bool printCount = false;
    if (!tempRecipes_name.empty())
    {
        std::cout << "\n--- [ 이름이 같은 레시피 ] ---" << std::endl;
        findRecipesPrint(tempRecipes_name);
        printCount = true;
    }
    if (!tempRecipes_jaryo.empty())
    {
        std::cout << "\n--- [ 재료가 같은 레시피 ] ---" << std::endl;
        findRecipesPrint(tempRecipes_jaryo);
        printCount = true;
    }
    if (!printCount)
    {
        cout << "검색된 레시피가 없습니다!" << endl;
    }
    // 출력부
    return;
}

// findRecipes에서 이름별 검색과 재료별 검색시 검색 로직이 동일함으로 해당 함수를 사용
void RecipeManager::findRecipesPrint(vector<PotionRecipe> _PR) const
{
    for (PotionRecipe PR : _PR)
    {
        std::cout << "- 물약 이름: " << PR.potionName << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < PR.ingredients.size(); ++j) {
            std::cout << PR.ingredients[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < PR.ingredients.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        cout << "현재 재고 : " << SM->getStock(PR.potionName) << endl;
    }
    std::cout << "---------------------------\n";
}

void RecipeManager::potionGetout(const string& name)
{
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }
    if (!SM->getOutPotion(name))
        cout << "포션 반출에 실패했습니다." << endl;
}

void RecipeManager::potionGetin(const string& name)
{
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }
    SM->returnPotion(name);
}
