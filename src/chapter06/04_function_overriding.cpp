/* 
파일명: function_overriding.cpp

함수 오버라이딩 (Function Overriding)
    자식 클래스에서 부모 클래스의 함수를 재정의하여 다른 동작을 구현하는 것
    
    - 함수 재정의: 상속받은 함수를 자식 클래스에서 새롭게 구현
    - 같은 시그니처: 함수명, 매개변수, 반환타입이 모두 동일해야 함
    - 정적 바인딩: 일반 함수는 컴파일 타임에 호출할 함수 결정
    - 부모 함수 호출: 클래스명::함수명() 형태로 부모 함수 명시적 호출 가능
    - 다형성 기반: virtual 키워드와 함께 사용하면 동적 바인딩 가능
    
    오버라이딩 vs 오버로딩:
    - 오버라이딩(Overriding): 상속 관계에서 같은 함수를 재정의
    - 오버로딩(Overloading): 같은 클래스에서 매개변수가 다른 동일 이름 함수
    
    주의사항:
    - virtual 없이는 정적 바인딩 (컴파일 타임에 타입으로 결정)
    - 포인터/참조 타입에 따라 호출되는 함수가 달라짐
    - 완전히 같은 시그니처가 아니면 오버로딩이 됨
*/

#include <iostream>
using namespace std;

class Shape {
protected:
    string name;
    
public:
    Shape(string n) : name(n) {}
    
    void display() {
        cout << "도형: " << name << endl;
    }
    
    double getArea() {
        cout << "기본 도형의 넓이" << endl;
        return 0;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : Shape("원"), radius(r) {}
    
    // 부모 클래스의 함수 오버라이딩
    double getArea() {
        cout << "원의 넓이 계산" << endl;
        return 3.14159 * radius * radius;
    }
    
    // 부모 함수 호출하기
    void showInfo() {
        Shape::display();  // 부모 클래스의 display() 호출
        cout << "반지름: " << radius << ", 넓이: " << getArea() << endl;
    }
};

int main() {
    Circle circle(5.0);
    
    circle.showInfo();
    
    // 부모 클래스 포인터로 자식 객체 참조
    Shape* shape = &circle;
    shape->display();     // 부모 클래스의 display()
    shape->getArea();     // 어떤 getArea()가 호출될까?
    
    return 0;
}