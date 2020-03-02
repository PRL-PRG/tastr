#include "ast/TypeDeclarationNodeSequenceNode.h"

#include "visitor/Visitor.h"

void tastr::ast::TypeDeclarationNodeSequenceNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
