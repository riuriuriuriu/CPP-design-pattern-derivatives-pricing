add_library(libs_ch4_PayOffBridge
    SHARED
    Parameters.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    Random1.cpp
    SimpleMC6.cpp
    Vanilla3.cpp
)

target_include_directories(libs_ch4_PayOffBridge
    PUBLIC ${CMAKE_SOURCE_DIR}/ch4_PayOffBridge/include
)