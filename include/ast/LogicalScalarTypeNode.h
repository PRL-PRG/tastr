#ifndef TASTR_AST_LOGICAL_TYPE_H
#define TASTR_AST_LOGICAL_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class LogicalScalarTypeNode final: public ScalarTypeNode {
  public:
    LogicalScalarTypeNode(const std::string& identifier)
        : ScalarTypeNode(identifier) {
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

    void accept(tastr::visitor::Visitor& visitor) const override final;

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

#endif /* TASTR_AST_LOGICAL_TYPE_H */
