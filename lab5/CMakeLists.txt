cmake_minimum_required (VERSION 2.6)

project (main)

include(CTest)

add_executable(main ftest.cpp)
add_test(main_test main)

set(LIBSRC Fun.h)
set(LIBSRC2 FElementarne.h FElementarne.cpp)
set(LIBSRC3 FZlozona.h FZlozona.cpp)
set(LIBSRC4 Rozniczka.h Rozniczka.cpp)
set(LIBSRC5 Trygonometryczne.h Trygonometryczne.cpp)
add_library(libs ${LIBSRC} ${LIBSRC2} ${LIBSRC3} ${LIBSRC4} ${LIBSRC5})

target_link_libraries(main libs)

set_target_properties(main PROPERTIES COMPILE_FLAGS "-g -Wall --pedantic")

add_custom_target(run
    COMMAND ./main 
    DEPENDS main
)

add_custom_target(check
    COMMAND ${CMAKE_CTEST_COMMAND}
	--force-new-ctest-process --test-action memcheck
    DEPENDS main
)