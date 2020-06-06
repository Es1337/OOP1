cmake_minimum_required (VERSION 2.6)

project (main)

include(CTest)

add_executable(main stest.cpp)
add_test(main_test main)

set(LIBSRC SmartPointer.h SmartPointer.cpp)
set(LIBSRC2 TestClassA.h TestClassA.cpp)
add_library(libs ${LIBSRC} ${LIBSRC2})

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