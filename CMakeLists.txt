cmake_minimum_required(VERSION 3.2)

project(Labyrinth)

set(SOURCES
      clean.cpp
      game.cpp
      init.cpp
      map.cpp
      menu.cpp
      move.cpp
      multiplatform.cpp
      records.cpp
      start.cpp
)

add_executable(Labyrinth ${SOURCES})
