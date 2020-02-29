#include "ast/node/TypeDeclaration.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::TypeDeclaration::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
