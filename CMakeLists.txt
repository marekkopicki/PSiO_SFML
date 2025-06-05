cmake_minimum_required(VERSION 3.16)

project(ProjectSFML LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB PROJECTSFML_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
#set(PROJECTSFML_SOURCES src/main.cpp)
add_executable(ProjectSFML ${PROJECTSFML_SOURCES})

set(SFML_DIR "C:/Qt/SFML")
target_link_libraries(ProjectSFML PRIVATE
	${SFML_DIR}/lib/libsfml-audio.a
	${SFML_DIR}/lib/libsfml-graphics.a
	${SFML_DIR}/lib/libsfml-network.a
	${SFML_DIR}/lib/libsfml-system.a
	${SFML_DIR}/lib/libsfml-window.a)
target_include_directories(ProjectSFML PRIVATE "${SFML_DIR}/include" "${CMAKE_SOURCE_DIR}/include")
include(GNUInstallDirs)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
install(TARGETS ProjectSFML
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
