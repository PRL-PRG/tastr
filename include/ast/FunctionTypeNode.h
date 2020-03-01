#ifndef TASTR_AST_FUNCTION_TYPE_H
#define TASTR_AST_FUNCTION_TYPE_H

#include "CompositeTypeNode.h"
#include "Sequence.h"

namespace tastr::ast {

class FunctionTypeNode final: public CompositeTypeNode {
  public:
    FunctionTypeNode(TypeNodeSequenceUPtr parameter_types,
                     std::unique_ptr<TypeNode> return_type)
        : CompositeTypeNode()
        , parameter_types_(std::move(parameter_types))
        , return_type_(std::move(return_type)) {
    }

    ~FunctionTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::Sequence<TypeNode>& get_parameter_types() const {
        return *parameter_types_.get();
    }

    const tastr::ast::TypeNode& get_return_type() const {
        return *return_type_.get();
    }

  private:
    TypeNodeSequenceUPtr parameter_types_;
    std::unique_ptr<TypeNode> return_type_;
};

using FunctionTypeNodePtr = FunctionTypeNode*;
using FunctionTypeNodeUPtr = std::unique_ptr<FunctionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_FUNCTION_TYPE_H */
