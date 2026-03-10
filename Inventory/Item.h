#pragma once
#include <string>
#include <iostream>

using namespace std;

class Item {
private:
    string name_;
    int price_;

public:
    // 기본 생성자 (Inventory의 배열 할당을 위해 필수)
    Item();

    // 매개변수가 있는 생성자
    Item(string name, int price);

    // 정보 출력 함수
    void PrintInfo() const;

    // Getter 함수 (가격 비교 등을 위해 필요)
    int GetPrice() const;
    string GetName() const;
};