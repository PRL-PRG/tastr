#ifndef R_TYPE_AST_NODE_TYPE_DECLARATION_H
#define R_TYPE_AST_NODE_TYPE_DECLARATION_H

#include "ast/node/Type.h"

#include <memory>
#include <string>

namespace rtype::ast::node {

class TypeDeclaration: public Node {
  public:
    explicit TypeDeclaration(const std::string& identifer,
                             std::unique_ptr<Type> type)
        : Node(), identifer_(identifer), type_(std::move(type)) {
    }

    ~TypeDeclaration() {
    }

    void accept(rtype::ast::visitor::Visitor& visitor) const override;

    const std::string& get_identifier() const {
        return identifer_;
    }

    const rtype::ast::node::Type& get_type() const {
        return *type_.get();
    }

  private:
    std::string identifer_;
    std::unique_ptr<Type> type_;
};

using TypeDeclarationPtr = TypeDeclaration*;
using TypeDeclarationUPtr = std::unique_ptr<TypeDeclaration>;

} // namespace rtype::ast::node

#endif /* R_TYPE_AST_NODE_TYPE_DECLARATION_H */
