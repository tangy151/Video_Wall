cmake_minimum_required(VERSION 3.18)#cmake最低版本
#project(Clion_VS_QT)
project(TV_Wall)


set(CMAKE_CXX_STANDARD 11)#C++标准
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 设置cmake模块的查询目录，注意这里的路径，到mingw路径即可
set(CMAKE_PREFIX_PATH   "C:/Qt/5.15.2/msvc2019_64")
set(QT_DIR              "C:/Qt/5.15.2/msvc2019_64")



message("CMAKE_GENERATOR_PLATFORM = ${CMAKE_GENERATOR_PLATFORM}")
message("CMAKE_VS_PLATFORM_NAME = ${CMAKE_VS_PLATFORM_NAME}")




file(GLOB HEAD_MAIN1        ${CMAKE_CURRENT_LIST_DIR}/*.h)
file(GLOB HEAD_MAIN2        ${CMAKE_CURRENT_LIST_DIR}/BottomArea/*.h)
file(GLOB HEAD_MAIN3        ${CMAKE_CURRENT_LIST_DIR}/ComputerInfo/*.h)
file(GLOB HEAD_MAIN4        ${CMAKE_CURRENT_LIST_DIR}/Controls/*.h)
file(GLOB HEAD_MAIN5        ${CMAKE_CURRENT_LIST_DIR}/Controls/Ribbon/*.h)
file(GLOB HEAD_MAIN6        ${CMAKE_CURRENT_LIST_DIR}/EditorWindow/*.h)
file(GLOB HEAD_MAIN7        ${CMAKE_CURRENT_LIST_DIR}/GraphicsView/*.h)
file(GLOB HEAD_MAIN8        ${CMAKE_CURRENT_LIST_DIR}/Public/*.h)
file(GLOB HEAD_MAIN9        ${CMAKE_CURRENT_LIST_DIR}/SplitterArea/*.h)
file(GLOB HEAD_MAIN10       ${CMAKE_CURRENT_LIST_DIR}/VideoChannel/*.h)


file(GLOB SOURCE1       ${CMAKE_CURRENT_LIST_DIR}/*.cpp)
file(GLOB SOURCE2       ${CMAKE_CURRENT_LIST_DIR}/BottomArea/*.cpp)
file(GLOB SOURCE3       ${CMAKE_CURRENT_LIST_DIR}/ComputerInfo/*.cpp)
file(GLOB SOURCE4       ${CMAKE_CURRENT_LIST_DIR}/Controls/*.cpp)
file(GLOB SOURCE5       ${CMAKE_CURRENT_LIST_DIR}/Controls/Ribbon/*.cpp)
file(GLOB SOURCE6       ${CMAKE_CURRENT_LIST_DIR}/EditorWindow/*.cpp)
file(GLOB SOURCE7       ${CMAKE_CURRENT_LIST_DIR}/GraphicsView/*.cpp)
file(GLOB SOURCE8       ${CMAKE_CURRENT_LIST_DIR}/Public/*.cpp)
file(GLOB SOURCE9       ${CMAKE_CURRENT_LIST_DIR}/SplitterArea/*.cpp)
file(GLOB SOURCE10      ${CMAKE_CURRENT_LIST_DIR}/VideoChannel/*.cpp)





#头文件设置
include_directories(
        ${PROJECT_SOURCE_DIR}/../include
        ${PROJECT_SOURCE_DIR}/.)


# 查找QT的模块
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


link_directories(../libs)
# 添加源文件
add_executable(${PROJECT_NAME}
        ${HEAD_MAIN1}
        ${HEAD_MAIN2}
        ${HEAD_MAIN3}
        ${HEAD_MAIN4}
        ${HEAD_MAIN5}
        ${HEAD_MAIN6}
        ${HEAD_MAIN7}
        ${HEAD_MAIN8}
        ${HEAD_MAIN9}
        ${HEAD_MAIN10}

        ${SOURCE1}
        ${SOURCE2}
        ${SOURCE3}
        ${SOURCE4}
        ${SOURCE5}
        ${SOURCE6}
        ${SOURCE7}
        ${SOURCE8}
        ${SOURCE9}
        ${SOURCE10}


        video_wall.qrc
        )



set(Qt5_DIR     ${QT_DIR}/lib/cmake/Qt5)



# 获取执行程序依赖的QT库文件
set(windeployqt     "${QT_DIR}/bin/windeployqt")

#添加模块
target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)

#message("CMAKE_PREFIX_PATH          = ${CMAKE_PREFIX_PATH}")
message("CMAKE_SOURCE_DIR           = ${CMAKE_SOURCE_DIR}")
#message("CMAKE_INSTALL_PREFIX       = ${CMAKE_INSTALL_PREFIX}")
#message("CMAKE_CURRENT_LIST_DIR     = ${CMAKE_CURRENT_LIST_DIR}")


set(INSTALL_PATH  ${CMAKE_SOURCE_DIR}/install/${CMAKE_VS_PLATFORM_NAME})


#设置Debug和Release输出路径一致（windows）CMAKE_SOURCE_DIR
set(RUMTIME ${CMAKE_SOURCE_DIR}/bin)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${RUMTIME}
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${RUMTIME}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${RUMTIME}
        )


# 执行windeployqt 复制依赖的qt库到输出文件目录下
install(CODE "
execute_process(COMMAND
${windeployqt} $<TARGET_FILE:${PROJECT_NAME}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})")


# 复制输出的执行程序和依赖的qt库到安装路径
install(DIRECTORY
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
        DESTINATION
        ${INSTALL_PATH})








if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
