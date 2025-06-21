/* 
파일명: virtual_function_basics.cpp

가상 함수 기초 (Virtual Function Basics)
    런타임에 실제 객체의 타입에 따라 호출될 함수가 결정되는 함수
    
    - virtual 키워드: 함수를 가상 함수로 선언
    - 동적 바인딩: 실행 시간에 실제 객체 타입을 보고 함수 결정
    - 정적 바인딩: 컴파일 시간에 포인터/참조 타입으로 함수 결정
    - override 키워드: 가상 함수 재정의임을 명시 (C++11)
    - 다형성 구현: 같은 인터페이스로 다른 동작 수행
    - vtable: 가상 함수 테이블을 통한 함수 주소 관리
    
    동작 원리:
    1. virtual 함수가 있는 클래스는 vtable(가상 함수 테이블) 생성
    2. 객체 생성 시 vtable 포인터(vptr) 설정
    3. 가상 함수 호출 시 vtable을 통해 실제 함수 주소 찾기
    4. 실제 객체 타입의 함수 실행
    
    장점:
    - 다형성 구현: 하나의 인터페이스로 여러 구현체 사용
    - 확장성: 새로운 자식 클래스 추가 시 기존 코드 수정 불필요
    - 코드 재사용: 공통 인터페이스를 통한 일관된 처리
    
    주의사항:
    - 약간의 성능 오버헤드 (vtable 조회)
    - 메모리 오버헤드 (vptr 저장)
    - 소멸자도 virtual로 선언 권장
*/

#include <iostream>
using namespace std;

class Animal {
public:
    // 가상 함수
    virtual void makeSound() {
        cout << "동물이 소리를 냅니다." << endl;
    }
    
    // 일반 함수
    void move() {
        cout << "동물이 움직입니다." << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {  // override 키워드 사용 권장
        cout << "멍멍!" << endl;
    }
    
    void move() {
        cout << "개가 뛰어다닙니다." << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "야옹!" << endl;
    }
    
    void move() {
        cout << "고양이가 조용히 걷습니다." << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    
    cout << "=== 직접 호출 ===" << endl;
    dog.makeSound();  // 멍멍!
    cat.makeSound();  // 야옹!
    
    cout << "\n=== 포인터로 호출 ===" << endl;
    Animal* animals[] = {&dog, &cat};
    
    for (Animal* animal : animals) {
        animal->makeSound();  // 가상 함수: 실제 타입의 함수 호출
        animal->move();       // 일반 함수: Animal의 함수 호출
    }
    
    return 0;
}