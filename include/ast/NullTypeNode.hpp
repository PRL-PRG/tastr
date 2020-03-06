#ifndef TASTR_AST_NULL_TYPE_NODE_HPP
#define TASTR_AST_NULL_TYPE_NODE_HPP

#include "TypeNode.hpp"

namespace tastr::ast {

class NullTypeNode final: public TypeNode {
  public:
    explicit NullTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~NullTypeNode() = default;

    NullTypeNode(const NullTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    NullTypeNode(NullTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    NullTypeNode& operator=(const NullTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    NullTypeNode& operator=(NullTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::ConstVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableVisitor& visitor) override final;

    std::unique_ptr<NullTypeNode> clone() const {
        return std::unique_ptr<NullTypeNode>(this->clone_impl());
    }

    bool is_null_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual NullTypeNode* clone_impl() const override final {
        return new NullTypeNode(*this);
    };

    std::string identifier_;
};

using NullTypeNodePtr = NullTypeNode*;
using NullTypeNodeUPtr = std::unique_ptr<NullTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NULL_TYPE_NODE_HPP */
