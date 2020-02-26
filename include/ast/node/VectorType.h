#ifndef R_TYPE_AST_NODE_VECTOR_TYPE_H
#define R_TYPE_AST_NODE_VECTOR_TYPE_H

#include "CompositeType.h"
#include "ScalarType.h"
#include <memory>

namespace rtype::ast::node {

class VectorType: public CompositeType {
  public:
    VectorType(std::unique_ptr<ScalarType> scalar_type)
        : CompositeType(), scalar_type_(std::move(scalar_type)) {
    }

    ~VectorType() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override;

    const rtype::ast::node::ScalarType& get_scalar_type() const {
        return *scalar_type_.get();
    }

  private:
    std::unique_ptr<ScalarType> scalar_type_;
};

using VectorTypePtr = VectorType*;
using VectorTypeUPtr = std::unique_ptr<VectorType>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_VECTOR_TYPE_H */
