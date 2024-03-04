add_library(queuelstptr queuelstptr.cpp queuelstptr.hpp)
set_property(TARGET queuelstptr PROPERTY CXX_STANDARD 20)
target_include_directories(queuelstptr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS queuelstptr)