#ifndef TASTR_AST_UNION_TYPE_H
#define TASTR_AST_UNION_TYPE_H

#include "CompositeTypeNode.h"
#include <memory>

namespace tastr::ast {

class UnionTypeNode final: public CompositeTypeNode {
  public:
    UnionTypeNode(std::unique_ptr<TypeNode> first_type,
              std::unique_ptr<TypeNode> second_type)
        : CompositeTypeNode()
        , first_type_(std::move(first_type))
        , second_type_(std::move(second_type)) {
    }

    ~UnionTypeNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::TypeNode& get_first_type() const {
        return *first_type_.get();
    }

    const tastr::ast::TypeNode& get_second_type() const {
        return *second_type_.get();
    }

  private:
    std::unique_ptr<TypeNode> first_type_;
    std::unique_ptr<TypeNode> second_type_;
};

using UnionTypeNodePtr = UnionTypeNode*;
using UnionTypeNodeUPtr = std::unique_ptr<UnionTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_UNION_TYPE_H */
