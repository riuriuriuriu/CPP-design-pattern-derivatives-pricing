add_library(libs_ch7
    SHARED
    AntiThetic.cpp
    ConvergenceTable.cpp
    MCStatistics.cpp
    ParkMiller.cpp
    PayOff3.cpp
    Wrapper.cpp
    Arrays.cpp
    ExoticBSEngine.cpp
    Normals.cpp
    PathDependent.cpp
    PayOffBridge.cpp
    ExoticEngine.cpp
    Parameters.cpp
    PathDependentAsian.cpp
    Random2.cpp
    PathDependentGeometricAsian.cpp
)

target_include_directories(libs_ch7
    PUBLIC ${CMAKE_SOURCE_DIR}/ch7_exotics_engine_and_template_pattern/include
)