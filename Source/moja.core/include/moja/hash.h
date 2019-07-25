
#ifndef MOJA_CORE_HASH_H_
#define MOJA_CORE_HASH_H_

#include "moja/_core_exports.h"

#include <Poco/Nullable.h>

#include <folly/hash/Hash.h>

#include <functional>  // needed by folly

namespace moja {
using folly::apply;
using folly::Hash;
using folly::hasher;

namespace hash {

using folly::hash::jenkins_rev_mix32;
using folly::hash::jenkins_rev_unmix32;
using folly::hash::twang_mix64;
using folly::hash::twang_unmix64;

using folly::hash::hash_combine;
using folly::hash::hash_combine_generic;
using folly::hash::hash_range;

// using folly::hash::SpookyHashV2;

template <typename T>
struct hasher<Poco::Nullable<T>> {
   size_t operator()(const Poco::Nullable<T>& key) const { return key.isNull() ? 0 : Hash()(key.value()); }
};

}  // namespace hash
}  // namespace moja

#endif  // MOJA_CORE_HASH_H_