/* 
파일명: constructor_destructor_order.cpp

생성자/소멸자 호출 순서 (Constructor/Destructor Call Order)
    상속 관계에서 객체 생성 시 부모→자식, 소멸 시 자식→부모 순으로 생성자/소멸자 호출
    
    생성 과정:
    1. 하나의 자식 객체 메모리 공간 할당
    2. Base 생성자 호출 → Base 부분 초기화
    3. Derived 생성자 호출 → Derived 부분 초기화  
    4. GrandChild 생성자 호출 → GrandChild 부분 초기화
    
    소멸 과정:
    1. GrandChild 소멸자 호출 → GrandChild 부분 정리
    2. Derived 소멸자 호출 → Derived 부분 정리
    3. Base 소멸자 호출 → Base 부분 정리
    4. 객체 메모리 공간 해제
    
    중요 개념:
    - 객체는 하나만 생성됨 (자식 객체)
    - 부모 객체가 별도로 생성되지 않음
    - 생성자/소멸자는 객체의 각 부분을 초기화/정리하는 역할
    - 상속은 "부분-전체" 관계 (composition이 아닌 inheritance)
*/

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base 생성자" << endl;
    }
    
    ~Base() {
        cout << "Base 소멸자" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived 생성자" << endl;
    }
    
    ~Derived() {
        cout << "Derived 소멸자" << endl;
    }
};

class GrandChild : public Derived {
public:
    GrandChild() {
        cout << "GrandChild 생성자" << endl;
    }
    
    ~GrandChild() {
        cout << "GrandChild 소멸자" << endl;
    }
};

int main() {
    cout << "=== 객체 생성 ===" << endl;
    {
        GrandChild gc;
    } // 여기서 소멸
    cout << "=== 객체 소멸 완료 ===" << endl;
    
    return 0;
}
