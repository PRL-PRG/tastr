#ifndef TASTR_AST_RAW_TYPE_H
#define TASTR_AST_RAW_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class RawTypeNode final: public ScalarTypeNode {
  public:
    RawTypeNode(): ScalarTypeNode() {
    }

    ~RawTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;
};

using RawTypeNodePtr = RawTypeNode*;
using RawTypeNodeUPtr = std::unique_ptr<RawTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_RAW_TYPE_H */
