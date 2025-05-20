file(
	GLOB_RECURSE
	EDITOR_SOURCE_FILES
	"src/*.cpp"
	"src/*.h"
)

add_executable(editor)

target_sources(editor PRIVATE ${EDITOR_SOURCE_FILES})

set_property(TARGET editor PROPERTY CXX_STANDARD 20)
set_property(TARGET editor PROPERTY CXX_EXTENSIONS ON)
set_property(TARGET editor PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET editor PROPERTY CXX_SCAN_FOR_MODULES ON)


target_link_libraries(editor PRIVATE core)