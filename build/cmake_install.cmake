<<<<<<< HEAD
# Install script for directory: D:/code/minesweeper

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/minesweeper")
=======
# Install script for directory: /home/dawidg81/minesweeper

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
>>>>>>> e6a7c80d3261e8b0c3e73294c0dace4d36158c5d
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
<<<<<<< HEAD
    set(CMAKE_INSTALL_CONFIG_NAME "")
=======
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
>>>>>>> e6a7c80d3261e8b0c3e73294c0dace4d36158c5d
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

<<<<<<< HEAD
=======
# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

>>>>>>> e6a7c80d3261e8b0c3e73294c0dace4d36158c5d
# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "D:/MinGW/bin/objdump.exe")
=======
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
>>>>>>> e6a7c80d3261e8b0c3e73294c0dace4d36158c5d
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "D:/code/minesweeper/build/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/home/dawidg81/minesweeper/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> e6a7c80d3261e8b0c3e73294c0dace4d36158c5d
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
