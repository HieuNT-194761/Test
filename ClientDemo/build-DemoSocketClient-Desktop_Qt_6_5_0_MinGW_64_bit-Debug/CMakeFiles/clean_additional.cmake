# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DemoSocketClient_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DemoSocketClient_autogen.dir\\ParseCache.txt"
  "DemoSocketClient_autogen"
  )
endif()
