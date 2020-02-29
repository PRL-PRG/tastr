#ifndef TASTR_AST_STRUCT_TYPE_H
#define TASTR_AST_STRUCT_TYPE_H

#include "SequenceTypeNode.h"
#include "TaggedTypeNode.h"

namespace tastr::ast {

class StructTypeNode final: public SequenceTypeNode<TaggedTypeNode> {
  public:
    explicit StructTypeNode(
        std::unique_ptr<std::vector<std::unique_ptr<TaggedTypeNode>>> sequence)
        : SequenceTypeNode(std::move(sequence)) {
    }

    ~StructTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using StructTypeNodePtr = StructTypeNode*;
using StructTypeNodeUPtr = std::unique_ptr<StructTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_STRUCT_TYPE_H */
