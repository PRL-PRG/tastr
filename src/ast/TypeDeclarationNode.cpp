#include "ast/TypeDeclarationNode.h"

#include "visitor/Visitor.h"

void tastr::ast::TypeDeclarationNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
