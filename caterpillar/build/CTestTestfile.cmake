# CMake generated Testfile for 
# Source directory: /mnt/c/minmin_tranova/Caterpillar/caterpillar
# Build directory: /mnt/c/minmin_tranova/Caterpillar/caterpillar/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[PointTest]=] "/mnt/c/minmin_tranova/Caterpillar/caterpillar/build/runTests" "--gtest_filter=PointTest*")
set_tests_properties([=[PointTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/minmin_tranova/Caterpillar/caterpillar/CMakeLists.txt;36;add_test;/mnt/c/minmin_tranova/Caterpillar/caterpillar/CMakeLists.txt;0;")
add_test([=[CaterpillarTest]=] "/mnt/c/minmin_tranova/Caterpillar/caterpillar/build/runTests" "--gtest_filter=CaterpillarTest*")
set_tests_properties([=[CaterpillarTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/minmin_tranova/Caterpillar/caterpillar/CMakeLists.txt;37;add_test;/mnt/c/minmin_tranova/Caterpillar/caterpillar/CMakeLists.txt;0;")
add_test([=[GameFieldTest]=] "/mnt/c/minmin_tranova/Caterpillar/caterpillar/build/runTests" "--gtest_filter=GameFieldTest*")
set_tests_properties([=[GameFieldTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/mnt/c/minmin_tranova/Caterpillar/caterpillar/CMakeLists.txt;38;add_test;/mnt/c/minmin_tranova/Caterpillar/caterpillar/CMakeLists.txt;0;")
