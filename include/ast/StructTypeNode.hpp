#ifndef TASTR_AST_STRUCT_TYPE_NODE_H
#define TASTR_AST_STRUCT_TYPE_NODE_H

#include "TagTypePairNode.hpp"
#include "TagTypePairNodeSequenceNode.hpp"
#include "TypeNode.hpp"

namespace tastr::ast {

class StructTypeNode final: public TypeNode {
  public:
    explicit StructTypeNode(TagTypePairNodeSequenceNodeUPtr element_types)
        : TypeNode(), element_types_(std::move(element_types)) {
    }

    ~StructTypeNode() = default;

    StructTypeNode(const StructTypeNode& node)
        : TypeNode(node), element_types_(node.element_types_->clone()) {
    }

    StructTypeNode(StructTypeNode&& node)
        : TypeNode(std::move(node)), element_types_(std::move(node.element_types_)) {
    }

    StructTypeNode& operator=(const StructTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        element_types_ = node.element_types_->clone();
        return *this;
    }

    StructTypeNode& operator=(StructTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        element_types_ = std::move(node.element_types_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<StructTypeNode> clone() const {
        return std::unique_ptr<StructTypeNode>(this->clone_impl());
    }

    bool is_struct_type_node() const override final {
        return true;
    }

    TagTypePairNodeSequenceNode& get_element_types() const {
        return *element_types_.get();
    }

  private:
    virtual StructTypeNode* clone_impl() const override final {
        return new StructTypeNode(*this);
    }

    TagTypePairNodeSequenceNodeUPtr element_types_;
};

using StructTypeNodePtr = StructTypeNode*;
using StructTypeNodeUPtr = std::unique_ptr<StructTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_STRUCT_TYPE_NODE_H */
