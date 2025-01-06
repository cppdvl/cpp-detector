#include <iostream>
#include <string>

// Function to determine the latest supported C++ standard based on compiler and version
std::string get_latest_cpp_standard() {
    std::string compiler;
    int major = 0, minor = 0, patch = 0;
    std::string latest_cpp = "Unknown";

    // Detect compiler and version
    #if defined(__clang__)
        compiler = "Clang";
        major = __clang_major__;
        minor = __clang_minor__;
        patch = __clang_patchlevel__;
    #elif defined(__GNUC__)
        compiler = "GCC";
        major = __GNUC__;
        minor = __GNUC_MINOR__;
        patch = __GNUC_PATCHLEVEL__;
    #elif defined(_MSC_VER)
        compiler = "MSVC";
        major = _MSC_VER;
        // MSVC versioning is different; _MSC_VER is an integer like 1920 for Visual Studio 2019 version 16.0
        // To extract major and minor, divide by 100 and get the remainder
        major = _MSC_VER / 100;
        minor = _MSC_VER % 100;
    #else
        compiler = "Unknown";
    #endif

    // Mapping compiler versions to supported C++ standards
    if (compiler == "GCC") {
        if (major >= 13) { // GCC 13 and above
            latest_cpp = "C++23";
        }
        else if (major == 12) {
            latest_cpp = "C++20";
        }
        else if (major == 11) {
            latest_cpp = "C++20";
        }
        else if (major == 10) {
            latest_cpp = "C++20";
        }
        else if (major == 9) {
            latest_cpp = "C++17";
        }
        else if (major == 8) {
            latest_cpp = "C++17";
        }
        else if (major >= 7) {
            latest_cpp = "C++14";
        }
        else {
            latest_cpp = "C++11 or older";
        }
    }
    else if (compiler == "Clang") {
        if (major >= 16) { // Clang 16 and above
            latest_cpp = "C++23";
        }
        else if (major >= 15) {
            latest_cpp = "C++23";
        }
        else if (major >= 14) {
            latest_cpp = "C++20";
        }
        else if (major >= 13) {
            latest_cpp = "C++20";
        }
        else if (major >= 12) {
            latest_cpp = "C++17";
        }
        else if (major >= 11) {
            latest_cpp = "C++17";
        }
        else if (major >= 10) {
            latest_cpp = "C++14";
        }
        else {
            latest_cpp = "C++11 or older";
        }
    }
    else if (compiler == "MSVC") {
        // MSVC version numbers correspond to Visual Studio releases
        // Example: Visual Studio 2019 is _MSC_VER 1920 to 1929
        // Visual Studio 2022 is _MSC_VER 1930 to 1939
        // Note: This mapping is approximate and should be updated with actual compiler release info
        if (major >= 193) { // Visual Studio 2022 and above
            latest_cpp = "C++23";
        }
        else if (major >= 192) { // Visual Studio 2019
            latest_cpp = "C++20";
        }
        else if (major >= 191) { // Visual Studio 2017
            latest_cpp = "C++17";
        }
        else if (major >= 190) { // Visual Studio 2015
            latest_cpp = "C++14";
        }
        else {
            latest_cpp = "C++11 or older";
        }
    }
    else {
        latest_cpp = "Cannot determine";
    }

    return latest_cpp;
}

int main() {
    // Detect compiler and version
    std::string compiler;
    std::string version;
    
    #if defined(__clang__)
        compiler = "Clang";
        version = std::to_string(__clang_major__) + "." + 
                  std::to_string(__clang_minor__) + "." + 
                  std::to_string(__clang_patchlevel__);
    #elif defined(__GNUC__)
        compiler = "GCC";
        version = std::to_string(__GNUC__) + "." + 
                  std::to_string(__GNUC_MINOR__) + "." + 
                  std::to_string(__GNUC_PATCHLEVEL__);
    #elif defined(_MSC_VER)
        compiler = "MSVC";
        // MSVC versioning is different; _MSC_VER is an integer like 1920 for Visual Studio 2019 version 16.0
        // To make it more readable, you might map it to Visual Studio versions
        int mscv = _MSC_VER;
        if (mscv >= 1930) {
            version = "19.30 (Visual Studio 2022)";
        }
        else if (mscv >= 1920) {
            version = "19.20 (Visual Studio 2019)";
        }
        else if (mscv >= 1910) {
            version = "19.10 (Visual Studio 2017)";
        }
        else if (mscv >= 1900) {
            version = "19.00 (Visual Studio 2015)";
        }
        else {
            version = "Older MSVC version";
        }
    #else
        compiler = "Unknown";
        version = "Unknown";
    #endif

    std::cout << "Compiler: " << compiler << " " << version << "\n";

    // Determine the latest supported C++ standard
    std::string latest_cpp = get_latest_cpp_standard();

    std::cout << "Latest Supported C++ Standard: " << latest_cpp << "\n";

    return 0;
}

