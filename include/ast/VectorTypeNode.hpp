#ifndef TASTR_AST_VECTOR_TYPE_NODE_HPP
#define TASTR_AST_VECTOR_TYPE_NODE_HPP

#include "ast/OperatorNode.hpp"
#include "ScalarTypeNode.hpp"
#include "TypeNode.hpp"

#include <memory>

namespace tastr::ast {

class VectorTypeNode final: public TypeNode {
  public:
    explicit VectorTypeNode(const OperatorNode& op,
                            std::unique_ptr<ScalarTypeNode> scalar_type)
        : TypeNode(), op_(op), scalar_type_(std::move(scalar_type)) {
    }

    ~VectorTypeNode() = default;

    VectorTypeNode(const VectorTypeNode& node)
        : TypeNode(node)
        , op_(node.op_)
        , scalar_type_(node.scalar_type_->clone()) {
    }

    VectorTypeNode(VectorTypeNode&& node)
        : TypeNode(std::move(node))
        , op_(std::move(node.op_))
        , scalar_type_(std::move(node.scalar_type_)) {
    }

    VectorTypeNode& operator=(const VectorTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        op_ = node.op_;
        scalar_type_ = node.scalar_type_->clone();
        return *this;
    }

    VectorTypeNode& operator=(VectorTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        op_ = std::move(node.op_);
        scalar_type_ = std::move(node.scalar_type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<VectorTypeNode> clone() const {
        return std::unique_ptr<VectorTypeNode>(this->clone_impl());
    }

    const OperatorNode& get_operator() const {
        return op_;
    }

    const tastr::ast::ScalarTypeNode& get_scalar_type() const {
        return *scalar_type_.get();
    }

    bool is_vector_type_node() const override final {
        return true;
    }

  private:
    virtual VectorTypeNode* clone_impl() const override final {
        return new VectorTypeNode(*this);
    }

    std::unique_ptr<ScalarTypeNode> scalar_type_;
    OperatorNode op_;
};

using VectorTypeNodePtr = VectorTypeNode*;
using VectorTypeNodeUPtr = std::unique_ptr<VectorTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_VECTOR_TYPE_NODE_HPP */
