project(Projet_Manguille)
set(EXECUTABLE_OUTPUT_PATH bin/)
cmake_minimum_required(VERSION 2.8)


find_package(PkgConfig REQUIRED)
pkg_check_modules(SFML2 REQUIRED sfml-graphics>=2.1 sfml-audio>=2.1)


file(
GLOB_RECURSE

src_files

src/*
include/*
)

add_definitions( -std=c++11 )
include_directories(
include/
)

add_executable(

  manguille

  ${src_files} 

)


target_link_libraries(
manguille
sfml-audio
sfml-graphics
sfml-window
sfml-system
)