# Install script for directory: /root/Code/OOP-Project/libs/raylib-cpp/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/root/Code/OOP-Project/libs/raylib-cpp/include/AudioDevice.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/AudioStream.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/AutomationEventList.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/BoundingBox.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Camera2D.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Camera3D.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Color.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/FileData.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/FileText.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Font.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Functions.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Gamepad.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Image.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Keyboard.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Material.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Matrix.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Mesh.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/MeshUnmanaged.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Model.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/ModelAnimation.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Mouse.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Music.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Ray.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/RayCollision.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/RaylibException.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/raylib-cpp-utils.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/raylib-cpp.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/raylib.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/raymath.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Rectangle.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/RenderTexture.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Shader.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Sound.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Text.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Texture.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/TextureUnmanaged.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Touch.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Vector2.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Vector3.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Vector4.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/VrStereoConfig.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Wave.hpp"
    "/root/Code/OOP-Project/libs/raylib-cpp/include/Window.hpp"
    )
endif()

