#ifndef TASTR_AST_NULLABLE_TYPE_NODE_HPP
#define TASTR_AST_NULLABLE_TYPE_NODE_HPP

#include "ast/Operator.hpp"
#include "ast/TypeNode.hpp"

#include <memory>

namespace tastr::ast {

class NullableTypeNode final: public TypeNode {
  public:
    explicit NullableTypeNode(const Operator& op,
                              std::unique_ptr<TypeNode> inner_type)
        : TypeNode(), op_(op), inner_type_(std::move(inner_type)) {
    }

    ~NullableTypeNode() = default;

    NullableTypeNode(const NullableTypeNode& node)
        : TypeNode(node)
        , op_(node.op_)
        , inner_type_(node.inner_type_->clone()) {
    }

    NullableTypeNode(NullableTypeNode&& node)
        : TypeNode(std::move(node))
        , op_(std::move(node.op_))
        , inner_type_(std::move(node.inner_type_)) {
    }

    NullableTypeNode& operator=(const NullableTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        op_ = node.op_;
        inner_type_ = node.inner_type_->clone();
        return *this;
    }

    NullableTypeNode& operator=(NullableTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        op_ = std::move(node.op_);
        inner_type_ = std::move(node.inner_type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    const tastr::ast::TypeNode& get_inner_type() const {
        return *inner_type_.get();
    }

    const Operator& get_operator() const {
        return op_;
    }

    std::unique_ptr<NullableTypeNode> clone() const {
        return std::unique_ptr<NullableTypeNode>(this->clone_impl());
    }

    bool is_nullable_type_node() const override final {
        return true;
    }

  private:
    virtual NullableTypeNode* clone_impl() const override final {
        return new NullableTypeNode(*this);
    };

    Operator op_;
    std::unique_ptr<TypeNode> inner_type_;
};

using NullableTypeNodePtr = NullableTypeNode*;
using NullableTypeNodeUPtr = std::unique_ptr<NullableTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NULLABLE_TYPE_NODE_HPP */
