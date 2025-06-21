/* 
파일명: file_write_basic.cpp

파일 쓰기 (File Writing)
    ofstream을 사용하여 텍스트 파일에 데이터를 기록하는 기본 방법
    
    - ofstream: Output File Stream, 파일에 데이터를 쓰기 위한 클래스
    - ios::out: 쓰기 모드 (기본값이므로 생략 가능)
    - ios::trunc: 파일이 존재하면 내용을 지우고 새로 작성 (기본값)
    - open(): 파일을 열기
    - close(): 파일을 닫기 (소멸자에서 자동 호출됨)
    - is_open(): 파일이 제대로 열렸는지 확인
    
    주의사항:
    - 파일이 존재하지 않으면 새로 생성
    - 기존 파일이 있으면 내용이 덮어써짐
    - 파일 열기 실패 시 예외 처리 필요
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("output.txt");
    
    if (outFile.is_open()) {
        outFile << "안녕하세요!" << endl;
        outFile << "파일 쓰기 테스트입니다." << endl;
        outFile << "숫자: " << 123 << endl;
        
        cout << "파일 쓰기 완료: output.txt" << endl;
        outFile.close();
    } else {
        cout << "파일 열기 실패!" << endl;
    }
    
    return 0;
}