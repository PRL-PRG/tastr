#include "ast/node/CharacterType.h"

#include "ast/visitor/TypeVisitor.h"

void rtype::ast::node::CharacterType::accept(
    rtype::ast::visitor::TypeVisitor& visitor) const {
    visitor.visit(*this);
}
