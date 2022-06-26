add_library(libs_ch6
    SHARED
    AntiThetic.cpp
    MCStatistics.cpp
    Parameters.cpp
    PayOff3.cpp
    Random2.cpp
    Vanilla3.cpp
    Arrays.cpp
    ConvergenceTable.cpp
    Normals.cpp
    ParkMiller.cpp
    PayOffBridge.cpp
    SimpleMC8.cpp
    Wrapper.cpp
)

target_include_directories(libs_ch6
    PUBLIC ${CMAKE_SOURCE_DIR}/ch6_random_number_class/include
)