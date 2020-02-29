#ifndef TASTR_AST_NODE_TYPE_DECLARATION_H
#define TASTR_AST_NODE_TYPE_DECLARATION_H

#include "ast/node/Identifier.h"
#include "ast/node/Type.h"

#include <memory>
#include <string>

namespace tastr::ast::node {

class TypeDeclaration final: public Node {
  public:
    explicit TypeDeclaration(std::unique_ptr<Identifier> identifier,
                             std::unique_ptr<Type> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    ~TypeDeclaration() {
    }

    void accept(tastr::ast::visitor::Visitor& visitor) const override final;

    const tastr::ast::node::Identifier& get_identifier() const {
        return *identifier_.get();
    }

    const tastr::ast::node::Type& get_type() const {
        return *type_.get();
    }

  private:
    std::unique_ptr<Identifier> identifier_;
    std::unique_ptr<Type> type_;
};

using TypeDeclarationPtr = TypeDeclaration*;
using TypeDeclarationUPtr = std::unique_ptr<TypeDeclaration>;

} // namespace tastr::ast::node

#endif /* TASTR_AST_NODE_TYPE_DECLARATION_H */
