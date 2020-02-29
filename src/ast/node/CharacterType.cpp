#include "ast/node/CharacterType.h"

#include "ast/visitor/Visitor.h"

void tastr::ast::node::CharacterType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
