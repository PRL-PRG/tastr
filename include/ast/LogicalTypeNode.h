#ifndef TASTR_AST_LOGICAL_TYPE_H
#define TASTR_AST_LOGICAL_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class LogicalTypeNode final: public ScalarTypeNode {
  public:
    LogicalTypeNode(): ScalarTypeNode() {
    }

    LogicalTypeNode(const LogicalTypeNode& node): ScalarTypeNode(node) {
    }

    ~LogicalTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<LogicalTypeNode> clone() const {
        return std::unique_ptr<LogicalTypeNode>(this->clone_impl());
    }

  private:
    virtual LogicalTypeNode* clone_impl() const override final {
        return new LogicalTypeNode(*this);
    };
};

using LogicalTypeNodePtr = LogicalTypeNode*;
using LogicalTypeNodeUPtr = std::unique_ptr<LogicalTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LOGICAL_TYPE_H */
