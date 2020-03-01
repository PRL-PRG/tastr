#ifndef TASTR_AST_STRUCT_TYPE_H
#define TASTR_AST_STRUCT_TYPE_H

#include "TypeNode.h"
#include "Sequence.h"
#include "TagTypePairNode.h"

namespace tastr::ast {

class StructTypeNode final
    : public TypeNode
    , public TagTypePairNodeSequence {
  public:
    explicit StructTypeNode(TagTypePairNodeSequence sequence)
        : TypeNode(), TagTypePairNodeSequence(std::move(sequence)) {
    }

    ~StructTypeNode() {
    }

    StructTypeNode(const StructTypeNode& node)
        : TypeNode(node), TagTypePairNodeSequence(node) {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<StructTypeNode> clone() const {
        return std::unique_ptr<StructTypeNode>(this->clone_impl());
    }

    bool is_struct_type_node() const override final {
        return true;
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
