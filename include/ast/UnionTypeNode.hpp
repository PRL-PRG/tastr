#ifndef TASTR_AST_UNION_TYPE_NODE_HPP
#define TASTR_AST_UNION_TYPE_NODE_HPP

#include "ast/OperatorNode.hpp"
#include "ast/TypeNode.hpp"

#include <memory>

namespace tastr::ast {

class UnionTypeNode final: public TypeNode {
  public:
    UnionTypeNode(const OperatorNode& op,
                  std::unique_ptr<TypeNode> first_type,
                  std::unique_ptr<TypeNode> second_type)
        : TypeNode()
        , op_(op)
        , first_type_(std::move(first_type))
        , second_type_(std::move(second_type)) {
    }

    ~UnionTypeNode() = default;

    UnionTypeNode(const UnionTypeNode& node)
        : TypeNode(node)
        , op_(node.op_)
        , first_type_(node.first_type_->clone())
        , second_type_(node.second_type_->clone()) {
    }

    UnionTypeNode(UnionTypeNode&& node)
        : TypeNode(std::move(node))
        , op_(std::move(node.op_))
        , first_type_(std::move(node.first_type_))
        , second_type_(std::move(node.second_type_)) {
    }

    UnionTypeNode& operator=(const UnionTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        op_ = node.op_;
        first_type_ = node.first_type_->clone();
        second_type_ = node.second_type_->clone();
        return *this;
    }

    UnionTypeNode& operator=(UnionTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        op_ = std::move(node.op_);
        first_type_ = std::move(node.first_type_);
        second_type_ = std::move(node.second_type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<UnionTypeNode> clone() const {
        return std::unique_ptr<UnionTypeNode>(this->clone_impl());
    }

    const OperatorNode& get_operator() const {
        return op_;
    }

    const tastr::ast::TypeNode& get_first_type() const {
        return *first_type_.get();
    }

    const tastr::ast::TypeNode& get_second_type() const {
        return *second_type_.get();
    }

    bool is_union_type_node() const override final {
        return true;
    }

  private:
    virtual UnionTypeNode* clone_impl() const override final {
        return new UnionTypeNode(*this);
    }

    OperatorNode op_;
    std::unique_ptr<TypeNode> first_type_;
    std::unique_ptr<TypeNode> second_type_;
};

using UnionTypeNodePtr = UnionTypeNode*;
using UnionTypeNodeUPtr = std::unique_ptr<UnionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_UNION_TYPE_NODE_HPP */
