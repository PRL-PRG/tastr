#ifndef TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP
#define TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP

#include "TypeNode.hpp"

namespace tastr::ast {

class WeakReferenceTypeNode final: public TypeNode {
  public:
    explicit WeakReferenceTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~WeakReferenceTypeNode() = default;

    WeakReferenceTypeNode(const WeakReferenceTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    WeakReferenceTypeNode(WeakReferenceTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    WeakReferenceTypeNode& operator=(const WeakReferenceTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    WeakReferenceTypeNode& operator=(WeakReferenceTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<WeakReferenceTypeNode> clone() const {
        return std::unique_ptr<WeakReferenceTypeNode>(this->clone_impl());
    }

    bool is_bytecode_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual WeakReferenceTypeNode* clone_impl() const override final {
        return new WeakReferenceTypeNode(*this);
    };

    std::string identifier_;
};

using WeakReferenceTypeNodePtr = WeakReferenceTypeNode*;
using WeakReferenceTypeNodeUPtr = std::unique_ptr<WeakReferenceTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP */
