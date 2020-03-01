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

    VectorTypeNode(const VectorTypeNode& node)
        : CompositeTypeNode(node)
        , scalar_type_(node.get_scalar_type().clone()) {
    }

    void accept(tastr::visitor::Visitor& visitor) const override;

    std::unique_ptr<VectorTypeNode> clone() const {
        return std::unique_ptr<VectorTypeNode>(this->clone_impl());
    }

    const tastr::ast::ScalarTypeNode& get_scalar_type() const {
        return *scalar_type_.get();
    }

    bool is_vector_type_node() const override final {
        return true;
    }

  private:
    virtual VectorTypeNode* clone_impl() const override final {
        return new VectorTypeNode(*this);
    }

    std::unique_ptr<ScalarTypeNode> scalar_type_;
};

using VectorTypeNodePtr = VectorTypeNode*;
using VectorTypeNodeUPtr = std::unique_ptr<VectorTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_VECTOR_TYPE_H */
