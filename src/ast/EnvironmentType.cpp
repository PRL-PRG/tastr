#include "ast/EnvironmentType.h"
#include "visitor/Visitor.h"

void tastr::ast::EnvironmentType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
