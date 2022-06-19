cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)
project(DervativePricing CXX)

add_subdirectory(ch3_Option_Class/src)
add_subdirectory(ch3_Option_Class/test)

add_subdirectory(ch4_PayOffBridge/src)
add_subdirectory(ch4_PayOffBridge/test)