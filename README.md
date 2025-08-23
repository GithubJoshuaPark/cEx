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

   ### vsCode Extension, "Hex Editor" 설치
   > main.o 파일을 오른쪽 클릭 → "Open With..." → "Hex Editor"로 선택