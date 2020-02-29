#include "ast/TypeDeclarationSequenceNode.h"

#include "visitor/Visitor.h"

void tastr::ast::TypeDeclarationSequenceNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
