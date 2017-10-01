cmake_minimum_required(VERSION 3.8)
project(pricealab2)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES cscd340Lab2.c ./linkedlist/linkedList.c ./words/word.c ./linkedlist/listUtils.c
        ./utils/fileUtil.c ./utils/myUtils.c movies/movie.c)
add_executable(pricealab2 ${SOURCE_FILES})
