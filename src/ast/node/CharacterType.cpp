#include "ast/node/CharacterType.h"

#include "ast/visitor/Visitor.h"

void rtype::ast::node::CharacterType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
