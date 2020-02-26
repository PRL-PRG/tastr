#ifndef R_TYPE_AST_NODE_RAW_TYPE_H
#define R_TYPE_AST_NODE_RAW_TYPE_H

#include "ScalarType.h"

namespace rtype::ast::node {

class RawType: public ScalarType {
  public:
    RawType(): ScalarType() {
    }

    ~RawType() {
    }

    void accept(rtype::ast::visitor::TypeVisitor& visitor) const override;
};

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_RAW_TYPE_H */
