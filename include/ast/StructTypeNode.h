#ifndef TASTR_AST_STRUCT_TYPE_H
#define TASTR_AST_STRUCT_TYPE_H

#include "Sequence.h"
#include "TaggedTypeNode.h"
#include "CompositeTypeNode.h"

namespace tastr::ast {

class StructTypeNode final
    : public CompositeTypeNode
    , public TaggedTypeNodeSequence {
  public:
    explicit StructTypeNode(TaggedTypeNodeSequence sequence)
        : CompositeTypeNode(), Sequence(std::move(sequence)) {
    }

    ~StructTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using StructTypeNodePtr = StructTypeNode*;
using StructTypeNodeUPtr = std::unique_ptr<StructTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_STRUCT_TYPE_H */
