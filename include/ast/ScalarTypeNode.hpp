#ifndef TASTR_AST_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_SCALAR_TYPE_NODE_HPP

#include "TypeNode.hpp"

namespace tastr::ast {

class ScalarTypeNode: public TypeNode {
  public:
    explicit ScalarTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    virtual ~ScalarTypeNode() = default;

    ScalarTypeNode(const ScalarTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    ScalarTypeNode(ScalarTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    ScalarTypeNode& operator=(const ScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    ScalarTypeNode& operator=(ScalarTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    virtual void
    accept(tastr::visitor::ConstNodeVisitor& visitor) const override = 0;

    virtual void
    accept(tastr::visitor::MutableNodeVisitor& visitor) override = 0;

    std::unique_ptr<ScalarTypeNode> clone() const {
        return std::unique_ptr<ScalarTypeNode>(this->clone_impl());
    }

    bool is_scalar_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual ScalarTypeNode* clone_impl() const override = 0;

    std::string identifier_;
};

using ScalarTypeNodePtr = ScalarTypeNode*;
using ScalarTypeNodeUPtr = std::unique_ptr<ScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_SCALAR_TYPE_NODE_HPP */
