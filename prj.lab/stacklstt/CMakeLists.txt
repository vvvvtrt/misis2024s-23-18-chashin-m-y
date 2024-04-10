add_library(stacklstt stacklstt.hpp)
set_property(TARGET stacklstt PROPERTY CXX_STANDARD 20)
target_include_directories(stacklstt PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS stacklstt)