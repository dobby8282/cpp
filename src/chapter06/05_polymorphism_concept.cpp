/* 
파일명: polymorphism_concept.cpp

다형성 (Polymorphism)
    같은 인터페이스를 통해 서로 다른 타입의 객체들이 각자의 방식으로 동작하는 것
    
    - 그리스어 "poly(많은)" + "morph(형태)" = 여러 형태
    - 같은 함수 호출: 동일한 방식으로 함수를 호출
    - 다른 동작: 실제 객체 타입에 따라 다르게 동작
    - 코드 재사용: 새로운 타입 추가 시 기존 코드 수정 불필요
    - 확장성: 개방-폐쇄 원칙 (확장에는 열려있고, 수정에는 닫혀있다)
    
    다형성 없는 코드의 문제점:
    - 타입별 개별 처리: 각 타입마다 별도 함수/조건문 필요
    - 확장성 부족: 새 타입 추가 시 모든 관련 코드 수정
    - 코드 중복: 비슷한 로직을 반복 작성
    - 유지보수 어려움: 하나의 변경이 여러 곳에 영향
    
    다형성의 장점:
    - 일관된 인터페이스: 모든 객체를 같은 방식으로 처리
    - 확장 용이: 새로운 타입 추가가 간단
    - 코드 간소화: 조건문 대신 객체의 특성 활용
    - 유지보수성: 각 타입의 로직이 해당 클래스에 캡슐화
    
    적용 사례:
    - 게임: 다양한 캐릭터들의 공통 동작 (이동, 공격)
    - 그래픽: 다양한 도형들의 공통 동작 (그리기, 넓이 계산)
    - 파일 처리: 다양한 파일 형식의 공통 동작 (읽기, 쓰기)
*/

#include <iostream>
#include <vector>
using namespace std;

class Shape {
protected:
    string name;
    
public:
    Shape(string n) : name(n) {}
    
    // 문제: virtual이 없으면 정적 바인딩
    void draw() {
        cout << name << "을(를) 그립니다" << endl;
    }
    
    double getArea() {
        cout << "기본 도형 - 넓이 계산 불가" << endl;
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : Shape("원"), radius(r) {}
    
    void draw() {
        cout << "반지름 " << radius << "인 원을 그립니다" << endl;
    }
    
    double getArea() {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
    
public:
    Rectangle(double w, double h) : Shape("사각형"), width(w), height(h) {}
    
    void draw() {
        cout << width << "x" << height << " 사각형을 그립니다" << endl;
    }
    
    double getArea() {
        return width * height;
    }
};

int main() {
    // 각각의 객체 생성
    Circle circle(5);
    Rectangle rect(4, 6);
    
    cout << "=== 직접 호출 (의도한 대로 동작) ===" << endl;
    circle.draw();        // 원 그리기
    rect.draw();          // 사각형 그리기
    

    
    // 문제 상황: 부모 포인터로 자식 객체들을 관리
    Shape* shapes[] = {&circle, &rect};
    
    cout << "\n--- 현재 결과 (다형성 없음) ---" << endl;
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();      // 모두 "기본 도형" 출력
        cout << "넓이: " << shapes[i]->getArea() << endl;  // 모두 0 출력
    }
    
    // cout << "\n=== 문제점 분석 ===" << endl;
    // cout << "1. 포인터 타입(Shape*)으로 함수가 결정됨" << endl;
    // cout << "2. 실제 객체 타입(Circle, Rectangle)이 무시됨" << endl;
    // cout << "3. 각 도형의 고유한 동작이 실행되지 않음" << endl;
    // cout << "\n해결책: virtual 키워드로 동적 바인딩 구현!" << endl;
    
    return 0;
}