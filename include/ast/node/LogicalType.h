#ifndef R_TYPE_AST_NODE_LOGICAL_TYPE_H
#define R_TYPE_AST_NODE_LOGICAL_TYPE_H

#include "ScalarType.h"

namespace rtype::ast::node {

class LogicalType: public ScalarType {
  public:
    LogicalType(): ScalarType() {
    }

    ~LogicalType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;
};

using LogicalTypePtr = LogicalType*;
using LogicalTypeUPtr = std::unique_ptr<LogicalType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_LOGICAL_TYPE_H */
