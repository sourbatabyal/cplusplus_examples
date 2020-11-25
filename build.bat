@ECHO ON

PUSHD build

cmake .. -G"Visual Studio 15 2017 Win64"
cmake --build . --config Release

POPD build