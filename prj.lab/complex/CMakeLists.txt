add_library(complex complex.cpp complex.hpp)
set_property(TARGET complex PROPERTY CXX_STANDARD 20)
target_include_directories(complex PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS complex)