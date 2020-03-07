#ifndef TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_HPP
#define TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_HPP

#include "ast/Name.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class ExternalPointerTypeNode final
    : public TypeNode
    , public Name {
  public:
    explicit ExternalPointerTypeNode(const std::string& name)
        : TypeNode(), Name(name) {
    }

    ~ExternalPointerTypeNode() = default;

    ExternalPointerTypeNode(const ExternalPointerTypeNode& node)
        : TypeNode(node), Name(node) {
    }

    ExternalPointerTypeNode(ExternalPointerTypeNode&& node)
        : TypeNode(std::move(node)), Name(std::move(node)) {
    }

    ExternalPointerTypeNode& operator=(const ExternalPointerTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        Name::operator=(node);
        return *this;
    }

    ExternalPointerTypeNode& operator=(ExternalPointerTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        Name::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ExternalPointerTypeNode> clone() const {
        return std::unique_ptr<ExternalPointerTypeNode>(this->clone_impl());
    }

    bool is_external_pointer_type_node() const override final {
        return true;
    }

  private:
    virtual ExternalPointerTypeNode* clone_impl() const override final {
        return new ExternalPointerTypeNode(*this);
    };
};

using ExternalPointerTypeNodePtr = ExternalPointerTypeNode*;
using ExternalPointerTypeNodeUPtr = std::unique_ptr<ExternalPointerTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_EXTERNAL_POINTER_TYPE_NODE_HPP */
