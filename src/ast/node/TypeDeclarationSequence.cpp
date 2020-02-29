#include "ast/node/TypeDeclarationSequence.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::TypeDeclarationSequence::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
