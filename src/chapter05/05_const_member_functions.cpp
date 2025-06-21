/* 
파일명: const_member_function.cpp

const 멤버 함수 (Const Member Function)
    객체의 상태(멤버 변수)를 변경하지 않는다고 약속하는 멤버 함수
    
    - const 멤버 함수: 함수명 뒤에 const 키워드를 붙여 선언
    - 읽기 전용: 멤버 변수의 값을 읽을 수만 있고 수정할 수 없음
    - const 객체 호출: const 객체는 const 멤버 함수만 호출 가능
    - 컴파일 타임 검사: const 위반 시 컴파일 에러 발생
    - mutable 키워드: const 함수에서도 수정 가능한 멤버 변수 지정
    - 함수 오버로딩: const 유무에 따라 다른 함수로 취급
    
    장점:
    - 코드 안정성: 의도치 않은 객체 상태 변경 방지
    - 인터페이스 명확성: 함수의 의도와 동작을 명확히 표현
    - const 객체 지원: const 객체에서도 getter 함수 사용 가능
*/

#include <iostream>
using namespace std;

class Book {
private:
    string title;
    int pages;
    mutable int readCount;  // const 함수에서도 수정 가능
    
public:
    Book(string t, int p) : title(t), pages(p), readCount(0) {}
    
    // const 멤버 함수
    string getTitle() const {
        readCount++;  // mutable이므로 수정 가능
        return title;
    }
    
    int getPages() const {
        return pages;
    }
    
    // 비 const 멤버 함수
    void setPages(int p) {
        pages = p;
    }
};

int main() {
    Book book("C++", 500);
    const Book constBook("상수책", 300);
    
    book.setPages(520);        // OK
    cout << constBook.getTitle() << endl;  // OK (const 함수)
    // constBook.setPages(400);  // 오류: const 객체는 비const 함수 호출 불가
    
    return 0;
}