#ifndef TASTR_AST_NA_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_NA_SCALAR_TYPE_NODE_HPP

#include "ast/AScalarTypeNode.hpp"
#include "ast/OperatorNode.hpp"
#include "ast/ScalarTypeNode.hpp"

namespace tastr {
namespace ast {

class NAScalarTypeNode final: public ScalarTypeNode {
  public:
    explicit NAScalarTypeNode(OperatorNodeUPtr op,
                              std::unique_ptr<AScalarTypeNode> a_scalar_type)
        : ScalarTypeNode()
        , op_(std::move(op))
        , a_scalar_type_(std::move(a_scalar_type)) {
    }

    virtual ~NAScalarTypeNode() = default;

    NAScalarTypeNode(const NAScalarTypeNode& node)
        : ScalarTypeNode(node)
        , op_(node.op_->clone())
        , a_scalar_type_(node.a_scalar_type_->clone()) {
    }

    NAScalarTypeNode(NAScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node))
        , op_(std::move(node.op_))
        , a_scalar_type_(std::move(node.a_scalar_type_)) {
    }

    NAScalarTypeNode& operator=(const NAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        op_ = node.op_->clone();
        a_scalar_type_ = node.a_scalar_type_->clone();
        return *this;
    }

    NAScalarTypeNode& operator=(NAScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        op_ = std::move(node.op_);
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

    const OperatorNode& get_operator() const {
        return *op_.get();
    }

    Kind get_kind() const override final {
        return kind_;
    }

  private:
    virtual NAScalarTypeNode* clone_impl() const override final {
        return new NAScalarTypeNode(*this);
    }

    OperatorNodeUPtr op_;
    std::unique_ptr<AScalarTypeNode> a_scalar_type_;

    static const Kind kind_;
};

using NAScalarTypeNodePtr = NAScalarTypeNode*;
using NAScalarTypeNodeUPtr = std::unique_ptr<NAScalarTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_NA_SCALAR_TYPE_NODE_HPP */
