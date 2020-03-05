#ifndef TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_H
#define TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_H

#include "TypeNode.hpp"

namespace tastr::ast {

class ExternalPointerTypeNode final: public TypeNode {
  public:
    explicit ExternalPointerTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~ExternalPointerTypeNode() = default;

    ExternalPointerTypeNode(const ExternalPointerTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    ExternalPointerTypeNode(ExternalPointerTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    ExternalPointerTypeNode& operator=(const ExternalPointerTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    ExternalPointerTypeNode& operator=(ExternalPointerTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<ExternalPointerTypeNode> clone() const {
        return std::unique_ptr<ExternalPointerTypeNode>(this->clone_impl());
    }

    bool is_external_pointer_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual ExternalPointerTypeNode* clone_impl() const override final {
        return new ExternalPointerTypeNode(*this);
    };

    std::string identifier_;
};

using ExternalPointerTypeNodePtr = ExternalPointerTypeNode*;
using ExternalPointerTypeNodeUPtr = std::unique_ptr<ExternalPointerTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_H */
