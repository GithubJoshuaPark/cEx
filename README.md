# C Language Examples (C-ex)

[![C Language Examples](https://img.shields.io/badge/C-Examples-blue)](https://github.com/GithubJoshuaPark/cEx.git)

이 저장소는 C 언어의 다양한 기능, 자료구조, 알고리즘, 그리고 시스템 프로그래밍을 학습하기 위한 종합 예제 모음집입니다.

> "저는 현장에서 Java, C#, JavaScript, Python 등 다양한 언어를 사용하고 있지만, 가장 기본이 되는 언어는 C언어라고 생각합니다. C언어는 시스템 프로그래밍, 임베디드 시스템, 운영체제 개발 등 다양한 분야에서 사용되며, 다른 언어의 기초가 되는 중요한 언어입니다."

---

## 📚 목차 (Contents)

1. [프로젝트 구조 (Project Structure)](#-프로젝트-구조-project-structure)
2. [시작하기 (Getting Started)](#-시작하기-getting-started)
3. [개발 환경 설정 (Development Environment)](#-개발-환경-설정-development-environment)
4. [예제 목록 (Example List)](#-예제-목록-example-list)
5. [프로젝트 상세 (Project Details)](#-프로젝트-상세-project-details)

---

## 📂 프로젝트 구조 (Project Structure)

```
cEx/
├── src/                # 소스 코드 (.c)
│   ├── main.c          # 메인 메뉴 프로그램
│   ├── hello.c
│   └── ...
├── include/            # 헤더 파일 (.h)
│   ├── hello.h
│   └── ...
├── bin/                # 컴파일된 실행 파일 및 객체 파일 (.o)
├── Makefile            # 메인 빌드 스크립트
├── Makefile.mk         # 빌드 설정 파일
├── generate_compile_commands.py # IntelliSense 설정 스크립트
└── README.md           # 프로젝트 문서
```

---

## 🚀 시작하기 (Getting Started)

### 1. 클론 (Clone)

```bash
git clone https://github.com/GithubJoshuaPark/cEx.git
cd cEx
```

### 2. 빌드 및 실행 (Build & Run)

터미널에서 `make` 명령어를 사용하여 전체 프로젝트를 빌드하고 실행할 수 있습니다.

```bash
# 전체 빌드 및 실행 파일 생성 (bin/main)
make

# 실행 파일을 현재 디렉토리로 복사 (선택 사항)
make copy_main

# 프로그램 실행
./main
```

실행하면 대화형 메뉴가 나타나며, 원하는 예제의 번호를 입력하여 실행할 수 있습니다.

---

## ⚙️ 개발 환경 설정 (Development Environment)

VS Code나 Antigravity 같은 최신 에디터에서 **자동 완성(IntelliSense)** 기능을 제대로 사용하려면 `compile_commands.json` 파일이 필요합니다.

### `generate_compile_commands.py`

이 스크립트는 프로젝트의 소스 파일들을 스캔하여 `compile_commands.json` 파일을 자동으로 생성해줍니다.

**왜 필요한가요?**

- 에디터가 헤더 파일 경로(`include/`)를 찾지 못해 발생하는 빨간 줄(에러 표시) 제거
- 코드 자동 완성 및 정의로 이동(Go to Definition) 기능 활성화

**사용 방법:**
새로운 `.c` 파일을 추가하거나 프로젝트를 처음 열었을 때 한 번 실행해주세요.

```bash
python3 generate_compile_commands.py
```

---

## 📝 예제 목록 (Example List)

이 프로젝트는 30개 이상의 다양한 예제를 포함하고 있습니다.

### 🔹 기초 (Basics)

- [Hello World](src/hello.c)
- [Data Types](src/data_typesEx.c)
- [Functions](src/functionsEx.c)
- [Pointers](src/pointersEx.c)
- [Arrays](src/arraysEx.c)
- [Structures](src/structuresEx.c)
- [Unions](src/unionsEx.c)
- [Enums](src/enumsEx.c)
- [Typedefs](src/typedefsEx.c)

### 🔹 메모리 관리 (Memory)

- [Memory Management](src/memory_managementEx.c)
- [Dynamic Memory Allocation](src/dynamic_memory_allocationEx.c)
- [Dynamic 2D Array Allocation](src/dynamic_2d_arrayEx.c)

### 🔹 자료구조 (Data Structures)

- [Stack](src/stack_data_structureEx.c)
- [Queue](src/queue_data_structureEx.c)
- [Linked List](src/linked_list_data_structureEx.c) (Single, Double, Circular)
- [Binary Trees](src/binary_tree_data_structureEx.c)
- [Hash Tables](src/hash_table_data_structureEx.c)
- [Graphs](src/graphs_data_structureEx.c)

### 🔹 알고리즘 (Algorithms)

- [Searching](src/searching_algorithmsEx.c)
- [Sorting](src/sorting_algorithmsEx.c)
- [Recursion](src/recursion_examplesEx.c)
- [Bit Manipulation](src/bit_manipulationEx.c)

### 🔹 시스템 & 고급 (System & Advanced)

- [File I/O](src/file_ioEx.c)
- [Preprocessor Directives](src/preprocessor_directivesEx.c)
- [Error Handling](src/error_handlingEx.c)
- [Multithreading](src/multithreadingEx.c)
- [Networking Basics](src/networking_basicsEx.c)
- [Socket Programming](src/socket_programmingEx.c)
- [Task Management System](src/taskManagementEx.c)

### 🎮 게임 프로젝트 (Games)

- [Snake Game](src/snake_gameEx.c)
- [Tetris Game](src/tetris_gameEx.c)
- [Breakout Game](src/breakout_gameEx.c)

---

## 💡 프로젝트 상세 (Project Details)

### 인터랙티브 메뉴 시스템

`src/main.c`는 함수 포인터 배열을 사용한 **데이터 기반(Data-Driven)** 구조로 설계되었습니다. 새로운 예제를 추가하려면 `menu_items` 배열에 한 줄만 추가하면 자동으로 메뉴에 반영됩니다.

### 빌드 시스템 (Makefile)

- **컴파일러**: `clang` (기본값)
- **플래그**: `-Wall` (경고 표시), `-g` (디버깅), `-pthread` (멀티스레딩), `-Iinclude` (헤더 경로)
- **자동화**: `src/` 폴더의 모든 `.c` 파일을 자동으로 감지하여 빌드합니다.

### 메모리 구조

![memory_segment](memory_segment.png)
