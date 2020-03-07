#ifndef TASTR_AST_NO_NA_TYPE_NODE_HPP
#define TASTR_AST_NO_NA_TYPE_NODE_HPP

#include "TypeNode.hpp"
#include "VectorTypeNode.hpp"

#include <memory>

namespace tastr::ast {

class NoNaTypeNode final: public TypeNode {
  public:
    explicit NoNaTypeNode(std::unique_ptr<VectorTypeNode> inner_type)
        : TypeNode(), inner_type_(std::move(inner_type)) {
    }

    ~NoNaTypeNode() = default;

    NoNaTypeNode(const NoNaTypeNode& node)
        : TypeNode(node), inner_type_(node.inner_type_->clone()) {
    }

    NoNaTypeNode(NoNaTypeNode&& node)
        : TypeNode(std::move(node)), inner_type_(std::move(node.inner_type_)) {
    }

    NoNaTypeNode& operator=(const NoNaTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        inner_type_ = node.inner_type_->clone();
        return *this;
    }

    NoNaTypeNode& operator=(NoNaTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        inner_type_ = std::move(node.inner_type_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    const tastr::ast::VectorTypeNode& get_inner_type() const {
        return *inner_type_.get();
    }

    std::unique_ptr<NoNaTypeNode> clone() const {
        return std::unique_ptr<NoNaTypeNode>(this->clone_impl());
    }

    bool is_no_na_type_node() const override final {
        return true;
    }

  private:
    virtual NoNaTypeNode* clone_impl() const override final {
        return new NoNaTypeNode(*this);
    };

    std::unique_ptr<tastr::ast::VectorTypeNode> inner_type_;
};

using NoNaTypeNodePtr = NoNaTypeNode*;
using NoNaTypeNodeUPtr = std::unique_ptr<NoNaTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NO_NA_TYPE_NODE_HPP */
