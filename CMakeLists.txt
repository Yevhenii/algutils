cmake_minimum_required (VERSION 3.8 FATAL_ERROR)
project (algs)

include_directories("include")

#add_library(algs STATIC plugin_1.c)

add_executable(binary_search_sample binary_search_sample.cpp)
#target_link_libraries(test_plugins LINK_PUBLIC ${Boost_LIBRARIES} dl)
