############################################################################
# Copyright 2007-2025 Universidade do Porto - Faculdade de Engenharia      #
# Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  #
############################################################################
# This file is part of DUNE: Unified Navigation Environment.               #
#                                                                          #
# Commercial Licence Usage                                                 #
# Licencees holding valid commercial DUNE licences may use this file in    #
# accordance with the commercial licence agreement provided with the       #
# Software or, alternatively, in accordance with the terms contained in a  #
# written agreement between you and Faculdade de Engenharia da             #
# Universidade do Porto. For licensing terms, conditions, and further      #
# information contact lsts@fe.up.pt.                                       #
#                                                                          #
# Modified European Union Public Licence - EUPL v.1.1 Usage                #
# Alternatively, this file may be used under the terms of the Modified     #
# EUPL, Version 1.1 only (the "Licence"), appearing in the file LICENCE.md #
# included in the packaging of this file. You may not use this work        #
# except in compliance with the Licence. Unless required by applicable     #
# law or agreed to in writing, software distributed under the Licence is   #
# distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     #
# ANY KIND, either express or implied. See the Licence for the specific    #
# language governing permissions and limitations at                        #
# https://github.com/LSTS/dune/blob/master/LICENCE.md and                  #
# http://ec.europa.eu/idabc/eupl.html.                                     #
############################################################################
# Author: Ricardo Martins                                                  #
############################################################################

# Validate CMake version.
cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0075 NEW)
  if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.28")
    cmake_policy(SET CMP0153 OLD)
    cmake_policy(SET CMP0145 OLD)
  endif()
endif(COMMAND CMAKE_POLICY)

# Required C++ Standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Toolchain.cmake)

##########################################################################
#                         Project information                            #
##########################################################################
project("DUNE")
set(PROJECT_NAME "DUNE: Unified Navigation Environment")
set(PROJECT_SHORT_NAME "DUNE")
set(PROJECT_VENDOR "Universidade do Porto - LSTS")
set(PROJECT_COPYRIGHT "Copyright (C) 2007-2025 - ${PROJECT_VENDOR}")
set(PROJECT_CONTACT "DUNE <dune@lsts.pt>")
set(PROJECT_VERSION_YEAR  "2024")
set(PROJECT_VERSION_MONTH "09")
set(PROJECT_VERSION_PATCH "0")
set(PROJECT_VERSION_RCN   "0")

# Version formats.
set(PROJECT_VERSION
  "${PROJECT_VERSION_YEAR}.${PROJECT_VERSION_MONTH}.${PROJECT_VERSION_PATCH}")

if(PROJECT_VERSION_RCN GREATER 0)
  set(PROJECT_VERSION "${PROJECT_VERSION}-rc${PROJECT_VERSION_RCN}")
endif(PROJECT_VERSION_RCN GREATER 0)

if(PROJECT_VERSION_PATCH STREQUAL "x")
  set(PROJECT_VERSION_PARTS
    "${PROJECT_VERSION_YEAR},${PROJECT_VERSION_MONTH},99,${PROJECT_VERSION_RCN}")
else()
  set(PROJECT_VERSION_PARTS
    "${PROJECT_VERSION_YEAR},${PROJECT_VERSION_MONTH},${PROJECT_VERSION_PATCH},${PROJECT_VERSION_RCN}")
endif()

# This directory will hold generated files.
set(DUNE_GENERATED ${CMAKE_BINARY_DIR}/DUNEGeneratedFiles)

include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

