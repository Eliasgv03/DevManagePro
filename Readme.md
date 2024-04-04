# DevManagePro Project Setup
This project requires the following tools to be installed on your system:
 
- CMake (version 3.27 or greater)
- A compiler (such as MSVC or MinGW)
- The C++ extension for VSCode

### Building the project
1. Open the project directory in VSCode
2. Open a terminal in VSCode using the `View > Terminal` menu or by using the `ctrl` + `backtick` shortcut
3. Run the `cmake -Bbuild` command in the terminal to configure the project. This will create a `build` directory in the project root
4. Run the `cmake --build build` command in the terminal to build the project. This will create an executable file in the `build` directory

### Running the project
1. Run the `./build/<executable-name>` command in the terminal to run the project. Replace `<executable-name>` with the name of the executable file created in the `build` directory

Note: The first time you build the project, you may encounter the error "CMAKE_C_COMPILER not set". This can be resolved by setting the `CMAKE_C_COMPILER` and `CMAKE_CXX_COMPILER` environment variables to the path of the C and C++ compilers installed on your system.