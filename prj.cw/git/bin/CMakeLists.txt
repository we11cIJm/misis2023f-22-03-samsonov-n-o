add_executable(main main.cpp)
#target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(main PRIVATE PkgConfig::LIBGIT2 gitlib)

install(TARGETS main DESTINATION bin COMPONENT main)

