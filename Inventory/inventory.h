#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template <typename T>
class Inventory {
private:
    T* pItems_;      // 아이템 동적 배열 포인터
    int capacity_;   // 최대 저장 용량
    int size_;       // 현재 저장된 아이템 개수

public:
    // 생성자: 용량 설정 및 메모리 할당
    Inventory(int capacity = 10) {
        capacity_ = (capacity <= 0) ? 1 : capacity;
        size_ = 0;
        pItems_ = new T[capacity_];
        cout << "인벤토리 생성 완료 (용량: " << capacity_ << ")" << endl;
    }

    // 복사 생성자: 깊은 복사(Deep Copy)
    Inventory(const Inventory<T>& other) {
        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            pItems_[i] = other.pItems_[i];
        }
        cout << "인벤토리 복사 완료" << endl;
    }

    // 소멸자: 메모리 해제
    ~Inventory() {
        if (pItems_ != nullptr) {
            delete[] pItems_;
            pItems_ = nullptr;
        }
        cout << "인벤토리 메모리 해제 완료" << endl;
    }

    // 아이템 추가 (꽉 차면 2배 확장)
    void AddItem(const T& item) {
        if (size_ >= capacity_) {
            cout << "공간 부족! 용량을 2배로 확장합니다." << endl;
            Resize(capacity_ * 2);
        }
        pItems_[size_++] = item;
    }

    // 마지막 아이템 제거
    void RemoveLastItem() {
        if (size_ <= 0) {
            cout << "인벤토리가 비어있습니다." << endl;
            return;
        }
        size_--;
        cout << "마지막 아이템 제거 완료" << endl;
    }

    // 인벤토리 확장 (Resize)
    void Resize(int newCapacity) {
        if (newCapacity <= capacity_) return;

        T* pNewItems = new T[newCapacity];
        for (int i = 0; i < size_; i++) {
            pNewItems[i] = pItems_[i];
        }

        delete[] pItems_;
        pItems_ = pNewItems;
        capacity_ = newCapacity;
    }

    // 대입 함수 (Assign)
    void Assign(const Inventory<T>& other) {
        if (this == &other) return;
        delete[] pItems_;

        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            pItems_[i] = other.pItems_[i];
        }
        cout << "데이터 대입 완료" << endl;
    }

    // 정렬 (C++ 표준 정렬 활용)
    void SortItems(bool (*compare)(const T&, const T&)) {
        if (size_ > 1) {
            sort(pItems_, pItems_ + size_, compare);
            cout << "아이템 정렬 완료" << endl;
        }
    }

    // 전체 출력
    void PrintAllItems() const {
        cout << "\n--- 인벤토리 목록 (Size: " << size_ << "/" << capacity_ << ") ---" << endl;
        for (int i = 0; i < size_; i++) {
            pItems_[i].PrintInfo();
        }
        cout << "------------------------------------------\n" << endl;
    }

    int GetSize() const { return size_; }
    int GetCapacity() const { return capacity_; }
};