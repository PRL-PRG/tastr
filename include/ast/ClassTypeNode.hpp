#ifndef TASTR_AST_CLASS_TYPE_NODE_HPP
#define TASTR_AST_CLASS_TYPE_NODE_HPP

#include "ast/IdentifierNode.hpp"
#include "ast/OperatorNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class ClassTypeNode final: public TypeNode {
  public:
    explicit ClassTypeNode(OperatorNodeUPtr op, IdentifierNodeUPtr identifier)
        : TypeNode(), op_(std::move(op)), identifier_(std::move(identifier)) {
    }

    ~ClassTypeNode() = default;

    ClassTypeNode(const ClassTypeNode& node)
        : TypeNode(node)
        , op_(node.op_->clone())
        , identifier_(node.identifier_->clone()) {
    }

    ClassTypeNode(ClassTypeNode&& node)
        : TypeNode(std::move(node))
        , op_(std::move(node.op_))
        , identifier_(std::move(node.identifier_)) {
    }

    ClassTypeNode& operator=(const ClassTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        op_ = node.op_->clone();
        identifier_ = node.identifier_->clone();
        return *this;
    }

    ClassTypeNode& operator=(ClassTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        op_ = std::move(node.op_);
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ClassTypeNode> clone() const {
        return std::unique_ptr<ClassTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const OperatorNode& get_operator() const {
        return *op_.get();
    }

    const IdentifierNode& get_identifier() const {
        return *identifier_.get();
    }

  private:
    virtual ClassTypeNode* clone_impl() const override final {
        return new ClassTypeNode(*this);
    };

    OperatorNodeUPtr op_;
    IdentifierNodeUPtr identifier_;

    static const Kind kind_;
};

using ClassTypeNodePtr = ClassTypeNode*;
using ClassTypeNodeUPtr = std::unique_ptr<ClassTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_CLASS_TYPE_NODE_HPP */
