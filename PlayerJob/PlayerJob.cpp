#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Monster; // 순환 참조를 위한 전방 선언

//  부모 클래스 Player 정의
class Player {
public:
    Player(string nickname) : nickname(nickname), level(1), HP(100), MP(50), power(20), defence(10), accuracy(10), speed(10) {}

    // 가상 소멸자: 자식 객체 해제 시 메모리 누수 방지 
    virtual ~Player() {}

    // 순수 가상 함수
    virtual void attack() = 0;
    virtual void attack(Monster* monster) = 0;

    void printPlayerStatus() {
        cout << "------------------------------------" << endl;
        cout << "* 현재 능력치" << endl;
        cout << "닉네임: " << nickname << " | 직업: " << job_name << endl;
        cout << "Lv. " << level << " | HP: " << HP << " | MP: " << MP << endl;
        cout << "공격력: " << power << " | 방어력: " << defence << endl;
        cout << "------------------------------------" << endl;
    }

    // Getter & Setter
    string getNickname() { return nickname; }
    int getHP() { return HP; }
    int getDefence() { return defence; }
    int getPower() { return power; }
    void setHP(int hp) { this->HP = (hp < 0) ? 0 : hp; }

protected:
    string job_name, nickname;
    int level, HP, MP, power, defence, accuracy, speed;
};

//  Monster 클래스 구현
class Monster {
public:
    Monster(string name) : name(name), HP(100), power(30), defence(10), speed(10) {}

    void attack(Player* player) {
        // 데미지 공식: 몬스터 공격력 - 플레이어 방어력 (최소 1)
        int damage = power - player->getDefence();
        if (damage <= 0) damage = 1;

        cout << "[!] " << name << "의 공격! " << player->getNickname() << "에게 " << damage << "의 피해!" << endl;
        player->setHP(player->getHP() - damage);

        if (player->getHP() > 0) cout << ">> " << player->getNickname() << "의 남은 HP: " << player->getHP() << endl;
    }

    // Getter & Setter
    string getName() { return name; }
    int getHP() { return HP; }
    int getDefence() { return defence; }
    void setHP(int hp) { this->HP = (hp < 0) ? 0 : hp; }

protected:
    string name;
    int HP, power, defence, speed;
};

//  직업 클래스 (상속 및 오버라이딩)
class Warrior : public Player {
public:
    Warrior(string nickname) : Player(nickname) { job_name = "전사"; HP = 150; power = 25; }
    void attack() override { cout << "전사가 검을 휘두릅니다!" << endl; }
    void attack(Monster* monster) override {
        int damage = power - monster->getDefence();
        if (damage <= 0) damage = 1;
        cout << "* " << monster->getName() << "에게 검으로 " << damage << "의 피해를 입혔다!" << endl;
        monster->setHP(monster->getHP() - damage);
        checkStatus(monster);
    }
private:
    void checkStatus(Monster* m) {
        if (m->getHP() > 0) cout << m->getName() << "의 남은 HP: " << m->getHP() << endl;
        else cout << "★ 축하합니다! " << m->getName() << "을(를) 처치했습니다!" << endl;
    }
};

class Archer : public Player {
public:
    Archer(string nickname) : Player(nickname) { job_name = "궁수"; power = 21; }
    void attack() override { cout << "궁수가 화살을 발사합니다!" << endl; }
    void attack(Monster* monster) override {
        int totalDamage = power - monster->getDefence();
        int hitDamage = (totalDamage / 3 <= 0) ? 1 : totalDamage / 3;

        for (int i = 0; i < 3; i++) {
            cout << "* " << monster->getName() << "에게 화살로 " << hitDamage << "의 피해를 입혔다!" << endl;
            monster->setHP(monster->getHP() - hitDamage);
        }
        if (monster->getHP() > 0) cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
        else cout << "★ 축하합니다! " << monster->getName() << "을(를) 처치했습니다!" << endl;
    }
};

class Thief : public Player {
public:
    Thief(string nickname) : Player(nickname) { job_name = "도적"; power = 25; }
    void attack() override { cout << "도적이 빠르게 단검을 찌릅니다!" << endl; }
    void attack(Monster* monster) override {
        int totalDamage = power - monster->getDefence();
        int hitDamage = (totalDamage / 5 <= 0) ? 1 : totalDamage / 5;

        for (int i = 0; i < 5; i++) {
            cout << "* " << monster->getName() << "에게 단검으로 " << hitDamage << "의 피해를 입혔다!" << endl;
            monster->setHP(monster->getHP() - hitDamage);
        }
        if (monster->getHP() > 0) cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
        else cout << "★ 축하합니다! " << monster->getName() << "을(를) 처치했습니다!" << endl;
    }
};

class Magician : public Player {
public:
    Magician(string nickname) : Player(nickname) { job_name = "마법사"; HP = 80; power = 35; }
    void attack() override { cout << "마법사가 마법 화살을 쏏니다!" << endl; }
    void attack(Monster* monster) override {
        int damage = power - monster->getDefence();
        if (damage <= 0) damage = 1;
        cout << "* " << monster->getName() << "에게 마법 화살로 " << damage << "의 피해를 입혔다!" << endl;
        monster->setHP(monster->getHP() - damage);
        if (monster->getHP() > 0) cout << monster->getName() << "의 남은 HP: " << monster->getHP() << endl;
        else cout << "★ 축하합니다! " << monster->getName() << "을(를) 처치했습니다!" << endl;
    }
};

//  메인 로직
int main() {
    string nickname;
    cout << "* 닉네임을 입력해주세요: ";
    cin >> nickname;

    Player* player = nullptr; // 포인터 초기화 
    int choice;
    cout << "<전직 시스템>\n1.전사 2.마법사 3.도적 4.궁수\n선택: ";
    cin >> choice;

    switch (choice) {
    case 1: player = new Warrior(nickname); break;
    case 2: player = new Magician(nickname); break;
    case 3: player = new Thief(nickname); break;
    case 4: player = new Archer(nickname); break;
    default: cout << "잘못된 선택입니다." << endl; return 0;
    }

    Monster* slime = new Monster("슬라임");

    player->attack();            // 단순 메시지 출력
    player->attack(slime);       // 몬스터 공격 로직 실행
    player->printPlayerStatus(); // 현재 상태 확인

    slime->attack(player);       // 몬스터의 반격

    // 메모리 해제 필수 
    if (player != nullptr) delete player;
    delete slime;

    return 0;
}