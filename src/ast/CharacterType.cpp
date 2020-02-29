#include "ast/CharacterType.h"

#include "visitor/Visitor.h"

void tastr::ast::CharacterType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
