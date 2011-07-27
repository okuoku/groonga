#ifndef GRN_DAT_PREDICTIVE_CURSOR_HPP_
#define GRN_DAT_PREDICTIVE_CURSOR_HPP_

#include "cursor.hpp"
#include "vector.hpp"

namespace grn {
namespace dat {

class Trie;

class PredictiveCursor : public Cursor {
 public:
  PredictiveCursor();
  ~PredictiveCursor();

  void open(const Trie &trie,
            const String &str,
            UInt32 offset = 0,
            UInt32 limit = UINT32_MAX,
            UInt32 flags = 0);

  void close();

  bool next(Key *key);

  UInt32 offset() const {
    return offset_;
  }
  UInt32 limit() const {
    return limit_;
  }
  UInt32 flags() const {
    return flags_;
  }

 private:
  const Trie *trie_;
  UInt32 offset_;
  UInt32 limit_;
  UInt32 flags_;

  Vector<UInt32> buf_;
  UInt32 cur_;
  UInt32 end_;
  UInt32 min_length_;

  PredictiveCursor(const Trie &trie,
                   UInt32 offset, UInt32 limit, UInt32 flags);

  UInt32 fix_flags(UInt32 flags) const;
  void init(const String &str);
  void swap(PredictiveCursor *cursor);

  bool ascending_next(Key *key);
  bool descending_next(Key *key);

  static const UInt32 IS_ROOT_FLAG    = 0x80000000U;
  static const UInt32 POST_ORDER_FLAG = 0x80000000U;

  // Disallows copy and assignment.
  PredictiveCursor(const PredictiveCursor &);
  PredictiveCursor &operator=(const PredictiveCursor &);
};

}  // namespace dat
}  // namespace grn

#endif  // GRN_DAT_PREDICTIVE_CURSOR_HPP_