# Project README

## Introduction
This program simply detects and outputs the compiler it was compiled with and the maximum C++ standard version that the compiler supports. It serves as a utility to provide quick information about the build environment.

## Building the Project
This project uses CMake for build management. The build artifacts are generated in the `bld/` directory, which is already part of the repository. To build the project, follow the steps for your operating system:

### Requirements
- **Toolchains:** A C++ compiler such as GCC (e.g., `g++-14`) or Clang.
- **CMake:** A build system generator supporting your platform.
- **Make:** For Linux and macOS, or MinGW Makefiles/Visual Studio for Windows.

### On macOS
1. **Navigate to the Build Directory:**
   ```bash
   cd bld
   ```

2. **Run CMake Configuration:**
   ```bash
   cmake -S ../rpo -B ./ -DCMAKE_CXX_COMPILER=g++-14
   ```

3. **Build the Project:**
   ```bash
   make
   ```

**Note for macOS Users:**
   - The default compiler on macOS is `clang`. If you want to use GCC installed via Homebrew, specify it explicitly when running CMake:
     ```bash
     cmake -S ../rpo -B ./ -DCMAKE_CXX_COMPILER=g++-14
     ```
   - Ensure your `PATH` is correctly set so the Homebrew GCC binaries are prioritized over system defaults.

### On Linux
1. **Navigate to the Build Directory:**
   ```bash
   cd bld
   ```

2. **Run CMake Configuration:**
   ```bash
   cmake -S ../rpo -B ./ -DCMAKE_CXX_COMPILER=g++-14
   ```

3. **Build the Project:**
   ```bash
   make
   ```

### On Windows
1. **Navigate to the Build Directory:**
   ```cmd
   cd bld
   ```

2. **Run CMake Configuration:**
   - For MinGW:
     ```cmd
     cmake -S ../rpo -B ./ -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=g++-14
     ```
   - For Visual Studio:
     ```cmd
     cmake -S ../rpo -B ./ -G "Visual Studio 16 2019"
     ```

3. **Build the Project:**
   - For MinGW:
     ```cmd
     mingw32-make
     ```
   - For Visual Studio:
     Open the generated `.sln` file in Visual Studio and build the solution.

### Cleaning the Project
If you want to clean up all build files and start over, use the following command in the root directory of the project:

```bash
git clean -fdx
```

**Warning:** This command will delete all untracked files and directories, so make sure you don’t have any important untracked files before running it.

---

Feel free to reach out if you encounter any issues or have further questions!


