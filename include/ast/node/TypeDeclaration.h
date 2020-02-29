#ifndef R_TYPE_AST_NODE_TYPE_DECLARATION_H
#define R_TYPE_AST_NODE_TYPE_DECLARATION_H

#include "ast/node/Identifier.h"
#include "ast/node/Type.h"

#include <memory>
#include <string>

namespace rtype::ast::node {

class TypeDeclaration final: public Node {
  public:
    explicit TypeDeclaration(std::unique_ptr<Identifier> identifier,
                             std::unique_ptr<Type> type)
        : Node(), identifier_(std::move(identifier)), type_(std::move(type)) {
    }

    ~TypeDeclaration() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override final;

    const rtype::ast::node::Identifier& get_identifier() const {
        return *identifier_.get();
    }

    const rtype::ast::node::Type& get_type() const {
        return *type_.get();
    }

  private:
    std::unique_ptr<Identifier> identifier_;
    std::unique_ptr<Type> type_;
};

using TypeDeclarationPtr = TypeDeclaration*;
using TypeDeclarationUPtr = std::unique_ptr<TypeDeclaration>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_TYPE_DECLARATION_H */
