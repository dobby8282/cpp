/* 
파일명: file_read_basic.cpp

파일 읽기 (File Reading)
    ifstream을 사용하여 텍스트 파일에서 데이터를 읽어오는 기본 방법
    
    - ifstream: Input File Stream, 파일에서 데이터를 읽기 위한 클래스
    - ios::in: 읽기 모드 (기본값이므로 생략 가능)
    - getline(): 한 줄씩 읽기
    - >> 연산자: 공백 단위로 읽기
    - eof(): 파일 끝 확인
    - good(): 파일 상태 확인
    
    읽기 방법:
    - 줄 단위 읽기: getline(file, string)
    - 단어 단위 읽기: file >> variable
    - 전체 파일 읽기: while문과 eof() 활용
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("output.txt");
    string line;
    
    if (inFile.is_open()) {
        cout << "=== 파일 내용 ===\n";
        
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        
        inFile.close();
        cout << "파일 읽기 완료" << endl;
    } else {
        cout << "파일 열기 실패! output.txt가 존재하는지 확인하세요." << endl;
    }
    
    return 0;
}