# Using the `std::move` implementation in `C++`

## Testing **lvalue** and **rvalue** reference concept in `C++`

Author: **Robert Poenaru**
E-mail: <robert.poenaru@outlook.com>

Project which implemented the standard library `move`  into some example files. Project exclusivey written in `C++`.

See the [EXTRAS](/sources.md) for the documentation used in the development stages of the present project.

## Opened issues

 [ ] - The `#include <bits/stdc++.h> ` header is not available in macOS Catalina. So in the present state, `main.cc` file can't compile successfully.

## Compile the project with custom compilers

Instead of hardcoding the `CMakeLists.txt` configuration file with:

```cmake
set(CMAKE_C_COMPILER "path/to/c-compiler")
set(CMAKE_CXX_COMPILER "/path/to/cxx-compiler")
```

One should use the `CC` and `CXX` flags when building the project with CMake

> *The best method is to set the environment variables CC and CXX before calling CMake for the very first time in a build tree. After CMake detects what compilers to use, it saves them in the CMakeCache.txt file so that it can still generate proper build systems even if those variables disappear from the environment... If you ever need to change compilers, you need to start with a fresh build tree.* [^1]

[^1]:According to a SO post on choosing the right method for compiling.  https://stackoverflow.com/a/13089688/8295213

The command which has to be introduced in the terminal, when building with CMake is:

```bash
CC=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang CXX=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ cmake ..
```

More details on [gitlab](https://gitlab.kitware.com/cmake/community/-/wikis/FAQ#how-do-i-use-a-different-compiler)

The project's `CMakeLists.txt` file has also some custom variables which are set in the configuration, like the compiler paths.
The source for such variables is taken from this SO [post](https://stackoverflow.com/questions/31037882/whats-the-cmake-syntax-to-set-and-use-variables).