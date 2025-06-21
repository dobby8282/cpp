/* 
파일명: raii_pattern.cpp

RAII 패턴 (Resource Acquisition Is Initialization)
    자원의 획득과 해제를 객체의 생성과 소멸에 연결하여 자동 자원 관리를 수행하는 패턴
    
    - 자원 획득: 생성자에서 자원(메모리, 파일, 소켓 등)을 할당
    - 자동 해제: 소멸자에서 자원을 자동으로 해제
    - 스택 기반: 객체가 스코프를 벗어나면 자동으로 소멸자 호출
    - 예외 안전성: 예외 발생 시에도 소멸자가 호출되어 자원 누수 방지
    - 결정적 소멸: 객체의 생명주기가 명확하여 자원 해제 시점 예측 가능
    
    적용 영역:
    - 동적 메모리 관리 (smart pointer)
    - 파일 핸들링
    - 뮤텍스 잠금 관리
    - 네트워크 연결 관리
    - 데이터베이스 연결 관리
    
    장점:
    - 메모리 누수 방지: 자동 자원 해제로 누수 위험 제거
    - 코드 안전성: 예외 발생 시에도 자원이 안전하게 해제
    - 코드 간소화: 명시적 자원 해제 코드 불필요
    - 유지보수성: 자원 관리 로직이 한 곳에 집중
*/

#include <iostream>
#include <fstream>
using namespace std;

class FileManager {
private:
    ofstream file;
    string filename;
    
public:
    FileManager(const string& fname) : filename(fname) {
        file.open(filename);
        cout << "파일 열기: " << filename << endl;
    }
    
    ~FileManager() {
        if (file.is_open()) {
            file.close();
            cout << "파일 닫기: " << filename << endl;
        }
    }
    
    void write(const string& content) {
        if (file.is_open()) {
            file << content << endl;
        }
    }
};

class MemoryManager {
private:
    int* data;
    
public:
    MemoryManager(int size) {
        data = new int[size];
        cout << "메모리 할당: " << data << endl;
    }
    
    ~MemoryManager() {
        delete[] data;
        cout << "메모리 해제: " << data << endl;
    }
    
    int* get() { return data; }
};

int main() {
    {
        FileManager fm("test.txt");
        fm.write("RAII 패턴 테스트");
        
        MemoryManager mm(10);
        mm.get()[0] = 42;
    } // 여기서 자동으로 자원 해제
    
    cout << "자원이 안전하게 해제되었습니다." << endl;
    return 0;
}