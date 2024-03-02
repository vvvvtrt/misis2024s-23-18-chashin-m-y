add_executable(test_complex test_complex.cpp "test_complex.cpp")
target_link_libraries(test_complex complex)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_complex)


add_executable(test_rational test_rational.cpp "test_rational.cpp")
target_link_libraries(test_rational rational)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_rational)


add_executable(test_dynarr test_dynarr.cpp "test_dynarr.cpp")
target_link_libraries(test_dynarr dynarr)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_dynarr)


add_executable(test_stackarr test_stackarr.cpp "test_stackarr.cpp")
target_link_libraries(test_stackarr stackarr)
target_link_libraries(test_stackarr complex)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stackarr)

add_executable(test_stacklst test_stacklst.cpp "test_stacklst.cpp")
target_link_libraries(test_stacklst stacklst)
target_link_libraries(test_stacklst complex)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_stacklst)

add_executable(test_queuelst test_queuelst.cpp "test_queuelst.cpp")
target_link_libraries(test_queuelst queuelst)
target_link_libraries(test_queuelst complex)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuelst)

add_executable(test_queuearr test_queuearr.cpp "test_queuearr.cpp")
# target_link_libraries(test_queuearr queuearr)
target_link_libraries(test_queuearr complex)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_queuearr)