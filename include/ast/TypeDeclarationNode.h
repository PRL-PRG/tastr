#ifndef TASTR_AST_TYPE_DECLARATION_H
#define TASTR_AST_TYPE_DECLARATION_H

#include "ast/IdentifierNode.h"
#include "ast/TypeNode.h"

#include <memory>
#include <string>

namespace tastr::ast {

class TypeDeclarationNode final: public Node {
  public:
    explicit TypeDeclarationNode(std::unique_ptr<IdentifierNode> identifier,
                             std::unique_ptr<TypeNode> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    ~TypeDeclarationNode() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::IdentifierNode& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::TypeNode& get_type() const {
        return *type_.get();
    }

  private:
    std::unique_ptr<IdentifierNode> identifier_;
    std::unique_ptr<TypeNode> type_;
};

using TypeDeclarationNodePtr = TypeDeclarationNode*;
using TypeDeclarationNodeUPtr = std::unique_ptr<TypeDeclarationNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_H */
