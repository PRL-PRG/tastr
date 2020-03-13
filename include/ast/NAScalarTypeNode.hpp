#ifndef TASTR_AST_NA_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_NA_SCALAR_TYPE_NODE_HPP

#include "ast/AScalarTypeNode.hpp"
#include "ast/ScalarTypeNode.hpp"

namespace tastr::ast {

class NAScalarTypeNode final: public ScalarTypeNode {
  public:
    explicit NAScalarTypeNode(std::unique_ptr<AScalarTypeNode> a_scalar_type)
        : ScalarTypeNode(), a_scalar_type_(std::move(a_scalar_type)) {
    }

    virtual ~NAScalarTypeNode() = default;

    NAScalarTypeNode(const NAScalarTypeNode& node)
        : ScalarTypeNode(node), a_scalar_type_(node.a_scalar_type_->clone()) {
    }

    NAScalarTypeNode(NAScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node))
        , a_scalar_type_(std::move(node.a_scalar_type_)) {
    }

    NAScalarTypeNode& operator=(const NAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        a_scalar_type_ = node.a_scalar_type_->clone();
        return *this;
    }

    NAScalarTypeNode& operator=(NAScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        a_scalar_type_ = std::move(node.a_scalar_type_);
        return *this;
    }

    virtual void
    accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    virtual void
    accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<NAScalarTypeNode> clone() const {
        return std::unique_ptr<NAScalarTypeNode>(this->clone_impl());
    }

    const tastr::ast::AScalarTypeNode& get_a_scalar_type() const {
        return *a_scalar_type_.get();
    }

    bool is_na_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual NAScalarTypeNode* clone_impl() const override final {
        return new NAScalarTypeNode(*this);
    }

    std::unique_ptr<AScalarTypeNode> a_scalar_type_;
};

using NAScalarTypeNodePtr = NAScalarTypeNode*;
using NAScalarTypeNodeUPtr = std::unique_ptr<NAScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NA_SCALAR_TYPE_NODE_HPP */