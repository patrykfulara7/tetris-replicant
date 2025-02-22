# Tetris Replicant

A simple replica of Tetris written in C++ with OpenGL.

<p align="center">
	<img width="320" height="640" src="https://imgur.com/tpitYAX.png">
</p>

## Installation

First, download the repository along with its submodules:
```
git clone --recursive -j8 https://github.com/patrykfulara7/tetris-replicant.git
```

Then, build and compile it with CMake:
```
cd tetris-replicant
cmake -S . -B build
cmake --build build
```

Finally, run the executable:
```
# On Linux
./build/Tetris/tetris

# On Windows
.\build\Tetris\tetris.exe
```

## Controls

| Action         | Key   |
|----------------|-------|
| Move Left      | H     |
| Move Down      | J     |
| Move Right     | L     |
| Rotate Left    | Q     |
| Rotate Right   | E     |
| Close Game     | C     |
| Restart Game   | R     |
