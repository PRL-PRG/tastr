#ifndef TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP
#define TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP

#include "TypeNode.hpp"

namespace tastr::ast {

class EnvironmentTypeNode final: public TypeNode {
  public:
    explicit EnvironmentTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~EnvironmentTypeNode() = default;

    EnvironmentTypeNode(const EnvironmentTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    EnvironmentTypeNode(EnvironmentTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    EnvironmentTypeNode& operator=(const EnvironmentTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    EnvironmentTypeNode& operator=(EnvironmentTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<EnvironmentTypeNode> clone() const {
        return std::unique_ptr<EnvironmentTypeNode>(this->clone_impl());
    }

    bool is_environment_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual EnvironmentTypeNode* clone_impl() const override final {
        return new EnvironmentTypeNode(*this);
    };

    std::string identifier_;
};

using EnvironmentTypeNodePtr = EnvironmentTypeNode*;
using EnvironmentTypeNodeUPtr = std::unique_ptr<EnvironmentTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_ENVIRONMENT_TYPE_NODE_HPP */