# Define options.
message(STATUS "")
message(STATUS "******************************************")
message(STATUS "***          Optional Features         ***")
message(STATUS "******************************************")
dune_option(PICCOLO "Include Piccolo library")
dune_option(SHARED "Build shared library and shared plugins")
dune_option(DEBUG "Compile with debug information enabled")
dune_option(PROFILE "Compile with profiling and debug information enabled")
dune_option(TLSF "Include the TLSF O(1) memory allocator")
dune_option(QT5 "Include Qt5 based GUI")
dune_option(DC1394 "Enable support for libdc1394")
dune_option(V4L2 "Enable support for libv4l2")
dune_option(JS "Enable support for SpiderMonkey javascript engine")
dune_option(XENETH "Enable support for the Xeneth SDK")
dune_option(BLUEVIEW "Enable support for the BlueView SDK")
dune_option(OPENCV "Enable support for OpenCV")
dune_option(POINTGREY "Enable support for POINTGREY")
dune_option(EXIV2 "Enable support for Exiv2")
dune_option(NO_RTTI "Disable support for RTTI")
dune_option(UEYE "Enable support for IDS uEye cameras")
dune_option(H5CPP "Enable support for hdf5 format i/o using the h5cpp library")
dune_option(ELLIPSOIDAL "Enable ellipsoidal coordinates in (WGS84) displace")
dune_option(DUNELEGACY "Disable compilation of C++17 features")

# Internationalization.
include(${PROJECT_SOURCE_DIR}/cmake/I18N.cmake)

#############################################################################
# DUNE Legacy build
#############################################################################
if(DUNELEGACY)
  set(CMAKE_CXX_STANDARD 14)
  add_definitions(-DDUNE_LEGACY)
endif(DUNELEGACY)

#############################################################################
# DUNE's default build type
#############################################################################
if(DEBUG)
  set(CMAKE_BUILD_TYPE "Debug")
  add_definitions(-DDEBUG)
else(DEBUG)
  set(CMAKE_BUILD_TYPE "Release")
endif(DEBUG)

if(PROFILE)
  set(CMAKE_BUILD_TYPE "Debug")
endif(PROFILE)

# Set a build name with more details than the default.
set(BUILDNAME "${DUNE_SYSTEM_NAME_VAR}")

include(cmake/IMC.cmake)

##########################################################################
# Piccolo                                                                #
##########################################################################
set(PICCOLO_MESSAGES_XML ${PROJECT_SOURCE_DIR}/private/etc/xml/Piccolo.xml)

if(DUNE_PROGRAM_PYTHON)
  add_custom_target(piccolo_messages
    COMMAND ${DUNE_PROGRAM_PYTHON}
    ${PROJECT_SOURCE_DIR}/private/programs/generators/piccolo_messages.py
    ${PICCOLO_MESSAGES_XML} ${PROJECT_SOURCE_DIR}/private/src/Piccolo
    DEPENDS ${xml})
endif(DUNE_PROGRAM_PYTHON)

##########################################################################
# Status Codes                                                           #
##########################################################################
if(DUNE_PROGRAM_PYTHON)
  add_custom_target(status
    COMMAND ${DUNE_PROGRAM_PYTHON}
    ${PROJECT_SOURCE_DIR}/programs/generators/status_codes.py
    ${PROJECT_SOURCE_DIR}/src/DUNE/Status/Codes.def
    ${PROJECT_SOURCE_DIR}/src/DUNE/Status
    DEPENDS ${PROJECT_SOURCE_DIR}/src/DUNE/Status/Codes.def)
endif(DUNE_PROGRAM_PYTHON)

##########################################################################
#                         DUNE's Core Library                            #
##########################################################################
if(SHARED)
  set(DUNE_SHARED 1)
else(SHARED)
  set(DUNE_STATIC 1)
endif(SHARED)

if(TLSF)
  set(DUNE_USING_TLSF 1 CACHE INTERNAL "TLSF allocator")
else(TLSF)
  set(DUNE_USING_TLSF 0 CACHE INTERNAL "TLSF allocator")
endif(TLSF)

file(GLOB_RECURSE DUNE_CORE_SOURCES "${PROJECT_SOURCE_DIR}/src/DUNE/*.cpp")
file(GLOB_RECURSE DUNE_CORE_HEADERS "${PROJECT_SOURCE_DIR}/src/DUNE/*.hpp"
  "${PROJECT_SOURCE_DIR}/src/DUNE/*.def")
