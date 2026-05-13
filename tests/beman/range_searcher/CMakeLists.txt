# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

find_package(GTest REQUIRED)

add_executable(beman.range_searcher.tests.basic)
target_sources(beman.range_searcher.tests.basic PRIVATE basic.test.cpp)
target_link_libraries(
    beman.range_searcher.tests.basic
    PRIVATE beman::range_searcher GTest::gtest GTest::gtest_main
)

if(BEMAN_RANGE_SEARCHER_USE_MODULES)
    set_target_properties(
        beman.range_searcher.tests.basic
        PROPERTIES CXX_MODULE_STD ON
    )
endif()

include(GoogleTest)
gtest_discover_tests(beman.range_searcher.tests.basic DISCOVERY_TIMEOUT 60)
