cmake_minimum_required(VERSION 3.13) #min working version of cmake

#Project name
project(CMakeConf CXX)#CMakeConf can be the same as folder name but dont have to be

#set standard of c++ and c
set(CMAKE_CXX_STANDARD 14)#c++ version
set(CMAKE_C_STANDARD 99)#c version

#Sources
set(SOURCES
    main.cpp
    komendy.cpp
    inputProtection.cpp
    Magazyn.cpp
)

# Heading files
set(HEADERS
    komendy.hpp
    obiekt.hpp
    inputProtection.hpp
    Magazyn.hpp
)

#Make executable file
add_executable(MyExecutable ${SOURCES} ${HEADERS})#file made based of sources and headers
#executable file is name MyExecutable, to to run program type ./MyExecutable
