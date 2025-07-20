# Dynamissa
Fully fledged Newtonian mechanics simulator

## About Dynamissa
The goal is to create as complete as possible simulator of Newtonian mechanics with emphasis on use in an educational environment.
The plan is not to create a basic, gravity only simulator, but to create an emulator that supports whole suite of mechanics phenomena described by [Newton's 3 laws of motion](https://en.wikipedia.org/wiki/Newton%27s_laws_of_motion).

Dynamissa is written in C++ using [SDL2](https://www.libsdl.org/) and [Dear ImGui](https://github.com/ocornut/imgui) libraries.

## Build instructions
### Software installation
- C++ compiler
    - on Windows install Visual Studio 2022 with ```Desktop development with C++``` component
    - on other platforms install GCC or Clang (they are compatible) and C & C++ headers (`base-devel`, `build-essentials` or `build-base`)
- Git
- CMake
- SDL2
    - #### Windows
        1. Go to https://libsdl.org/release/.
        2. Download SDL2-devel-*latest_version*-VC.zip.
        3. Extract the downloaded folder.
        4. Create new `sdl2-config.cmake ` inside extracted folder:
        ```cmake
        set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

        # Support both 32 and 64 bit builds
        if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
        set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2main.lib")
        else ()
        set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2main.lib")
        endif ()

        string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
        ```
    - #### Other platforms
        1. Install SDL2 using package manager.

### Compilation
#### Windows
1. Create `build` folder.
2. Inside it, run `cmake -DCMAKE_PREFIX_PATH="path_to_extracted_folder" ..`
3. Open Visual Studio solution and build the whole solution.
4. Go inside `Debug` or `Release` folder, run the executable and voila!

#### Other platforms
1. Create `build` folder/directory.
2. Inside it run `cmake ..`
3. Run `make`, run the executable and voila!
