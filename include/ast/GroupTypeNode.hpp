#ifndef TASTR_AST_GROUP_TYPE_NODE_H
#define TASTR_AST_GROUP_TYPE_NODE_H

#include "TypeNode.hpp"

#include <memory>

namespace tastr::ast {

class GroupTypeNode final: public TypeNode {
  public:
    explicit GroupTypeNode(std::unique_ptr<TypeNode> inner_type)
        : TypeNode(), inner_type_(std::move(inner_type)) {
    }

    ~GroupTypeNode() = default;

    GroupTypeNode(const GroupTypeNode& node)
        : TypeNode(node), inner_type_(node.inner_type_->clone()) {
    }

    GroupTypeNode(GroupTypeNode&& node)
        : TypeNode(std::move(node)), inner_type_(std::move(node.inner_type_)) {
    }

    GroupTypeNode& operator=(const GroupTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        inner_type_ = node.inner_type_->clone();
        return *this;
    }

    GroupTypeNode& operator=(GroupTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        inner_type_ = std::move(node.inner_type_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::TypeNode& get_inner_type() const {
        return *inner_type_.get();
    }

    std::unique_ptr<GroupTypeNode> clone() const {
        return std::unique_ptr<GroupTypeNode>(this->clone_impl());
    }

    bool is_group_type_node() const override final {
        return true;
    }

  private:
    virtual GroupTypeNode* clone_impl() const override final {
        return new GroupTypeNode(*this);
    };

    std::unique_ptr<TypeNode> inner_type_;
};

using GroupTypeNodePtr = GroupTypeNode*;
using GroupTypeNodeUPtr = std::unique_ptr<GroupTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_GROUP_TYPE_NODE_H */
