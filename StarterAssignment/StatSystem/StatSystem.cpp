#include <iostream>
#include <limits>

using namespace std;

class StatSystem 
{
private:
    int level;
    int hp, mp, atk, def, dex, intel;
    int potion;

public:
    StatSystem(int h, int m, int a, int d, int dx, int i) 
        : level(1), hp(h), mp(m), atk(a), def(d), dex(dx), intel(i), potion(5) {}

    void showStatus() 
    {
        cout << "\n=============================================" << endl;
        cout << "[ 현재 캐릭터 상태 ]" << endl;
        cout << "* Level : " << level << endl;
        cout << "* HP : " << hp << ", MP : " << mp << endl;
        cout << "* 공격력 : " << atk << ", 방어력 : " << def << endl;
        cout << "* 민첩 : " << dex << ", 지능 : " << intel << endl;
        cout << "* 남은 포션 수 : " << potion << endl;
        cout << "=============================================" << endl;
    }

    void hpUp() 
    {
        if (potion > 0) 
        {
            if (hp >= 1000)
            {
                cout << "* \n최대 체력 입니다" << endl;
            }
            else
            {
                hp += 20;
                potion--;
                cout << "* \nHP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n현재 HP: " << hp << "\n남은 포션 수: " << potion << endl;
            }
        }
        else 
        {
            cout << "\n포션이 부족합니다." << endl;
        }
    }

    void mpUp() 
    {
        if (potion > 0) 
        {
            if (mp >= 1000)
            {
                cout << "* \n최대 MP 입니다" << endl;
            }
            else
            {
                mp += 20;
                potion--;
                cout << "* \nMP가 20 증가되었습니다. 포션이 1개 차감됩니다.\n현재 MP: " << mp << "\n남은 포션 수: " << potion << endl;
            }
        }
        else 
        {
            cout << "\n포션이 부족합니다." << endl;
        }
    }

    void atkUp() 
    { 
        atk *= 2; 
        cout << "* \n공격력이 2배로 증가되었습니다.\n현재 공격력: " << atk << endl; 
    }

    void defUp() 
    { 
        def *= 2; 
        cout << "* \n방어력이 2배로 증가되었습니다.\n현재 방어력: " << def << endl;
    }

    void dexUp() 
    { 
        dex += 5; 
        cout << "* \n민첩이 5 증가했습니다! (현재: " << dex << ")" << endl;
    }

    void intelUp() 
    { 
        intel += 5; 
        cout << "* \n지능이 5 증가했습니다! (현재: " << intel << ")" << endl;
    }

    void levelUp() 
    {
        level++;
        cout << "* \n축하합니다! 레벨이 " << level << "(으)로 올랐습니다!" << endl;
        refillPotion();
    }

    void refillPotion() 
    {
        if (potion >= 99)
        {
            cout << "* \n포션이 가득 충전되어 있습니다" << endl;
        }
        else
        {
            potion += 3;
            cout << "* \n포션이 3개 충전되었습니다. (현재 " << potion << "개)" << endl;
        }
    }
};

int main() {
    int h, m, a, d, dx, i;

    while (true) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> h >> m;
        if (h >= 60 && m >= 60) break;
        cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }
    while (true) {
        cout << "공격력과 방어력을 입력해주세요: ";;
        cin >> a >> d;
        if (a >= 10 && a <= 30 && d <= 30 && d >= 10) break;
        cout << "공격력이나 방어력의 값이 너무 크거나 작습니다. 다시 입력해주세요." << endl;
    }
    while (true) {
        cout << "민첩과 지능을 입력해주세요: ";;
        cin >> dx >> i;
        if (dx >= 5 && dx <= 20 && i <= 20 && i >= 5) break;
        cout << "민첩이나 지능의 값이 너무 크거나 작습니다. 다시 입력해주세요." << endl;
    }

    StatSystem sys(h, m, a, d, dx, i);
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)\n";

    int choice;

    while (true) {
        cout << "\n=============================================\n<스탯 관리 시스템>\n1. HP UP\n2. MP UP\n3. 공격력 UP\n4. 방어력 UP\n5. 민첩 UP\n6. 지능 UP\n7. 현재 능력치\n8. Level UP\n0. 나가기\n번호를 선택해주세요: ";
        cin >> choice;
        if (choice == 0) break;
        switch (choice) {
        case 1: sys.hpUp(); break;
        case 2: sys.mpUp(); break;
        case 3: sys.atkUp(); break;
        case 4: sys.defUp(); break;
        case 5: sys.dexUp(); break;
        case 6: sys.intelUp(); break;
        case 7: sys.showStatus(); break;
        case 8: sys.levelUp(); break;
        }
    }
    cout << "프로그램을 종료합니다." << endl;
    return 0;
}