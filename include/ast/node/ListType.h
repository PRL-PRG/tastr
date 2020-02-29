#ifndef TASTR_AST_NODE_LIST_TYPE_H
#define TASTR_AST_NODE_LIST_TYPE_H

#include "SequenceType.h"

namespace tastr::ast::node {

class ListType final: public SequenceType<Type> {
  public:
    explicit ListType(
        std::unique_ptr<std::vector<std::unique_ptr<Type>>> sequence)
        : SequenceType(std::move(sequence)) {
    }

    ~ListType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using ListTypePtr = ListType*;
using ListTypeUPtr = std::unique_ptr<ListType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_LIST_TYPE_H */
