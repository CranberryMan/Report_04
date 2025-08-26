#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// PotionRecipe Ŭ����: ��� ����� vector<string>���� ����
class PotionRecipe {
public:
    std::string potionName;
    std::vector<std::string> ingredients; // ���� ��ῡ�� ��� '���'���� ����

    // ������: ��� ����� �޾� �ʱ�ȭ�ϵ��� ����
    PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    ~PotionRecipe();
};