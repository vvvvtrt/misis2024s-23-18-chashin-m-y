add_executable(test_complex test_complex.cpp "test_complex.cpp")

target_link_libraries(test_complex complex)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_complex)


add_executable(test_rational test_rational.cpp "test_rational.cpp")

target_link_libraries(test_rational rational)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_rational)


add_executable(test_dynarr test_dynarr.cpp "test_dynarr.cpp")

target_link_libraries(test_dynarr dynarr)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_dynarr)



