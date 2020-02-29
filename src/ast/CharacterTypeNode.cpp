#include "ast/CharacterTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::CharacterTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
