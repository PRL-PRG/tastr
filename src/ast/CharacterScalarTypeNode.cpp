#include "ast/CharacterScalarTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::CharacterScalarTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
