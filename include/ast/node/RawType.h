#ifndef TASTR_AST_NODE_RAW_TYPE_H
#define TASTR_AST_NODE_RAW_TYPE_H

#include "ScalarType.h"

namespace tastr::ast::node {

class RawType final: public ScalarType {
  public:
    RawType(): ScalarType() {
    }

    ~RawType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;
};

using RawTypePtr = RawType*;
using RawTypeUPtr = std::unique_ptr<RawType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_RAW_TYPE_H */
