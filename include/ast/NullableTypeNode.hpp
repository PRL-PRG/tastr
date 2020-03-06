#ifndef TASTR_AST_NULLABLE_TYPE_NODE_HPP
#define TASTR_AST_NULLABLE_TYPE_NODE_HPP

#include "TypeNode.hpp"

#include <memory>

namespace tastr::ast {

class NullableTypeNode final: public TypeNode {
  public:
    explicit NullableTypeNode(std::unique_ptr<TypeNode> inner_type)
        : TypeNode(), inner_type_(std::move(inner_type)) {
    }

    ~NullableTypeNode() = default;

    NullableTypeNode(const NullableTypeNode& node)
        : TypeNode(node), inner_type_(node.inner_type_->clone()) {
    }

    NullableTypeNode(NullableTypeNode&& node)
        : TypeNode(std::move(node)), inner_type_(std::move(node.inner_type_)) {
    }

    NullableTypeNode& operator=(const NullableTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        inner_type_ = node.inner_type_->clone();
        return *this;
    }

    NullableTypeNode& operator=(NullableTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        inner_type_ = std::move(node.inner_type_);
        return *this;
    }

    void accept(tastr::visitor::ConstVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableVisitor& visitor) override final;

    const tastr::ast::TypeNode& get_inner_type() const {
        return *inner_type_.get();
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

    std::unique_ptr<TypeNode> inner_type_;
};

using NullableTypeNodePtr = NullableTypeNode*;
using NullableTypeNodeUPtr = std::unique_ptr<NullableTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NULLABLE_TYPE_NODE_HPP */
