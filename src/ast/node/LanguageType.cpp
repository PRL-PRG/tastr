#include "ast/node/LanguageType.h"
#include "ast/visitor/Visitor.h"

void tastr::ast::node::LanguageType::accept(
    tastr::ast::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
