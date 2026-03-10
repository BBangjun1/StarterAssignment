#include <iostream>
#include "inventory.h"
#include "item.h"

using namespace std;

// 아이템 가격 비교용 외부 함수
bool compareItemsByPrice(const Item& a, const Item& b) {
    return a.GetPrice() < b.GetPrice();
}

int main() {
    // 인벤토리 생성
    Inventory<Item> myInven(3);

    // 아이템 추가
    myInven.AddItem(Item("전설의 검", 5000));
    myInven.AddItem(Item("빨간 포션", 50));
    myInven.AddItem(Item("나무 방패", 150));
    myInven.AddItem(Item("전설의 활", 4500));

    cout << "--- 정렬 전 목록 ---" << endl;
    myInven.PrintAllItems();

    // 가격순 정렬
    myInven.SortItems(compareItemsByPrice);

    cout << "--- 가격순 정렬 후 목록 ---" << endl;
    myInven.PrintAllItems();

    return 0;
}