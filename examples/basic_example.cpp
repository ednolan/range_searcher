// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <beman/range_searcher/config.hpp>

#if BEMAN_RANGE_SEARCHER_USE_MODULES()

import std;

#else

    #include <functional>
    #include <iostream>
    #include <string>

    #if __cpp_lib_print >= 202207L
        #include <print>
    #endif

#endif

#include <beman/range_searcher/searcher.hpp>

namespace exe     = beman::range_searcher;
namespace branges = exe::ranges;

#if __cpp_lib_print >= 202207L && __cpp_lib_format_ranges >= 202207L
void print(auto&& rng) { std::print("{:s}", std::forward<decltype(rng)>(rng)); }

void println(auto&& rng) { std::println("{:s}", std::forward<decltype(rng)>(rng)); }
#else
void print(auto&& rng) {
    for (auto&& elem : rng)
        std::cout << elem;
}

void println(auto&& rng) {
    print(std::forward<decltype(rng)>(rng));
    std::cout << "\n";
}
#endif

// Example given in the paper for range-based searchers. (Needs C++23)
int main() {
    std::string haystack = "a quick brown fox jumps over the lazy dog";
    std::string needle   = "jump";

    branges::boyer_moore_searcher searcher(needle);
    auto                          result = branges::search(haystack, searcher);
    print(std::ranges::subrange{haystack.begin(), result.begin()});
    std::cout << '[';
    print(result);
    std::cout << ']';
    println(std::ranges::subrange{result.end(), haystack.end()});
    // Output: a quick brown fox [jump]s over the lazy dog

    if (branges::contains_subrange(haystack, branges::boyer_moore_horspool_searcher{needle}))
        std::cout << "jump found!\n";
    else
        std::cout << "jump not found!\n";
    if (branges::contains_subrange(haystack, branges::boyer_moore_horspool_searcher{"run"}))
        std::cout << "run found!\n";
    else
        std::cout << "run not found!\n";

    return 0;
}
