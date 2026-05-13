module;

#include <version>

export module beman.range_searcher;

import std;

#define BEMAN_RANGE_SEARCHER_INCLUDED_FROM_INTERFACE_UNIT
export {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winclude-angled-in-module-purview"
#include <beman/range_searcher/searcher.hpp>
#pragma clang diagnostic pop
}
