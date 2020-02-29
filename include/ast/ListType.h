#ifndef TASTR_AST_LIST_TYPE_H
#define TASTR_AST_LIST_TYPE_H

#include "SequenceType.h"

namespace tastr::ast {

class ListType final: public SequenceType<Type> {
  public:
    explicit ListType(
        std::unique_ptr<std::vector<std::unique_ptr<Type>>> sequence)
        : SequenceType(std::move(sequence)) {
    }

    ~ListType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ListTypePtr = ListType*;
using ListTypeUPtr = std::unique_ptr<ListType>;

} // namespace tastr::ast

#endif /* TASTR_AST_LIST_TYPE_H */
