project(HellowLib) 
set(PROJECT_VERSION 1.0.0)

cmake_minimum_required (VERSION 3.5)

include(GNUInstallDirs)

# WINDOWS PDB FILE 
if(MSVC)
  set(pdb_output_dir "${CMAKE_CURRENT_BINARY_DIR}/pdb-files")

  set(CMAKE_PDB_OUTPUT_DIRECTORY "${pdb_output_dir}")
  set(CMAKE_COMPILE_PDB_OUTPUT_DIRECTORY "${pdb_output_dir}")

  get_cmake_property(is_multi GENERATOR_IS_MULTI_CONFIG)
  if(is_multi)
    set(config_suffix "$<CONFIG>")
  else()
    set(config_suffix "")
  endif()

  if(BUILD_SHARED_LIBS)
    set(pdb_dst ${CMAKE_INSTALL_BINDIR})
  else()
    set(pdb_dst ${CMAKE_INSTALL_LIBDIR})
  endif()

  install(
      DIRECTORY "${pdb_output_dir}/${config_suffix}/"
      DESTINATION ${pdb_dst}
  )
endif()


# BUILD OPTIONS
set(SRC 
    src/HellowLib.cpp
)

add_compile_definitions(EXPORTS)
add_library(${PROJECT_NAME} SHARED ${SRC})

target_compile_definitions(${PROJECT_NAME} PUBLIC "${PROJECT_NAME}:DEBUG=$<CONFIG:Debug>")

target_include_directories(
  ${PROJECT_NAME}  PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
  "$<INSTALL_INTERFACE:include>"
)

# Configuration
set(config_install_dir "${CMAKE_INSTALL_PREFIX}/cmake/")
set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/cmake")
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")

# Include module with fuction 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

# INSTALL 
install(
    TARGETS ${PROJECT_NAME} 
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
    INCLUDES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

install(
    DIRECTORY "include"
    DESTINATION "${CMAKE_INSTALL_PREFIX}"
    FILES_MATCHING PATTERN "*.h"
)

install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    DESTINATION "${config_install_dir}"
)