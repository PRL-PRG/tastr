#include "ast/LanguageType.h"
#include "visitor/Visitor.h"

void tastr::ast::LanguageType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
