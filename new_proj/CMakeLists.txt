add_library(semantics SHARED src/semantics.cc)
target_include_directories(semantics PUBLIC ${CURRENT_SOURCE_DIR}/include)
add_executable(move src/semantics.cc)
add_executable(for_loops src/for_loops.cc)

target_link_libraries(move LINK_PUBLIC semantics)