file(GLOB_RECURSE DUNE_CORE_DEFS    "${PROJECT_SOURCE_DIR}/src/DUNE/*.def")
string(REPLACE ";" " " DUNE_CORE_HEADERS_STRING "${DUNE_CORE_HEADERS}")

file(GLOB_RECURSE PRIVATE_CORE_SOURCES "${PROJECT_SOURCE_DIR}/private*/src/DUNE/Control/*.cpp")
file(GLOB_RECURSE PRIVATE_CORE_HEADERS "${PROJECT_SOURCE_DIR}/private*/src/DUNE/Control/*.hpp")
string(REPLACE ";" " " PRIVATE_CORE_HEADERS_STRING "${PRIVATE_CORE_HEADERS}")

file(GLOB_RECURSE USER_CORE_SOURCES "${PROJECT_SOURCE_DIR}/user*/src/USER/*.cpp")
file(GLOB_RECURSE USER_CORE_HEADERS "${PROJECT_SOURCE_DIR}/user*/src/USER/*.hpp")
string(REPLACE ";" " " USER_CORE_HEADERS_STRING "${USER_CORE_HEADERS}")

configure_file(${PROJECT_SOURCE_DIR}/src/DUNE/Config.hpp.in
  ${DUNE_GENERATED}/src/DUNE/Config.hpp)

install(FILES ${DUNE_GENERATED}/src/DUNE/Config.hpp
  DESTINATION include/DUNE)

include(${PROJECT_SOURCE_DIR}/cmake/Version.cmake)

message(STATUS "")
message(STATUS "******************************************")
message(STATUS "***            Compiler Flags          ***")
message(STATUS "******************************************")

if(NOT DUNE_OS_WINDOWS)
  message(STATUS "Adding: -Wno-cpp")
  set(DUNE_CXX_FLAGS "${DUNE_CXX_FLAGS} -Wno-cpp")
  set(DUNE_C_FLAGS "${DUNE_C_FLAGS} -Wno-cpp")
endif(NOT DUNE_OS_WINDOWS)

message(STATUS "DUNE_CXX_FLAGS: ${DUNE_CXX_FLAGS}")
message(STATUS "DUNE_C_FLAGS: ${DUNE_C_FLAGS}")

set_source_files_properties(${DUNE_CORE_SOURCES} ${USER_CORE_SOURCES} ${PRIVATE_CORE_SOURCES}
  PROPERTIES COMPILE_FLAGS "${DUNE_CXX_FLAGS} ${DUNE_CXX_FLAGS_STRICT}")

if(DUNE_OS_WINDOWS)
  configure_file(${PROJECT_SOURCE_DIR}/src/DUNE/Version.rc.in
    ${DUNE_GENERATED}/src/DUNE/Version.rc)

  set(DUNE_CORE_SOURCES ${DUNE_CORE_SOURCES}
    ${DUNE_GENERATED}/src/DUNE/Version.rc)
endif(DUNE_OS_WINDOWS)

foreach(header ${DUNE_CORE_HEADERS} ${USER_CORE_HEADERS} ${PRIVATE_CORE_HEADERS})
  string(REGEX REPLACE "${PROJECT_SOURCE_DIR}/" "" header ${header})
  string(REGEX REPLACE "src" "include" destination ${header})
  get_filename_component(destination ${destination} PATH)
  install(FILES ${header} DESTINATION ${destination})
endforeach(header ${DUNE_CORE_HEADERS})

