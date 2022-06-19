add_library(libs_ch4_VirtualConstructor
    SHARED
    DoubleDigital2.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    Random1.cpp
    SimpleMC4.cpp
    Vanilla2.cpp
)

target_include_directories(libs_ch4_VirtualConstructor
    PUBLIC ${CMAKE_SOURCE_DIR}/ch4_VirtualConstructor/include
)