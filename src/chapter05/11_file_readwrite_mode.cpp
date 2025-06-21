/* 
파일명: file_readwrite_mode.cpp

파일 읽기/쓰기 모드 (Read/Write Mode)
    하나의 파일에서 읽기와 쓰기를 동시에 수행하는 방법
    
    - fstream: 읽기와 쓰기가 모두 가능한 파일 스트림
    - ios::in | ios::out: 읽기와 쓰기 모드 동시 설정
    - seekg(): 읽기 위치 이동
    - seekp(): 쓰기 위치 이동
    - tellg(): 현재 읽기 위치 반환
    - tellp(): 현재 쓰기 위치 반환
    
    위치 지정자:
    - ios::beg: 파일 시작 위치
    - ios::end: 파일 끝 위치
    - ios::cur: 현재 위치
    
    활용 사례:
    - 파일 특정 부분 수정
    - 데이터베이스 파일 조작
    - 설정 파일 업데이트
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 초기 파일 생성
    fstream file("data.txt", ios::out);
    file << "Apple 100\n";
    file << "Banana 200\n";
    file << "Cherry 300\n";
    file.close();
    
    // 읽기/쓰기 모드로 열기
    file.open("data.txt", ios::in | ios::out);
    
    if (file.is_open()) {
        // 현재 내용 읽기
        cout << "=== 원본 내용 ===\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        
        // 두 번째 줄의 숫자 수정 (Banana 200 -> Banana 250)
        file.clear();  // 에러 플래그 초기화
        file.seekp(12, ios::beg);  // 쓰기 위치를 12번째 문자로 이동
        file << "250";
        
        // 수정된 내용 확인
        file.seekg(0, ios::beg);  // 읽기 위치를 파일 시작으로 이동
        cout << "\n=== 수정된 내용 ===\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        
        file.close();
        cout << "\n파일 수정 완료" << endl;
    }
    
    return 0;
}