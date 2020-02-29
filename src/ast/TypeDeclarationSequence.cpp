#include "ast/TypeDeclarationSequence.h"

#include "visitor/Visitor.h"

void tastr::ast::TypeDeclarationSequence::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
