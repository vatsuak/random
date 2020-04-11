# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

link_directories("/home/vatsuak/tensorflow/bazel-bin/tensorflow")
include_directories("/home/vatsuak/tensorflow")
include_directories("/home/vatsuak/tensorflow/bazel-tensorflow/external/eigen_archive")
include_directories("/home/vatsuak/tensorflow/bazel-tensorflow/external/protobuf_archive/src")
include_directories("/home/vatsuak/tensorflow/bazel-genfiles")
# include_directories("/home/vatsuak/tensorflow/tensorflow/contrib/makefile/downloads/absl")
# find_package(tensorflow REQUIRED)
add_executable(test_tf test_tf.cpp)

# Link the static Tensorflow library.
target_link_libraries(test_tf tensorflow_cc)
target_link_libraries(test_tf tensorflow_framework)

# Altenatively, link the shared Tensorflow library.
# target_link_libraries(test TensorflowCC::Shared)

# For shared library setting, you may also link cuda if it is available.
# find_package(CUDA)
# if(CUDA_FOUND)
#   target_link_libraries(test ${CUDA_LIBRARIES})
# endif()
