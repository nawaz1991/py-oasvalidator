cmake_minimum_required(VERSION 3.4...3.18)
project(py-oasvalidator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(Python REQUIRED COMPONENTS Interpreter Development)
add_subdirectory(thirdparty/pybind11)

include_directories(include)
include_directories(thirdparty/cpp-oasvalidator/include)
include_directories(thirdparty/cpp-oasvalidator/thirdparty/rapidjson/include)

# Recursively collect all .cpp files from the cpp-oasvalidator source
file(GLOB_RECURSE CPP_OASVALIDATOR_SRC
        "thirdparty/cpp-oasvalidator/src/*.cpp")

# Remove the specific file you don't want to include
list(REMOVE_ITEM CPP_OASVALIDATOR_SRC
        "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/cpp-oasvalidator/src/oas_validator.cpp")

# Collect src/*.cpp files (or however you prefer to handle your project sources)
file(GLOB PY_OASVALIDATOR_SRC "src/*.cpp")

# Combine cpp-oasvalidator source and project source
set(SOURCES
        ${PY_OASVALIDATOR_SRC}
        ${CPP_OASVALIDATOR_SRC})

pybind11_add_module(oasvalidator ${SOURCES})

target_link_libraries(oasvalidator PRIVATE pybind11::module pybind11::lto pybind11::windows_extras)

#pybind11_extension(oasvalidator)
if(NOT MSVC AND NOT ${CMAKE_BUILD_TYPE} MATCHES Debug|RelWithDebInfo)
    # Strip unnecessary sections of the binary on Linux/macOS
    pybind11_strip(oasvalidator)
endif()

target_compile_definitions(oasvalidator
        PRIVATE VERSION_INFO=${OASVALIDATOR_VERSION_INFO})

set_target_properties(oasvalidator PROPERTIES CXX_VISIBILITY_PRESET "hidden"
        CUDA_VISIBILITY_PRESET "hidden")

install(TARGETS oasvalidator
        COMPONENT python
        LIBRARY DESTINATION "lib/python3.8/site-packages"
        ARCHIVE DESTINATION "lib"
        RUNTIME DESTINATION "bin")