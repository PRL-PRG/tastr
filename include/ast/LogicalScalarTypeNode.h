#ifndef TASTR_AST_LOGICAL_TYPE_H
#define TASTR_AST_LOGICAL_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class LogicalScalarTypeNode final: public ScalarTypeNode {
  public:
    LogicalScalarTypeNode(): ScalarTypeNode() {
    }

    LogicalScalarTypeNode(const LogicalScalarTypeNode& node)
        : ScalarTypeNode(node) {
    }

    ~LogicalScalarTypeNode() {
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
