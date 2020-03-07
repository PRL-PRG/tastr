#ifndef TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP
#define TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP

#include "ScalarTypeNode.hpp"

namespace tastr::ast {

class LogicalScalarTypeNode final: public ScalarTypeNode {
  public:
    explicit LogicalScalarTypeNode(const std::string& name)
        : ScalarTypeNode(name) {
    }

    ~LogicalScalarTypeNode() = default;

    LogicalScalarTypeNode(const LogicalScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    LogicalScalarTypeNode(LogicalScalarTypeNode&& node)
        : ScalarTypeNode(std::move(node)) {
    }

    LogicalScalarTypeNode& operator=(const LogicalScalarTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        ScalarTypeNode::operator=(node);
        return *this;
    }

    LogicalScalarTypeNode& operator=(LogicalScalarTypeNode&& node) {
        ScalarTypeNode::operator=(std::move(node));
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<LogicalScalarTypeNode> clone() const {
        return std::unique_ptr<LogicalScalarTypeNode>(this->clone_impl());
    }

    bool is_logical_scalar_type_node() const override final {
        return true;
    }

  private:
    virtual LogicalScalarTypeNode* clone_impl() const override final {
        return new LogicalScalarTypeNode(*this);
    };
};

using LogicalScalarTypeNodePtr = LogicalScalarTypeNode*;
using LogicalScalarTypeNodeUPtr = std::unique_ptr<LogicalScalarTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LOGICAL_SCALAR_TYPE_NODE_HPP */
