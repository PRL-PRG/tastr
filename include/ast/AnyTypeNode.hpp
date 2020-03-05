#ifndef TASTR_AST_ANY_TYPE_NODE_H
#define TASTR_AST_ANY_TYPE_NODE_H

#include "TypeNode.hpp"

namespace tastr::ast {

class AnyTypeNode final: public TypeNode {
  public:
    explicit AnyTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~AnyTypeNode() = default;

    AnyTypeNode(const AnyTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    AnyTypeNode(AnyTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    AnyTypeNode& operator=(const AnyTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    AnyTypeNode& operator=(AnyTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<AnyTypeNode> clone() const {
        return std::unique_ptr<AnyTypeNode>(this->clone_impl());
    }

    bool is_any_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual AnyTypeNode* clone_impl() const override final {
        return new AnyTypeNode(*this);
    };

    std::string identifier_;
};

using AnyTypeNodePtr = AnyTypeNode*;
using AnyTypeNodeUPtr = std::unique_ptr<AnyTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_ANY_TYPE_NODE_H */
