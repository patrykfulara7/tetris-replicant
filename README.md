# Tetris Replicant

Simple replica of Tetris written in C++ with OpenGL.

<p align="center">
	<img width="320" height="640" src="https://imgur.com/tpitYAX.png">
</p>

## Installation

First download the repository along with the submodules
```
git clone --resursive -j8 https://github.com/patrykfulara7/Tetris.git
```

Then build and compile with [CMake](https://github.com/Kitware/CMake)
```
cd Tetris
cmake -G "Unix Makefiles" -S . -B build
cmake --build build
```

And run
```
# On Linux
./build/Tetris/tetris

# On Windows
.\build\Tetris\tetris.exe
```

## Controls
| Left | Down | Right | Rotate Left | Rotate Right | Close | Restart |
| ---- | ---- | ----- | ----------- | ------------ | ----- | ------- |
| H    | J    | L     | Q           | E            | C     | R       |
