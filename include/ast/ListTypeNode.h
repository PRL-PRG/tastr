#ifndef TASTR_AST_LIST_TYPE_H
#define TASTR_AST_LIST_TYPE_H

#include "CompositeTypeNode.h"
#include "Sequence.h"

namespace tastr::ast {

class ListTypeNode final
    : public CompositeTypeNode
    , public TypeNodeSequence {
  public:
    explicit ListTypeNode(TypeNodeSequence sequence)
        : CompositeTypeNode(), TypeNodeSequence(std::move(sequence)) {
    }

    ~ListTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ListTypeNodePtr = ListTypeNode*;
using ListTypeNodeUPtr = std::unique_ptr<ListTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LIST_TYPE_H */
