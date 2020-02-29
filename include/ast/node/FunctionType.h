#ifndef TASTR_AST_NODE_FUNCTION_TYPE_H
#define TASTR_AST_NODE_FUNCTION_TYPE_H

#include "CompositeType.h"
#include "ParameterType.h"

namespace tastr::ast::node {

class FunctionType final: public CompositeType {
  public:
    FunctionType(std::unique_ptr<ParameterType> parameter_types,
                 std::unique_ptr<Type> return_type)
        : CompositeType()
        , parameter_types_(std::move(parameter_types))
        , return_type_(std::move(return_type)) {
    }

    ~FunctionType() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;

    const tastr::ast::node::ParameterType& get_parameter_types() const {
        return *parameter_types_.get();
    }

    const tastr::ast::node::Type& get_return_type() const {
        return *return_type_.get();
    }

  private:
    std::unique_ptr<ParameterType> parameter_types_;
    std::unique_ptr<Type> return_type_;
};

using FunctionTypePtr = FunctionType*;
using FunctionTypeUPtr = std::unique_ptr<FunctionType>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_FUNCTION_TYPE_H */
