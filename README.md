# Exercising C language on windows os


1. Download IDE [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/) 
   and use Dev-C++ for c-language coding
or 
   <br>
2. Download [msys2-x86_64-20250622.exe](https://www.msys2.org/) and install it at C:\msys64
   and we can see command console window after installing it like the below;
   ---
   ![msys2.png](images/msys2.png)

   ---
   <br>
   가. Install MSYS2 and Mingw-w64
   ```bash
      ## install mingw-w64-ucrt-x86_64-toolchain (in msys2 terminal)  
      pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
   ```

   ![mingw-w64-ucrt.png](images/mingw-w64-ucrt.png)
   Enter selection default all (choose default Enter)
   Proceed with installation? [Y/n] Y
   ![mingw-w64-ucrt2.png](images/mingw-w64-ucrt2.png)
   ![msys2_installed_location.png](images/msys2_installed_location.png)

   ---
   <br>
   나. Add to System PATH
   copy the path of C:\msys64\ucrt64\bin
   ![msys2_installed_location_bin.png](images/msys2_installed_location_bin.png)

   add path variable
   ![msys2_installed_location_bin_add_path.png](images/msys2_installed_location_bin_add_path.png)

   ---
   <br>
   다. Verify Installation (check gcc installed in cmd terminal)
   ![check_gcc_installed_in_cmd_terminal.png](images/check_gcc_installed_in_cmd_terminal.png)

   ---
   <br>
   라. VS Code Setup
      > Install these extensions:
      >>
      > -  C/C++ by Microsoft
      > - C/C++ Extension Pack
      > - Code Runner (optional)
   <br>
   <br>
   install c/c++ extension in vsCode 
   ![c_extension.png](images/c_extension.png)
      

   ---
   <br>
   마. Create a Simple C Program (ex: main.c)

   ---
   <br>
   바. Manul Compilation Steps

   ```bash
   # Preprocessing
   gcc -E main.c -o main.i

   # Compiling to assembly
   gcc -S main.i -o main.s
   # or directly: gcc -S main.c -o main.s

   # Assembling to object file
   gcc -c main.s -o main.o
   # or directly: gcc -c main.c -o main.o

   # Linking to executable
   gcc main.o -o main.exe
   # or directly: gcc main.c -o main.exe

   # Run the executable
   ./main.exe
   ```

   ### vsCode에서 main.o 를 보고자 한다. 어떻게?
   > main.o는 오브젝트(바이너리) 파일이므로 텍스트 에디터로 바로 읽어볼 수 없다. 
   > <br> 그러나 VSCode에서 main.o의 내용을 바이너리(헥사 혹은 어셈블리 형태)로 확인하고 싶다면 다음과 같이 할 수 있다.
   > - vsCode Extension, "Hex Editor" 설치
   > - main.o 파일을 오른쪽 클릭 → "Open With..." → "Hex Editor"로 선택 (바이너리(16진수) 확인)
   > - or 

   ```bash
   # VSCode 터미널(Ctrl+`)에서 아래 명령어를 써서 main.o 파일의 어셈블리 코드를 확인할 수 있다.

   objdump -d main.o // 어셈블리 코드 확인 or 
   objdump -S main.o // 어셈블리 코드 확인 (소스포함)

   $ objdump -S main.o

      Can't get contents for section '.debug_str'.

      main.o:     file format pe-x86-64 // 파일 형식: pe-x86-64 (Windows 64-bit 실행 파일)
                                        // 오브젝트 파일(.o)이므로 링킹 전 상태. 이 때문에 주소가 0으로 표시된 부분 많음.

      Disassembly of section .text:

      0000000000000000 <printLine>:
      #include <stdio.h>

      void printLine(const char *line) {                       // printLine 함수 분석 
                                                               // 1. 함수 프롤로그: 스택 프레임 설정 
         0:   55                      push   %rbp              //  push   %rbp           : 이전 베이스 포인터 저장
         1:   48 89 e5                mov    %rsp,%rbp         //  mov    %rsp,%rbp      : 새로운 베이스 포인터 설정
         4:   48 83 ec 20             sub    $0x20,%rsp        //  sub    $0x20,%rsp     : 스택에 32바이트 공간 할당
                                                               // 2. 매개변수 전달
         8:   48 89 4d 10             mov    %rcx,0x10(%rbp)   //  mov    %rcx,0x10(%rbp): 매개변수를 스택에 저장
         printf("%s\n", line);                                 // 3. printf 호출:
         c:   48 8b 45 10             mov    0x10(%rbp),%rax   //  mov    0x10(%rbp),%rax: 매개변수 로드
      10:   48 89 c1                mov    %rax,%rcx           //  mov    %rax,%rcx      : printf의 첫 번째 인자로 설정 
      13:   e8 00 00 00 00          call   18 <printLine+0x18> //  call 18               : printf 함수 호출 (주소가 0인 것은 링킹이 안됐기 때문)
      }
      18:   90                      nop                        // 함수 에필로그: 스택 정리 및 복귀
      19:   48 83 c4 20             add    $0x20,%rsp          // add $0x20,%rsp: 할당한 스택 공간 해제
      1d:   5d                      pop    %rbp                // pop %rbp: 이전 베이스 포인터 복원
      1e:   c3                      ret                        // ret: 함수에서 반환

      000000000000001f <main>:                                 // main 함수 분석

      int main() {
      1f:   55                      push   %rbp                // 함수 프롤로그: printLine과 동일한 방식으로 스택 프레임 설정  
      20:   48 89 e5                mov    %rsp,%rbp
      23:   48 83 ec 20             sub    $0x20,%rsp
      27:   e8 00 00 00 00          call   2c <main+0xd>
         printLine("<< consoleEx002 project >>");
      2c:   48 8d 05 00 00 00 00    lea    0x0(%rip),%rax        # 33 <main+0x14> // 문자열 주소 계산: lea 0x0(%rip),%rax: RIP-relative addressing으로 문자열 주소 계산
                                                                                  // 주소가 0으로 표시된 것은 ※ 링킹이 완료되지 않아 상대 주소가 계산되지 않았기 때문
                                                                                  // 링킹 전 상태: 00 00 00 00으로 표시된 부분들은 링킹 과정에서 실제 주소로 채워짐.   
      33:   48 89 c1                mov    %rax,%rcx                              // printLine 호출: 문자열 주소를 RCX에 설정 (첫 번째 매개변수) 
      36:   e8 c5 ff ff ff          call   0 <printLine>                          // call 0 <printLine>: printLine 함수 호출
         printLine("Hello, Joshua! Welcome to C programming");
      3b:   48 8d 05 20 00 00 00    lea    0x20(%rip),%rax        # 62 <main+0x43>
      42:   48 89 c1                mov    %rax,%rcx                              // 반환 값 설정:mov $0x0,%eax:返回值 0을 EAX에 설정 (C에서의 return 0)
      45:   e8 b6 ff ff ff          call   0 <printLine>                          // 스택 정리 및 함수 종료
         return 0;
      4a:   b8 00 00 00 00          mov    $0x0,%eax                              // 중복된 코드: 출력 결과 하단에 반복되는 코드는 objdump의 디스어셈블리 오류로 보입니다.
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      55:   90                      nop
      56:   90                      nop
      57:   90                      nop
      58:   90                      nop
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      55:   90                      nop
      56:   90                      nop
      57:   90                      nop
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      55:   90                      nop
      56:   90                      nop
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      55:   90                      nop
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      4f:   48 83 c4 20             add    $0x20,%rsp
      4f:   48 83 c4 20             add    $0x20,%rsp
      4f:   48 83 c4 20             add    $0x20,%rsp
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      55:   90                      nop
      56:   90                      nop
      57:   90                      nop
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      55:   90                      nop
      56:   90                      nop
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      4f:   48 83 c4 20             add    $0x20,%rsp
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      4f:   48 83 c4 20             add    $0x20,%rsp
      4f:   48 83 c4 20             add    $0x20,%rsp
      53:   5d                      pop    %rbp
      54:   c3                      ret
      55:   90                      nop
      56:   90                      nop
      57:   90                      nop
      58:   90                      nop
      59:   90                      nop
      5a:   90                      nop
      5b:   90                      nop
      5c:   90                      nop
      5d:   90                      nop
      5e:   90                      nop
      5f:   90                      nop

   ```

