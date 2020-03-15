#ifndef TASTR_AST_FUNCTION_TYPE_NODE_HPP
#define TASTR_AST_FUNCTION_TYPE_NODE_HPP

#include "ast/Operator.hpp"
#include "ast/TypeNode.hpp"
#include "ast/TypeNodeSequenceNode.hpp"

namespace tastr::ast {

class FunctionTypeNode final: public TypeNode {
  public:
    FunctionTypeNode(const Operator& op,
                     TypeNodeSequenceNodeUPtr parameter_types,
                     std::unique_ptr<TypeNode> return_type)
        : TypeNode()
        , op_(op)
        , parameter_types_(std::move(parameter_types))
        , return_type_(std::move(return_type)) {
    }

    ~FunctionTypeNode() = default;

    FunctionTypeNode(const FunctionTypeNode& node)
        : TypeNode(node)
        , op_(node.op_)
        , parameter_types_(node.parameter_types_->clone())
        , return_type_(node.return_type_->clone()) {
    }

    FunctionTypeNode(FunctionTypeNode&& node)
        : TypeNode(std::move(node))
        , op_(std::move(node.op_))
        , parameter_types_(std::move(node.parameter_types_))
        , return_type_(std::move(node.return_type_)) {
    }

    FunctionTypeNode& operator=(const FunctionTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        op_ = node.op_;
        parameter_types_ = node.parameter_types_->clone();
        return_type_ = node.return_type_->clone();
        return *this;
    }

    FunctionTypeNode& operator=(FunctionTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        op_ = std::move(node.op_);
        parameter_types_ = std::move(node.parameter_types_);
        return_type_ = std::move(node.return_type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<FunctionTypeNode> clone() const {
        return std::unique_ptr<FunctionTypeNode>(this->clone_impl());
    }

    const Operator& get_operator() const {
        return op_;
    }

    const TypeNodeSequenceNode& get_parameter_types() const {
        return *parameter_types_.get();
    }

    const tastr::ast::TypeNode& get_return_type() const {
        return *return_type_.get();
    }

    bool is_function_type_node() const override final {
        return true;
    }

  private:
    virtual FunctionTypeNode* clone_impl() const override final {
        return new FunctionTypeNode(*this);
    };

    Operator op_;
    TypeNodeSequenceNodeUPtr parameter_types_;
    std::unique_ptr<TypeNode> return_type_;
};

using FunctionTypeNodePtr = FunctionTypeNode*;
using FunctionTypeNodeUPtr = std::unique_ptr<FunctionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_FUNCTION_TYPE_NODE_HPP */
