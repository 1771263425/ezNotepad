# -*- CMakeLists.txt generated by CodeLite IDE. Do not edit by hand -*-

cmake_minimum_required(VERSION 2.8.11)

project(ezNotepad)



#{{{{ User Code 1
# Place your code here
#}}}}

include_directories(
    .
)


# Library path
set(CMAKE_LDFLAGS "${CMAKE_LDFLAGS} -L. ")

# Define the CXX sources
set ( CXX_SRCS
    ${CMAKE_SOURCE_DIR}/main.cpp
    ${CMAKE_SOURCE_DIR}/MainFrame.cpp
)
set(CMAKE_EXE_LINKER_FLAGS -mwindows)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(ezNotepad ${RC_SRCS} ${CXX_SRCS} ${C_SRCS})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})



#{{{{ User Code 3
# Place your code here
#}}}}

