# - Try to find Photos++
# Defines:
#
#  Photos++_FOUND
#  Photos++_INCLUDE_DIR
#  Photos++_INCLUDE_DIRS (not cached)
#  Photos++_<component>_LIBRARY
#  Photos++_<component>_FOUND
#  Photos++_LIBRARIES (not cached)
#  Photos++_LIBRARY_DIRS (not cached)

#  Check all list if none is explicitly requested
if(NOT Photos++_FIND_COMPONENTS)
  set(Photos++_FIND_COMPONENTS pp ppHepMC ppHEPEVT ppHepMC3)
endif()
set(Photos++_FOUND TRUE)
foreach(component ${Photos++_FIND_COMPONENTS})
  find_library(Photos++_${component}_LIBRARY NAMES Photos${component}
               HINTS ${Photos++_ROOT_DIR}/lib $ENV{PHOTOSPP_ROOT_DIR}/lib ${PHOTOSPP_ROOT_DIR}/lib
                     ${Photos++_ROOT_DIR}/lib64 $ENV{PHOTOSPP_ROOT_DIR}/lib64 ${PHOTOSPP_ROOT_DIR}/lib64
               )
  if (Photos++_${component}_LIBRARY)
    set(Photos++_${component}_FOUND TRUE)
    list(APPEND Photos++_LIBRARIES ${Photos++_${component}_LIBRARY})
    get_filename_component(libdir ${Photos++_${component}_LIBRARY} PATH)
    list(APPEND Photos++_LIBRARY_DIRS ${libdir})
  else()
    set(Photos++_${component}_FOUND FALSE)
    if (Photos++_FIND_REQUIRED_${component})
    set(Photos++_FOUND FALSE)
    endif()
  endif()
  message(STATUS "EvtGen: Photos++_${component}_FOUND=${Photos++_${component}_FOUND}, Photos++_FIND_REQUIRED_${component}=${Photos++_FIND_REQUIRED_${component}}  in ${Photos++_${component}_LIBRARY}")
  mark_as_advanced(Photos++_${component}_LIBRARY)
endforeach()

if(Photos++_LIBRARY_DIRS)
  list(REMOVE_DUPLICATES Photos++_LIBRARY_DIRS)
endif()

find_path(Photos++_INCLUDE_DIR Photos/Photos.h
          HINTS ${Photos++_ROOT_DIR}/include
                $ENV{PHOTOSPP_ROOT_DIR}/include
                ${PHOTOSPP_ROOT_DIR}/include)
set(Photos++_INCLUDE_DIRS ${Photos++_INCLUDE_DIR} ${Photos++_INCLUDE_DIR}/Photos)
mark_as_advanced(Photos++_INCLUDE_DIR)

# handle the QUIETLY and REQUIRED arguments and set Photos++_FOUND to TRUE if
# all listed variables are TRUE
if (Photos++_FOUND)
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Photos++ DEFAULT_MSG Photos++_INCLUDE_DIR Photos++_LIBRARIES)
endif()
mark_as_advanced(Photos++_FOUND)
