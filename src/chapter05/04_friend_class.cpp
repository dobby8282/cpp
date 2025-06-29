/*
주제: 프렌드(friend) 클래스
정의: 다른 클래스의 모든 private 멤버에 접근할 수 있는 클래스
*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;
    
    friend class AccountManager;  // friend 클래스 선언
    
public:
    BankAccount(string o, double b) : owner(o), balance(b) {}
    
    void display() {
        cout << owner << ": " << balance << "원" << endl;
    }
};

class AccountManager {
public:
    // friend 권한으로 private 멤버에 접근
    void transfer(BankAccount& from, BankAccount& to, double amount) {
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
            cout << "이체 완료: " << amount << "원" << endl;
        }
    }
    
    void displayBalance(const BankAccount& account) {
        cout << account.owner << "의 잔액: " << account.balance << "원" << endl;
    }
};

int main() {
    BankAccount acc1("김철수", 100000);
    BankAccount acc2("이영희", 50000);
    
    AccountManager manager;
    manager.transfer(acc1, acc2, 30000);
    
    acc1.display();
    acc2.display();
    
    return 0;
}