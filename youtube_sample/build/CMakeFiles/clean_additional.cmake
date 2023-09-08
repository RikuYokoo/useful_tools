# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles/youtube_sample_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/youtube_sample_autogen.dir/ParseCache.txt"
  "youtube_sample_autogen"
  )
endif()
