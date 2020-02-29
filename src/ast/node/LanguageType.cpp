#include "ast/node/LanguageType.h"
#include "ast/visitor/Visitor.h"

void rtype::ast::node::LanguageType::accept(
    rtype::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
