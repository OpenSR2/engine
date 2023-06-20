# Building
First, install SFML 2.5.1

If you're installing with downloading, set the `SFML_DIR` environment variable

Alternatively, you can add `-DSFML_DIR=/home/username/SFML` flag to build command.

`cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -S . -B build`