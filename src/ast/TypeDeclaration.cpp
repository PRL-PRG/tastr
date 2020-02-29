#include "ast/TypeDeclaration.h"

#include "visitor/Visitor.h"

void tastr::ast::TypeDeclaration::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
