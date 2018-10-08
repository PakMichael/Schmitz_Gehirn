cmake_minimum_required (VERSION 2.6)
project (Schmitz_Gehirn)

add_executable(${PROJECT_NAME} main.cpp
	Src/engine.cpp
	Src/entity.cpp
	Src/file.cpp
	Src/observable.cpp
	Src/primitive.cpp
	Src/shader.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/Headers
)


target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Libraries/glew32.lib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Libraries/glew32s.lib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Libraries/glfw3.lib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Libraries/glfw3dll.lib)
target_link_libraries(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/Libraries/opengl32.lib)


add_custom_command(TARGET Schmitz_Gehirn POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/Shaders $<TARGET_FILE_DIR:Schmitz_Gehirn>/Shaders)
					   
add_custom_command(TARGET Schmitz_Gehirn POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/DLibs $<TARGET_FILE_DIR:Schmitz_Gehirn>)					 
					   