#ifndef TASTR_AST_LIST_TYPE_NODE_H
#define TASTR_AST_LIST_TYPE_NODE_H

#include "TypeNode.hpp"
#include "TypeNodeSequenceNode.hpp"

namespace tastr::ast {

class ListTypeNode final: public TypeNode {
  public:
    explicit ListTypeNode(TypeNodeSequenceNodeUPtr element_types)
        : TypeNode(), element_types_(std::move(element_types)) {
    }

    ~ListTypeNode() = default;

    ListTypeNode(const ListTypeNode& node)
        : TypeNode(node), element_types_(node.element_types_->clone()) {
    }

    ListTypeNode(ListTypeNode&& node)
        : TypeNode(std::move(node))
        , element_types_(std::move(node.element_types_)) {
    }

    ListTypeNode& operator=(const ListTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        element_types_ = node.element_types_->clone();
        return *this;
    }

    ListTypeNode& operator=(ListTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        element_types_ = std::move(node.element_types_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ListTypeNode> clone() const {
        return std::unique_ptr<ListTypeNode>(this->clone_impl());
    }

    bool is_list_type_node() const override final {
        return true;
    }

    TypeNodeSequenceNode& get_element_types() const {
        return *element_types_.get();
    }

  private:
    virtual ListTypeNode* clone_impl() const override final {
        return new ListTypeNode(*this);
    };

    TypeNodeSequenceNodeUPtr element_types_;
};

using ListTypeNodePtr = ListTypeNode*;
using ListTypeNodeUPtr = std::unique_ptr<ListTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LIST_TYPE_NODE_H */
