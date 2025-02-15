if(MSVC)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /wd\"4996\"")
	SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /wd\"4996\"")
endif()

add_subdirectory(test)
add_subdirectory(third_party/btyacc_tp)

add_definitions(-DBOOST_AUTO_LINK_NOMANGLE)

add_subdirectory(../../common/third_party/boost_tp/cmake  ${CMAKE_BINARY_DIR}/boost)

include_directories(../../common/third_party)

#############################################
## CppParser

find_program(
	FLEX
	"flex"
	# Assuming for Linux and OSX flex is already available
	# Only for Windows the flex will be used from the repository
	PATHS ENV PATH "third_party/flex_tp"
)
if(${FLEX} MATCHES "FLEX-NOTFOUND")
	message(FATAL_ERROR "'flex' not found")
else()
	message(STATUS "Found 'flex' as ${FLEX}")
endif()

set_source_files_properties(src/parser.tab.cpp GENERATED)
set_source_files_properties(src/parser.lex.cpp GENERATED)
set_source_files_properties(src/parser.tab.h GENERATED)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.h
	COMMAND $<TARGET_FILE:btyacc> -v -b parser -d ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.y
#	COMMAND ${CMAKE_COMMAND} -E copy y_tab.c ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.cpp
#	COMMAND ${CMAKE_COMMAND} -E copy y_tab.h ${CMAKE_CURRENT_SOURCE_DIR}/parser.tab.h
	COMMAND ${CMAKE_COMMAND} -E copy parser.tab.c ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.cpp
	COMMAND ${CMAKE_COMMAND} -E copy parser.tab.h ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.h
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.y
)

add_custom_command(
	OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.lex.cpp
	COMMAND ${FLEX} -o${CMAKE_CURRENT_SOURCE_DIR}/src/parser.lex.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.l
	DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.l ${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.h
)

add_library(cppparser_lex_and_yacc OBJECT
	src/parser.l
	src/parser.y
	${CMAKE_CURRENT_SOURCE_DIR}/src/parser.lex.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/parser.tab.cpp
)
target_link_libraries(cppparser_lex_and_yacc
	PUBLIC
		cppast
)
target_include_directories(cppparser_lex_and_yacc
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
	PRIVATE
		../../common/third_party/boost_tp
		src/win_hack
)
target_compile_definitions(cppparser_lex_and_yacc
	PRIVATE
		YY_NO_UNPUT
)

set(CPPPARSER_SOURCES
	src/cpp_program.cpp
	src/cppparser.cpp
	src/lexer-helper.cpp
	src/utils.cpp
)

add_library(cppparser STATIC ${CPPPARSER_SOURCES})
add_dependencies(cppparser btyacc)
target_link_libraries(cppparser
	PUBLIC
		cppast
		cppparser_lex_and_yacc
)

target_include_directories(cppparser
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

set_target_properties(cppparser PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_COMMAND}")

install(DIRECTORY "include/cppparser" DESTINATION "include" COMPONENT Development)
