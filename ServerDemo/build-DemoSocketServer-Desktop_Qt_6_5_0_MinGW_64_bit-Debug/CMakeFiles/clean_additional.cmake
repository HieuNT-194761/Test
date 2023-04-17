# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DemoSocketServer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DemoSocketServer_autogen.dir\\ParseCache.txt"
  "DemoSocketServer_autogen"
  )
endif()
