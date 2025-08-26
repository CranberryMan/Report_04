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
    std::cout << ">> ���ο� ������ '" << name << "'��(��) �߰��Ǿ����ϴ�." << std::endl;
}

void RecipeManager::displayAllRecipes() const
{
    if (recipes.empty()) {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "\n--- [ ��ü ������ ��� ] ---" << std::endl;
    findRecipesPrint(this->recipes); // �Ʒ��� ��� ����� ����������� �����ؼ� ���

    // **���� �ڵ� ���**
    //for (size_t i = 0; i < recipes.size(); ++i) {
    //    std::cout << "- ���� �̸�: " << recipes[i].potionName << std::endl;
    //    std::cout << "  > �ʿ� ���: ";

    //    // ��� ����� ��ȸ�ϸ� ���
    //    for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
    //        std::cout << recipes[i].ingredients[j];
    //        // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
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
            cout << "ERROR ������ �̸��� �����ǰ� �����մϴ�." << endl;
            rtrFlag = false;
            break;
        }
    }

    return rtrFlag;
}

void RecipeManager::findRecipesByNameAndJaryo(const std::string& name)
{
    if (recipes.empty()) {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return;
    }
    // ������ �����ϱ� ���ϵ��� �̸��� �˻� ����� ��� �˻� ����� ������ ����Ѵ�.
    // �˻���
    std::vector<PotionRecipe> tempRecipes_name;
    std::vector<PotionRecipe> tempRecipes_jaryo;
    for (PotionRecipe PR : this->recipes)
    {
        // �̸��� �ش��ϴ� ������ push back
        if (PR.potionName == name)
        {
            tempRecipes_name.push_back(PR);
        }
        // ��ῡ �ش��ϴ� ������ push back
        for (string s : PR.ingredients)
        {
            if (s == name)
            {
                tempRecipes_jaryo.push_back(PR);
            }
        }
    }
    // �˻���
    // 
    // ��º�
    bool printCount = false;
    if (!tempRecipes_name.empty())
    {
        std::cout << "\n--- [ �̸��� ���� ������ ] ---" << std::endl;
        findRecipesPrint(tempRecipes_name);
        printCount = true;
    }
    if (!tempRecipes_jaryo.empty())
    {
        std::cout << "\n--- [ ��ᰡ ���� ������ ] ---" << std::endl;
        findRecipesPrint(tempRecipes_jaryo);
        printCount = true;
    }
    if (!printCount)
    {
        cout << "�˻��� �����ǰ� �����ϴ�!" << endl;
    }
    // ��º�
    return;
}

// findRecipes���� �̸��� �˻��� ��Ằ �˻��� �˻� ������ ���������� �ش� �Լ��� ���
void RecipeManager::findRecipesPrint(vector<PotionRecipe> _PR) const
{
    for (PotionRecipe PR : _PR)
    {
        std::cout << "- ���� �̸�: " << PR.potionName << std::endl;
        std::cout << "  > �ʿ� ���: ";

        // ��� ����� ��ȸ�ϸ� ���
        for (size_t j = 0; j < PR.ingredients.size(); ++j) {
            std::cout << PR.ingredients[j];
            // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
            if (j < PR.ingredients.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        cout << "���� ��� : " << SM->getStock(PR.potionName) << endl;
    }
    std::cout << "---------------------------\n";
}

void RecipeManager::potionGetout(const string& name)
{
    if (recipes.empty()) {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return;
    }
    if (!SM->getOutPotion(name))
        cout << "���� ���⿡ �����߽��ϴ�." << endl;
}

void RecipeManager::potionGetin(const string& name)
{
    if (recipes.empty()) {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return;
    }
    SM->returnPotion(name);
}
