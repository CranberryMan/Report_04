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

    // addRecipe �޼���: ��� ���(vector)�� �Ű������� �޵��� ����
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);

    // ��� ������ ��� �޼���
    void displayAllRecipes() const;

    // ���� ���� �� ���� ������ ���� ���ٰ� �����Ѵٸ� Ȯ���� �ϱ� ���� ���� ������ ����
    // ����ϱ� ���ϰ� �Ѵ�.
    bool isValidName(const string& name);

    ///  ������ ���� �߰��� ���� �˻� ���
    /* �ð� ���⵵�� �� �Լ����� ó���ϴ°� ���ٰ� �Ǵ��Ͽ� �� �Լ����� �� �� �˻��Ѵ�. */
    void findRecipesByNameAndJaryo(const string& name);
    void findRecipesPrint(vector<PotionRecipe> _PR) const;

    // ������ �޾ƿ��� ���� �Լ�.
    void potionGetout(const string& name);
    void potionGetin(const string& name);
};

