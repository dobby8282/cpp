/* 
파일명: file_binary_mode.cpp

바이너리 파일 처리 (Binary File Handling)
    텍스트가 아닌 바이너리 데이터를 파일에 저장하고 읽는 방법
    
    - ios::binary: 바이너리 모드로 파일 열기
    - write(): 바이너리 데이터 쓰기
    - read(): 바이너리 데이터 읽기
    - sizeof(): 데이터 크기 계산
    - reinterpret_cast: 포인터 타입 변환
    
    장점:
    - 빠른 속도: 텍스트 변환 과정 없음
    - 정확한 데이터: 부동소수점 등의 정밀도 유지
    - 메모리 효율: 컴팩트한 저장
    
    용도:
    - 구조체/클래스 직렬화
    - 이미지, 음성 파일 등
    - 게임 세이브 파일
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Player {
    char name[20];
    int level;
    float health;
    int score;
};

int main() {
    // 바이너리 쓰기
    Player player = {"홍길동", 25, 85.5f, 12000};
    
    ofstream outFile("player.dat", ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char*>(&player), sizeof(Player));
        outFile.close();
        cout << "플레이어 데이터 저장 완료" << endl;
    }
    
    // 바이너리 읽기
    Player loadedPlayer;
    ifstream inFile("player.dat", ios::binary);
    
    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&loadedPlayer), sizeof(Player));
        inFile.close();
        
        cout << "\n=== 불러온 플레이어 정보 ===" << endl;
        cout << "이름: " << loadedPlayer.name << endl;
        cout << "레벨: " << loadedPlayer.level << endl;
        cout << "체력: " << loadedPlayer.health << endl;
        cout << "점수: " << loadedPlayer.score << endl;
    }
    
    return 0;
}