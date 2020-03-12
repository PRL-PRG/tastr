#ifndef TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP
#define TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class WeakReferenceTypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit WeakReferenceTypeNode(const std::string& name)
        : TypeNode(), Name(name) {
    }

    ~WeakReferenceTypeNode() = default;

    WeakReferenceTypeNode(const WeakReferenceTypeNode& node)
        : TypeNode(node), Name(node) {
    }

    WeakReferenceTypeNode(WeakReferenceTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    WeakReferenceTypeNode& operator=(const WeakReferenceTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    WeakReferenceTypeNode& operator=(WeakReferenceTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<WeakReferenceTypeNode> clone() const {
        return std::unique_ptr<WeakReferenceTypeNode>(this->clone_impl());
    }

    bool is_weak_reference_type_node() const override final {
        return true;
    }

  private:
    virtual WeakReferenceTypeNode* clone_impl() const override final {
        return new WeakReferenceTypeNode(*this);
    };
};

using WeakReferenceTypeNodePtr = WeakReferenceTypeNode*;
using WeakReferenceTypeNodeUPtr = std::unique_ptr<WeakReferenceTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_WEAK_REFERENCE_TYPE_NODE_HPP */
