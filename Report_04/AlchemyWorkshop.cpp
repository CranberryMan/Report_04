#include "AlchemyWorkshop.h"

AlchemyWorkshop::AlchemyWorkshop()
{
    myRecipeManager = new RecipeManager();
}
AlchemyWorkshop::~AlchemyWorkshop()
{
    myRecipeManager = nullptr;
    delete myRecipeManager;

    cout << "연금술 공방 Shut down!" << endl;
}

void AlchemyWorkshop::openWorkshop()
{
    while (true) {
        std::cout << "⚗️ 연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 레시피 검색" << std::endl;
        std::cout << "4. 포션 반출" << std::endl;
        std::cout << "5. 포션 회수" << std::endl;
        std::cout << "6. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            std::string name = userInputString("물약 이름: ");

            // 동일한 이름의 레시피 입력받지 못하도록
            if (!myRecipeManager->isValidName(name))
            {
                continue;
            }
            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true) {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) {
                myRecipeManager->addRecipe(name, ingredients_input);
            }
            else {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2) {
            myRecipeManager->displayAllRecipes();

        }
        else if (choice == 3) {
            std::string findName = userInputString("검색 단어: ");
            myRecipeManager->findRecipesByNameAndJaryo(findName);
        }
        else if (choice == 4) {
            std::string name = userInputString("반출할 물약 이름: ");
            myRecipeManager->potionGetout(name);
        }
        else if (choice == 5) {
            std::string name = userInputString("반입할 물약 이름: ");
            myRecipeManager->potionGetin(name);
        }
        else if (choice == 6) {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;

        }
        else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }
}

string AlchemyWorkshop::userInputString(string coutMsg)
{
    std::string rtrStr;
    std::cout << coutMsg;
    std::cin.ignore(10000, '\n');
    std::getline(std::cin, rtrStr);

    return rtrStr;
}