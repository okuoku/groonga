#ifndef GRN_DAT_CURSOR_HPP_
#define GRN_DAT_CURSOR_HPP_

#include "key.hpp"

namespace grn {
namespace dat {

class Cursor {
 public:
  Cursor() {}
  virtual ~Cursor() {}

  virtual void close() = 0;

  virtual bool next(Key *key) = 0;

  virtual UInt32 offset() const = 0;
  virtual UInt32 limit() const = 0;
  virtual UInt32 flags() const = 0;

 private:
  // Disallows copy and assignment.
  Cursor(const Cursor &);
  Cursor &operator=(const Cursor &);
};

}  // namespace dat
}  // namespace grn

#endif  // GRN_DAT_CURSOR_HPP_