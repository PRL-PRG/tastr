#ifndef TASTR_AST_LOGICAL_TYPE_H
#define TASTR_AST_LOGICAL_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class LogicalTypeNode final: public ScalarTypeNode {
  public:
    LogicalTypeNode(): ScalarTypeNode() {
    }

    ~LogicalTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using LogicalTypeNodePtr = LogicalTypeNode*;
using LogicalTypeNodeUPtr = std::unique_ptr<LogicalTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LOGICAL_TYPE_H */
