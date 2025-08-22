# Exercising C language on windows os
---

1. Download IDE [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/) 
   and use Dev-C++ for c-language coding
or 
   ---
1. Download [msys2-x86_64-20250622.exe](https://www.msys2.org/) and install it at C:\msys64
   and we can see command console window after installing it like the below;
   ---
   ![msys2.png](msys2.png)

   ```bash
      ## install mingw-w64-ucrt-x86_64-toolchain (in msys2 terminal)  
      pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain
   ```

   ![mingw-w64-ucrt.png](images/mingw-w64-ucrt.png)
   Enter selection default all (choose default Enter)
   Proceed with installation? [Y/n] Y
   ![mingw-w64-ucrt2.png](images/mingw-w64-ucrt2.png)
   ![msys2_installed_location.png](images/msys2_installed_location.png)

   copy the path of C:\msys64\ucrt64\bin
   ![msys2_installed_location_bin.png](images/msys2_installed_location_bin.png)

   add path variable
   ![msys2_installed_location_bin_add_path.png](images/msys2_installed_location_bin_add_path.png)

   check gcc installed in cmd terminal
   ![check_gcc_installed_in_cmd_terminal.png](images/check_gcc_installed_in_cmd_terminal.png)

   install c/c++ extension in vsCode 
   ![c_extension.png](images/c_extension.png)
