
cmake_minimum_required(VERSION 3.15)

set(PMR_Src
  ${CMAKE_CURRENT_SOURCE_DIR}/src/polymorphic_allocator.cpp
)

add_library(pmrlib STATIC ${PMR_Src})


target_include_directories(pmrlib
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)


install(TARGETS pmrlib EXPORT ${CMAKE_PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING
  PATTERN "*.h"
  PATTERN "*.inl"
  PATTERN "*.hpp"
  PATTERN "*.ih"
)