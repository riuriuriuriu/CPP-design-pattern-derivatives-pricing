add_library(libs
    SHARED
    PayOff2.cpp
    SimpleMonteCarlo3.cpp
    DoubleDigital.cpp
    Random1.cpp
    Vanilla1.cpp
)

target_include_directories(libs
    PUBLIC ${CMAKE_SOURCE_DIR}/ch3_Option_Class/include
)