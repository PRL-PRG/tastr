#ifndef TASTR_AST_VECTOR_TYPE_H
#define TASTR_AST_VECTOR_TYPE_H

#include "CompositeTypeNode.h"
#include "ScalarTypeNode.h"
#include <memory>

namespace tastr::ast {

class VectorTypeNode: public CompositeTypeNode {
  public:
    VectorTypeNode(std::unique_ptr<ScalarTypeNode> scalar_type)
        : CompositeTypeNode(), scalar_type_(std::move(scalar_type)) {
    }

    ~VectorTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override;

    const tastr::ast::ScalarTypeNode& get_scalar_type() const {
        return *scalar_type_.get();
    }

  private:
    std::unique_ptr<ScalarTypeNode> scalar_type_;
};

using VectorTypeNodePtr = VectorTypeNode*;
using VectorTypeNodeUPtr = std::unique_ptr<VectorTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_VECTOR_TYPE_H */
