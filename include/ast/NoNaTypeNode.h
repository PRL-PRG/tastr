#ifndef TASTR_AST_NO_NA_TYPE_H
#define TASTR_AST_NO_NA_TYPE_H

#include "CompositeTypeNode.h"
#include "VectorTypeNode.h"

#include <memory>

namespace tastr::ast {

class NoNaTypeNode final: public CompositeTypeNode {
  public:
    NoNaTypeNode(std::unique_ptr<VectorTypeNode> inner_type)
        : CompositeTypeNode(), inner_type_(std::move(inner_type)) {
    }

    ~NoNaTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::VectorTypeNode& get_inner_type() const {
        return *inner_type_.get();
    }

  private:
    std::unique_ptr<tastr::ast::VectorTypeNode> inner_type_;
};

using NoNaTypeNodePtr = NoNaTypeNode*;
using NoNaTypeNodeUPtr = std::unique_ptr<NoNaTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_NO_NA_TYPE_H */
