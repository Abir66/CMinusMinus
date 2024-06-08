#!/bin/bash

mkdir -p bin
bin_folder="bin"

yacc  -d -y 1905066.y -o y.tab.cpp
echo 'Generated the parser C file as well the header file'


emcc -w -c -o $bin_folder/y.o y.tab.cpp
echo 'Generated the parser object file'

flex -o lex.yy.cpp 1905066.l 
echo 'Generated the scanner C file'

emcc -w -c -o $bin_folder/l.o lex.yy.cpp
echo 'Generated the scanner object file'


emcc $bin_folder/y.o $bin_folder/l.o -fsanitize=none  -o ../src/lib/compiler/1905066_parser.js\
    -s NO_EXIT_RUNTIME=1 \
    -s EXPORTED_FUNCTIONS='["_main"]' \
    -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap", "FS"]' \
    -s INVOKE_RUN=0 \
    -sMODULARIZE \
    -sEXPORT_ES6 \
    -s INITIAL_MEMORY=64mb\
    -sENVIRONMENT=web \



echo 'All ready, running'
