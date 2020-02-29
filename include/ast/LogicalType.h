#ifndef TASTR_AST_LOGICAL_TYPE_H
#define TASTR_AST_LOGICAL_TYPE_H

#include "ScalarType.h"

namespace tastr::ast {

class LogicalType final: public ScalarType {
  public:
    LogicalType(): ScalarType() {
    }

    ~LogicalType() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using LogicalTypePtr = LogicalType*;
using LogicalTypeUPtr = std::unique_ptr<LogicalType>;

} // namespace tastr::ast

#endif /* TASTR_AST_LOGICAL_TYPE_H */
