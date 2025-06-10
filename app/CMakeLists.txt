file(
	GLOB_RECURSE
	APP_SOURCE_FILES
	"src/*.cpp"
	"src/*.h"
)

add_executable(app)

target_sources(app PRIVATE ${APP_SOURCE_FILES})

set_property(TARGET app PROPERTY CXX_STANDARD 20)
set_property(TARGET app PROPERTY CXX_EXTENSIONS ON)
set_property(TARGET app PROPERTY CXX_STANDARD_REQUIRED ON)
set_property(TARGET app PROPERTY CXX_SCAN_FOR_MODULES ON)


target_link_libraries(app PRIVATE core)