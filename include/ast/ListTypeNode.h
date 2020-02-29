#ifndef TASTR_AST_LIST_TYPE_H
#define TASTR_AST_LIST_TYPE_H

#include "SequenceTypeNode.h"

namespace tastr::ast {

class ListTypeNode final: public SequenceTypeNode<TypeNode> {
  public:
    explicit ListTypeNode(
        std::unique_ptr<std::vector<std::unique_ptr<TypeNode>>> sequence)
        : SequenceTypeNode(std::move(sequence)) {
    }

    ~ListTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using ListTypeNodePtr = ListTypeNode*;
using ListTypeNodeUPtr = std::unique_ptr<ListTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LIST_TYPE_H */