# Bundled Libraries.
file(GLOB extlibs ${PROJECT_SOURCE_DIR}/vendor/libraries/*/Library.cmake)
foreach(extlib ${extlibs})
  include(${extlib})
endforeach(extlib ${extlibs})

# Private Libraries.
file(GLOB extlibs ${PROJECT_SOURCE_DIR}/private*/vendor/libraries/*/Library.cmake)
foreach(extlib ${extlibs})
  include(${extlib})
endforeach(extlib ${extlibs})

# User Libraries.
file(GLOB extlibs ${PROJECT_SOURCE_DIR}/user*/vendor/libraries/*/Library.cmake)
foreach(extlib ${extlibs})
  include(${extlib})
endforeach(extlib ${extlibs})

file(GLOB DUNE_SOURCE_USER ${PROJECT_SOURCE_DIR}/user*/src)
file(GLOB DUNE_SOURCE_PRIVATE ${PROJECT_SOURCE_DIR}/private*/src)
include_directories(${DUNE_GENERATED}/src ${PROJECT_SOURCE_DIR}/src ${DUNE_SOURCE_USER} ${DUNE_SOURCE_PRIVATE} ${DUNE_VENDOR_INCS_DIR})
link_directories(${DUNE_VENDOR_LIBS_DIR})
set(DUNE_CORE_FILES ${DUNE_CORE_SOURCES} ${DUNE_VENDOR_FILES})
set(USER_CORE_FILES ${USER_CORE_SOURCES} ${USER_VENDOR_FILES})
set(PRIVATE_CORE_FILES ${PRIVATE_CORE_SOURCES} ${PRIVATE_VENDOR_FILES})

if(DUNE_SHARED)
  message(STATUS "Building shared library")
  add_library(dune-core SHARED ${DUNE_CORE_FILES} ${USER_CORE_FILES} ${PRIVATE_CORE_FILES} )
  set_target_properties(dune-core PROPERTIES DEFINE_SYMBOL DUNE_DLL_EXPORT)
  target_link_libraries(dune-core ${DUNE_SYS_LIBS})
else(DUNE_SHARED)
  message(STATUS "Building static library")
  add_library(dune-core STATIC ${DUNE_CORE_FILES} ${USER_CORE_FILES} ${PRIVATE_CORE_FILES} )
  if(DUNE_CXX_MICROSOFT AND DUNE_CPU_X86)
    if(DUNE_CPU_32B)
      set_target_properties(dune-core PROPERTIES STATIC_LIBRARY_FLAGS "/machine:x86")
    else(DUNE_CPU_32B)
      set_target_properties(dune-core PROPERTIES STATIC_LIBRARY_FLAGS "/machine:x64")
    endif(DUNE_CPU_32B)
  endif(DUNE_CXX_MICROSOFT AND DUNE_CPU_X86)
endif(DUNE_SHARED)

add_dependencies(dune-core dune-version)

# WGS84 Coordinate Type
if(ELLIPSOIDAL)
  add_definitions(-DDUNE_ELLIPSOIDAL_DISPLACE)
endif(ELLIPSOIDAL)

##########################################################################
#                          Tasks                                         #
##########################################################################
include(${PROJECT_SOURCE_DIR}/cmake/Tasks.cmake)

##########################################################################
#                          DUNE's Executable                             #
##########################################################################
if(CMAKE_RC_COMPILER)
  enable_language(RC)
endif(CMAKE_RC_COMPILER)

# Daemon.
configure_file(${PROJECT_SOURCE_DIR}/src/Main/StaticTasks.cpp.cmake
  ${DUNE_GENERATED}/src/Main/StaticTasks.cpp)

add_executable(dune
  ${DUNE_TASKS}
  ${DUNE_GENERATED}/src/Main/StaticTasks.cpp
  src/Main/Assets.rc
  src/Main/Daemon.cpp)
set_source_files_properties(src/Main/Daemon.cpp
  PROPERTIES
  COMPILE_FLAGS "${DUNE_CXX_FLAGS}")
target_link_libraries(dune dune-core ${DUNE_SYS_LIBS} ${DUNE_STATIC_TASKS}
  ${DUNE_VENDOR_LIBS})

# Launcher.
add_executable(dune-launcher
  src/Main/Assets.rc
  src/Main/Launcher.cpp)
set_source_files_properties(src/Main/Launcher.cpp
  PROPERTIES
  COMPILE_FLAGS "${DUNE_CXX_FLAGS}")
target_link_libraries(dune-launcher dune-core ${DUNE_SYS_LIBS}
  ${DUNE_VENDOR_LIBS})

