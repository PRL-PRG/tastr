#ifndef TASTR_AST_STRUCT_TYPE_H
#define TASTR_AST_STRUCT_TYPE_H

#include "CompositeTypeNode.h"
#include "Sequence.h"
#include "TaggedTypeNode.h"

namespace tastr::ast {

class StructTypeNode final
    : public CompositeTypeNode
    , public TaggedTypeNodeSequence {
  public:
    explicit StructTypeNode(TaggedTypeNodeSequence sequence)
        : CompositeTypeNode(), TaggedTypeNodeSequence(std::move(sequence)) {
    }

    ~StructTypeNode() {
    }

    StructTypeNode(const StructTypeNode& node)
        : CompositeTypeNode(node), TaggedTypeNodeSequence(node) {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<StructTypeNode> clone() const {
        return std::unique_ptr<StructTypeNode>(this->clone_impl());
    }

  private:
    virtual StructTypeNode* clone_impl() const override final {
        return new StructTypeNode(*this);
    }
};

using StructTypeNodePtr = StructTypeNode*;
using StructTypeNodeUPtr = std::unique_ptr<StructTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_STRUCT_TYPE_H */
