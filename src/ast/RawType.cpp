#include "ast/RawType.h"

#include "visitor/Visitor.h"

void tastr::ast::RawType::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