##########################################################################
#                          Simple programs                               #
##########################################################################
macro(dune_program source exclude)
  get_filename_component(executable ${source} NAME_WE)
  if(${exclude})
    add_executable(${executable} EXCLUDE_FROM_ALL ${source})
  else(${exclude})
    add_executable(${executable} ${source})
    set(DUNE_EXTRA_EXE ${DUNE_EXTRA_EXE} ${executable})
  endif(${exclude})
  set_target_properties(${executable} PROPERTIES COMPILE_FLAGS "${DUNE_CXX_FLAGS}")
  target_link_libraries(${executable} dune-core ${DUNE_SYS_LIBS} ${DUNE_VENDOR_LIBS})
endmacro(dune_program source)

file(GLOB programs programs/*.cpp)
foreach(program ${programs})
  dune_program(${program} 1)
endforeach(program ${programs})

file(GLOB programs programs/utils/*.cpp)
foreach(program ${programs})
  dune_program(${program} 0)
endforeach(program ${programs})

##########################################################################
#                          Documentation                                 #
##########################################################################
if(DUNE_PROGRAM_DOXYGEN AND DUNE_PROGRAM_ZIP)
  set(DUNE_DOCS_LABEL
    dune-${PROJECT_VERSION}-docs)

  set(DUNE_DOXYGEN_DOCS_DIR
    ${DUNE_GENERATED}/${DUNE_DOCS_LABEL})

  configure_file(${PROJECT_SOURCE_DIR}/doc/Doxygen/Doxyfile.in
    ${DUNE_GENERATED}/Doxyfile)

  add_custom_target(doc
    ${DUNE_PROGRAM_DOXYGEN} ${DUNE_GENERATED}/Doxyfile)

  add_custom_target(doc_package
    zip -r ${CMAKE_BINARY_DIR}/${DUNE_DOCS_LABEL}.zip ${DUNE_DOCS_LABEL}
    WORKING_DIRECTORY ${DUNE_GENERATED})

  add_dependencies(doc_package doc)
endif(DUNE_PROGRAM_DOXYGEN AND DUNE_PROGRAM_ZIP)

##########################################################################
#                        Packaging/Installation                          #
##########################################################################
install(TARGETS dune dune-launcher dune-core ${DUNE_EXTRA_EXE}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib)

# Install www helper files.
install(DIRECTORY www DESTINATION .)

# Install configuration files.
install(DIRECTORY etc DESTINATION .)

if(EXISTS "${PROJECT_SOURCE_DIR}/private/etc/")
  # Install private configuration files.
  install(DIRECTORY private/etc DESTINATION ./private/)
endif(EXISTS "${PROJECT_SOURCE_DIR}/private/etc/")

if(EXISTS "${PROJECT_SOURCE_DIR}/user/etc/")
  # Install user configuration files.
  install(DIRECTORY user/etc DESTINATION ./user/)
endif(EXISTS "${PROJECT_SOURCE_DIR}/user/etc/")

# Install scripts.
install(DIRECTORY programs/scripts DESTINATION .)

# MinGW dependencies.
include(cmake/MinGW.cmake)

# LAUV Simulator link.
if(DUNE_OS_WINDOWS)
  set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL 1)

  set(CPACK_NSIS_CREATE_ICONS_EXTRA "CreateShortCut          \\\\
    '$SMPROGRAMS\\\\$STARTMENU_FOLDER\\\\LAUV Simulator.lnk' \\\\
    '$INSTDIR\\\\bin\\\\dune.exe'                            \\\\
    '-c lauv-simulator-1 -p Simulation'")

  set(CPACK_NSIS_DELETE_ICONS_EXTRA "Delete                  \\\\
    '$SMPROGRAMS\\\\$MUI_TEMP\\\\LAUV Simulator.lnk'")
endif(DUNE_OS_WINDOWS)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_NAME})
set(CPACK_PACKAGE_NAME ${PROJECT_SHORT_NAME})
set(CPACK_PACKAGE_VENDOR ${PROJECT_VENDOR})
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_CONTACT ${PROJECT_CONTACT})
set(CPACK_STRIP_FILES "bin/dune")
set(CPACK_PACKAGE_EXECUTABLES ${DUNE_EXTRA_EXE_NAMES})
set(CPACK_PACKAGE_FILE_NAME
  "dune-${CPACK_PACKAGE_VERSION}-${DUNE_SYSTEM_NAME_VAR}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY
  "${PROJECT_SHORT_NAME} v${PROJECT_VERSION}")
set(CPACK_RESOURCE_FILE_LICENSE
  "${PROJECT_SOURCE_DIR}/LICENCE.md")
dune_set_path(CPACK_PACKAGE_ICON
  "${PROJECT_SOURCE_DIR}/assets/icons/install.bmp")
dune_set_path(CPACK_NSIS_MUI_ICON
  "${PROJECT_SOURCE_DIR}/assets/icons/dune.ico")
set(CPACK_NSIS_MUI_UNIICON
  "${CPACK_NSIS_MUI_ICON}")
set(CPACK_NSIS_DISPLAY_NAME
  "${PROJECT_SHORT_NAME} ${PROJECT_VERSION}")

if(DUNE_OS_WINDOWS)
  set(CPACK_GENERATOR "NSIS;ZIP")
else(DUNE_OS_WINDOWS)
  set(CPACK_GENERATOR "TBZ2")
endif(DUNE_OS_WINDOWS)

include(InstallRequiredSystemLibraries)
include(CPack)

include(programs/video-client/Program.cmake)
include(programs/gsmux/Program.cmake)

##########################################################################
#                                 Tests                                  #
##########################################################################
option(TESTS "Compile test programs" FALSE)

if(TESTS)
  enable_testing()

  macro(dune_test source)
    get_filename_component(executable ${source} NAME_WE)
    add_executable(${executable} ${source})
    set_target_properties(${executable} PROPERTIES COMPILE_FLAGS
      "${DUNE_CXX_FLAGS}")
    target_link_libraries(${executable} dune-core ${DUNE_SYS_LIBS}
      ${DUNE_VENDOR_LIBS})
    ADD_TEST(${executable} ${executable})
  endmacro(dune_test source)

  file(GLOB_RECURSE DUNE_TESTS_SOURCES
    "${PROJECT_SOURCE_DIR}/programs/tests/*.cpp")
  foreach(test ${DUNE_TESTS_SOURCES})
    dune_test(${test})
  endforeach(test ${DUNE_TESTS_SOURCES})
endif(TESTS)

##########################################################################
#                                CDash                                   #
##########################################################################
include(Dart)

##########################################################################
#                             CLANG-FORMAT                               #
##########################################################################
find_program(
  CLANG_FORMAT_EXECUTABLE
  NAMES "clang-format"
  DOC "Path to clang-format executable"
  )
if(NOT CLANG_FORMAT_EXECUTABLE)
  message(STATUS "clang-format not found.")
else()
  message(STATUS "clang-format found: ${CLANG_FORMAT_EXECUTABLE}")
  set(DO_CLANG_FORMAT "${CLANG_FORMAT_EXECUTABLE}" -i -style=file)
endif()

if(CLANG_FORMAT_EXECUTABLE)
  add_custom_target(
    clang-format-core-sources
    COMMAND "${CLANG_FORMAT_EXECUTABLE}" -i -style=file ${DUNE_CORE_HEADERS} ${DUNE_CORE_SOURCES}
  )
  add_custom_target(
    clang-format-programs
    COMMAND "${CLANG_FORMAT_EXECUTABLE}" -i -style=file ${programs}
  )
  add_custom_target(
    clang-format-tests
    COMMAND "${CLANG_FORMAT_EXECUTABLE}" -i -style=file ${DUNE_TESTS_SOURCES}
  )
  add_custom_target(
    clang-format-tasks
    COMMAND "${CLANG_FORMAT_EXECUTABLE}" -i -style=file ${ALL_TASK_SOURCES} ${ALL_TASK_HEADERS}
  )
endif()
