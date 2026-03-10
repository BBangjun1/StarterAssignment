#include "item.h"

// 기본 생성자: 빈 이름과 0원으로 초기화
Item::Item() : name_(""), price_(0) {}

// 매개변수 생성자: 멤버 이니셜라이저 사용
Item::Item(string name, int price) : name_(name), price_(price) {}

// 정보 출력 로직
void Item::PrintInfo() const {
    cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
}

// Getter 구현
int Item::GetPrice() const {
    return price_;
}

string Item::GetName() const {
    return name_;
}