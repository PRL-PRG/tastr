#ifndef TASTR_AST_INTERSECTION_TYPE_NODE_HPP
#define TASTR_AST_INTERSECTION_TYPE_NODE_HPP

#include "ast/OperatorNode.hpp"
#include "ast/TypeNode.hpp"

#include <memory>

namespace tastr {
namespace ast {

class IntersectionTypeNode final: public TypeNode {
  public:
    IntersectionTypeNode(OperatorNodeUPtr op,
                         std::unique_ptr<TypeNode> first_type,
                         std::unique_ptr<TypeNode> second_type)
        : TypeNode()
        , op_(std::move(op))
        , first_type_(std::move(first_type))
        , second_type_(std::move(second_type)) {
    }

    ~IntersectionTypeNode() = default;

    IntersectionTypeNode(const IntersectionTypeNode& node)
        : TypeNode(node)
        , op_(node.op_->clone())
        , first_type_(node.first_type_->clone())
        , second_type_(node.second_type_->clone()) {
    }

    IntersectionTypeNode(IntersectionTypeNode&& node)
        : TypeNode(std::move(node))
        , op_(std::move(node.op_))
        , first_type_(std::move(node.first_type_))
        , second_type_(std::move(node.second_type_)) {
    }

    IntersectionTypeNode& operator=(const IntersectionTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        op_ = node.op_->clone();
        first_type_ = node.first_type_->clone();
        second_type_ = node.second_type_->clone();
        return *this;
    }

    IntersectionTypeNode& operator=(IntersectionTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        op_ = std::move(node.op_);
        first_type_ = std::move(node.first_type_);
        second_type_ = std::move(node.second_type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<IntersectionTypeNode> clone() const {
        return std::unique_ptr<IntersectionTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const OperatorNode& get_operator() const {
        return *op_.get();
    }

    const tastr::ast::TypeNode& get_first_type() const {
        return *first_type_.get();
    }

    const tastr::ast::TypeNode& get_second_type() const {
        return *second_type_.get();
    }

  private:
    virtual IntersectionTypeNode* clone_impl() const override final {
        return new IntersectionTypeNode(*this);
    }

    OperatorNodeUPtr op_;
    std::unique_ptr<TypeNode> first_type_;
    std::unique_ptr<TypeNode> second_type_;

    static const Kind kind_;
};

using IntersectionTypeNodePtr = IntersectionTypeNode*;
using IntersectionTypeNodeUPtr = std::unique_ptr<IntersectionTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_INTERSECTION_TYPE_NODE_HPP */
