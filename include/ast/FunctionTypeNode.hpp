#ifndef TASTR_AST_FUNCTION_TYPE_NODE_HPP
#define TASTR_AST_FUNCTION_TYPE_NODE_HPP

#include "ast/OperatorNode.hpp"
#include "ast/ParameterNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class FunctionTypeNode final: public TypeNode {
  public:
    FunctionTypeNode(OperatorNodeUPtr op,
                     ParameterNodeUPtr parameter,
                     TypeNodeUPtr return_type)
        : TypeNode()
        , op_(std::move(op))
        , parameter_(std::move(parameter))
        , return_type_(std::move(return_type)) {
    }

    ~FunctionTypeNode() = default;

    FunctionTypeNode(const FunctionTypeNode& node)
        : TypeNode(node)
        , op_(node.op_->clone())
        , parameter_(node.parameter_->clone())
        , return_type_(node.return_type_->clone()) {
    }

    FunctionTypeNode(FunctionTypeNode&& node)
        : TypeNode(std::move(node))
        , op_(std::move(node.op_))
        , parameter_(std::move(node.parameter_))
        , return_type_(std::move(node.return_type_)) {
    }

    FunctionTypeNode& operator=(const FunctionTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        op_ = node.op_->clone();
        parameter_ = node.parameter_->clone();
        return_type_ = node.return_type_->clone();
        return *this;
    }

    FunctionTypeNode& operator=(FunctionTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        op_ = std::move(node.op_);
        parameter_ = std::move(node.parameter_);
        return_type_ = std::move(node.return_type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<FunctionTypeNode> clone() const {
        return std::unique_ptr<FunctionTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const OperatorNode& get_operator() const {
        return *op_.get();
    }

    const ParameterNode& get_parameter() const {
        return *parameter_.get();
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

    OperatorNodeUPtr op_;
    ParameterNodeUPtr parameter_;
    TypeNodeUPtr return_type_;

    static const Kind kind_;
};

using FunctionTypeNodePtr = FunctionTypeNode*;
using FunctionTypeNodeUPtr = std::unique_ptr<FunctionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_FUNCTION_TYPE_NODE_HPP */
