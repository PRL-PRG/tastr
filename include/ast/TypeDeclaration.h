#ifndef TASTR_AST_TYPE_DECLARATION_H
#define TASTR_AST_TYPE_DECLARATION_H

#include "ast/Identifier.h"
#include "ast/Type.h"

#include <memory>
#include <string>

namespace tastr::ast {

class TypeDeclaration final: public Node {
  public:
    explicit TypeDeclaration(std::unique_ptr<Identifier> identifier,
                             std::unique_ptr<Type> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    ~TypeDeclaration() {
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    const tastr::ast::Identifier& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::Type& get_type() const {
        return *type_.get();
    }

  private:
    std::unique_ptr<Identifier> identifier_;
    std::unique_ptr<Type> type_;
};

using TypeDeclarationPtr = TypeDeclaration*;
using TypeDeclarationUPtr = std::unique_ptr<TypeDeclaration>;

} // namespace tastr::ast

#endif /* TASTR_AST_TYPE_DECLARATION_H */
