add_library(libs_ch5
    SHARED
    MCStatistics.cpp
    PayOff3.cpp
    Random1.cpp
    Vanilla3.cpp
    ConvergenceTable.cpp
    Parameters.cpp  
    PayOffBridge.cpp
    SimpleMC7.cpp
    Wrapper.cpp
)

target_include_directories(libs_ch5
    PUBLIC ${CMAKE_SOURCE_DIR}/ch5_statistics_gatherer/include
)