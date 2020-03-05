#ifndef TASTR_AST_S4_TYPE_NODE_H
#define TASTR_AST_S4_TYPE_NODE_H

#include "TypeNode.hpp"

namespace tastr::ast {

class S4TypeNode final: public TypeNode {
  public:
    explicit S4TypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~S4TypeNode() = default;

    S4TypeNode(const S4TypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    S4TypeNode(S4TypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    S4TypeNode& operator=(const S4TypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    S4TypeNode& operator=(S4TypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<S4TypeNode> clone() const {
        return std::unique_ptr<S4TypeNode>(this->clone_impl());
    }

    bool is_s4_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual S4TypeNode* clone_impl() const override final {
        return new S4TypeNode(*this);
    };

    std::string identifier_;
};

using S4TypeNodePtr = S4TypeNode*;
using S4TypeNodeUPtr = std::unique_ptr<S4TypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_S4_TYPE_NODE_H */
