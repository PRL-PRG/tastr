#ifndef TASTR_AST_NODE_LOGICAL_TYPE_H
#define TASTR_AST_NODE_LOGICAL_TYPE_H

#include "ScalarType.h"

namespace tastr::ast::node {

class LogicalType final: public ScalarType {
  public:
    LogicalType(): ScalarType() {
    }

    ~LogicalType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using LogicalTypePtr = LogicalType*;
using LogicalTypeUPtr = std::unique_ptr<LogicalType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_LOGICAL_TYPE_H */
