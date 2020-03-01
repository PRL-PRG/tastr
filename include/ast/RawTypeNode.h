#ifndef TASTR_AST_RAW_TYPE_H
#define TASTR_AST_RAW_TYPE_H

#include "ScalarTypeNode.h"

namespace tastr::ast {

class RawTypeNode final: public ScalarTypeNode {
  public:
    RawTypeNode(): ScalarTypeNode() {
    }

    RawTypeNode(const RawTypeNode& node): ScalarTypeNode(node) {
    }

    ~RawTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<RawTypeNode> clone() const {
        return std::unique_ptr<RawTypeNode>(this->clone_impl());
    }

  private:
    virtual RawTypeNode* clone_impl() const override final {
        return new RawTypeNode(*this);
    };
};

using RawTypeNodePtr = RawTypeNode*;
using RawTypeNodeUPtr = std::unique_ptr<RawTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_RAW_TYPE_H */
