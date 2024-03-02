add_library(queuearr queuearr.cpp queuearr.hpp)
set_property(TARGET queuearr PROPERTY CXX_STANDARD 20)
target_include_directories(queuearr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS queuearr)