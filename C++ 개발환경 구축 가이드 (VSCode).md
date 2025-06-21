# C++ 개발환경 구축 가이드 (VSCode)

## 개발 도구 선택

### Visual Studio Code (크로스 플랫폼 지원)
- 웹사이트: [code.visualstudio.com](https://code.visualstudio.com)

### Visual Studio (Windows)
- Microsoft Learn: [C/C++ 지원 설치 가이드](https://docs.microsoft.com/ko-kr/cpp/build/vscpp-step-0-installation)

## 필수 구성 요소
1. 컴파일러: MinGW-w64 (Windows), Clang (macOS)
2. 에디터: Visual Studio Code
3. 확장 프로그램: C/C++ Extension

---

## Windows 환경 설정

### 사전 준비사항
- Windows 사용자 계정을 영문으로 설정 (공백 없이)
- Anaconda 설치된 경우 임시 제거 권장

### 설치 과정

#### Step 1: MinGW-w64 설치
1. MSYS2 공식 사이트에서 설치 파일 다운로드
2. 기본 설치 경로 사용 권장
3. MSYS2 터미널에서 다음 명령어 실행:
   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```
4. 설치 확인:
   ```bash
   g++ --version
   ```

#### Step 2: 환경 변수 설정
1. Windows 검색: "환경 변수"
2. Path에 MinGW-w64 bin 폴더 경로 추가
   - 기본 경로: `C:\msys64\mingw64\bin`

#### Step 3: Visual Studio Code 설치
1. 공식 사이트에서 Windows 버전 다운로드
2. 설치 시 "코드로 열기" 옵션 모두 체크

#### Step 4: C++ 확장 설치
1. VS Code 실행
2. Extensions 탭에서 "C++" 검색
3. Microsoft C/C++ 확장 설치

### 프로젝트 설정

#### 기본 구성 설정
1. `Ctrl + Shift + P` → "C++: Edit Configurations (UI)"
2. 컴파일러 경로를 MinGW g++로 설정
3. IntelliSense 모드: gcc-x64
4. C++ 표준: C++17

#### 실행 환경 설정
1. `Ctrl + Shift + P` → "C++: Add Debug Configuration"
2. g++.exe 선택
3. 자동 생성된 설정 파일 확인

---

## macOS 환경 설정

### 필수 도구 설치

#### Xcode 명령줄 도구
1. App Store에서 Xcode 설치
2. 터미널에서 설치 확인:
   ```bash
   clang++ --version
   ```
3. 필요시 수동 설치:
   ```bash
   xcode-select --install
   ```

#### Visual Studio Code
1. 공식 사이트에서 "Mac Universal" 버전 다운로드
2. Applications 폴더로 이동

### 프로젝트 설정
1. 터미널에서 프로젝트 폴더 생성:
   ```bash
   mkdir cpp_course
   cd cpp_course
   code .
   ```
2. C++ 확장 설치 및 구성 설정
3. 컴파일러: Clang++ 자동 인식
4. 디버거: LLDB 사용

---

## Hello World 예제

### 기본 C++ 코드 구조
```cpp
#include <iostream>

int main() {
    std::cout << "Hello World" << std::endl;
    return 0;
}
```

### 주의사항
- **기호 정확성**: `#`, `<>`, `;`, `{}` 등 특수문자 정확히 입력
- **세미콜론**: 문장 끝에 반드시 추가
- **대소문자**: C++는 대소문자를 구분

### 실행 방법
1. **일반 실행**: Run → Run Without Debugging (`Ctrl+F5`)
2. **디버그 실행**: Run → Start Debugging (`F5`)
