
cmake_minimum_required(VERSION 3.14)
project(The_Sort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp window_manager.cpp window_manager.h event_manager.cpp event_manager.h column_manager.cpp column_manager.h sort_manager.cpp sort_manager.h sorts/bubblesort.cpp sorts/bubblesort.h sorts/insertionsort.cpp sorts/insertionsort.h sorts/selectionsort.cpp sorts/selectionsort.h sorts/radixsort.cpp sorts/radixsort.h sorts/mergesort.cpp sorts/mergesort.h sorts/quicksort.cpp sorts/quicksort.h)
add_executable(The_Sort ${SOURCE_FILES} window_manager.cpp window_manager.h event_manager.cpp event_manager.h column_manager.cpp column_manager.h sort_manager.cpp sort_manager.h sorts/bubblesort.cpp sorts/bubblesort.h sorts/insertionsort.cpp sorts/insertionsort.h sorts/selectionsort.cpp sorts/selectionsort.h sorts/radixsort.cpp sorts/radixsort.h sorts/mergesort.cpp sorts/mergesort.h sorts/quicksort.cpp sorts/quicksort.h)
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(The_Sort sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
