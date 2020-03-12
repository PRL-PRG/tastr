#ifndef TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP

#include "AScalarTypeNode.hpp"

namespace tastr::ast {

class LogicalAScalarTypeNode final: public AScalarTypeNode {
  public:
    explicit LogicalAScalarTypeNode(const std::string& name)
        : AScalarTypeNode(name) {
    }

    ~LogicalAScalarTypeNode() = default;

    LogicalAScalarTypeNode(const LogicalAScalarTypeNode& node)
        : AScalarTypeNode(node) {
    }

    LogicalAScalarTypeNode(LogicalAScalarTypeNode&& node)
        : AScalarTypeNode(std::move(node)) {
    }

    LogicalAScalarTypeNode& operator=(const LogicalAScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        AScalarTypeNode::operator=(node);
        return *this;
    }

    LogicalAScalarTypeNode& operator=(LogicalAScalarTypeNode&& node) {
        AScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<LogicalAScalarTypeNode> clone() const {
        return std::unique_ptr<LogicalAScalarTypeNode>(this->clone_impl());
    }

    bool is_logical_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual LogicalAScalarTypeNode* clone_impl() const override final {
        return new LogicalAScalarTypeNode(*this);
    };
};

using LogicalAScalarTypeNodePtr = LogicalAScalarTypeNode*;
using LogicalAScalarTypeNodeUPtr = std::unique_ptr<LogicalAScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP */
