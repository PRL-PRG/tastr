#ifndef TASTR_AST_STRUCT_TYPE_H
#define TASTR_AST_STRUCT_TYPE_H

#include "TagTypePairNodeSequenceNode.h"
#include "TagTypePairNode.h"
#include "TypeNode.h"

namespace tastr::ast {

class StructTypeNode final: public TypeNode {
  public:
    explicit StructTypeNode(TagTypePairNodeSequenceNodeUPtr sequence)
        : TypeNode(), sequence_(std::move(sequence)) {
    }

    ~StructTypeNode() {
    }

    StructTypeNode(const StructTypeNode& node)
        : TypeNode(node), sequence_(node.get_element_types().clone()) {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<StructTypeNode> clone() const {
        return std::unique_ptr<StructTypeNode>(this->clone_impl());
    }

    bool is_struct_type_node() const override final {
        return true;
    }

    TagTypePairNodeSequenceNode& get_element_types() const {
        return *sequence_.get();
    }

  private:
    virtual StructTypeNode* clone_impl() const override final {
        return new StructTypeNode(*this);
    }

    TagTypePairNodeSequenceNodeUPtr sequence_;
};

using StructTypeNodePtr = StructTypeNode*;
using StructTypeNodeUPtr = std::unique_ptr<StructTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_STRUCT_TYPE_H */
