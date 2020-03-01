#ifndef TASTR_AST_FUNCTION_TYPE_H
#define TASTR_AST_FUNCTION_TYPE_H

#include "TypeNode.h"
#include "Sequence.h"

namespace tastr::ast {

class FunctionTypeNode final: public TypeNode {
  public:
    FunctionTypeNode(TypeNodeSequenceUPtr parameter_types,
                     std::unique_ptr<TypeNode> return_type)
        : TypeNode()
        , parameter_types_(std::move(parameter_types))
        , return_type_(std::move(return_type)) {
    }

    ~FunctionTypeNode() {
    }

    FunctionTypeNode(const FunctionTypeNode& node)
        : TypeNode(node)
        , parameter_types_(node.get_parameter_types().clone())
        , return_type_(node.get_return_type().clone()) {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<FunctionTypeNode> clone() const {
        return std::unique_ptr<FunctionTypeNode>(this->clone_impl());
    }

    const tastr::ast::Sequence<TypeNode>& get_parameter_types() const {
        return *parameter_types_.get();
    }

    const tastr::ast::TypeNode& get_return_type() const {
        return *return_type_.get();
    }

    bool is_function_type_node() const override final {
        return true;
    }

  private:
    virtual FunctionTypeNode* clone_impl() const override final {
        return new FunctionTypeNode(*this);
    };

    TypeNodeSequenceUPtr parameter_types_;
    std::unique_ptr<TypeNode> return_type_;
};

using FunctionTypeNodePtr = FunctionTypeNode*;
using FunctionTypeNodeUPtr = std::unique_ptr<FunctionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_FUNCTION_TYPE_H */
