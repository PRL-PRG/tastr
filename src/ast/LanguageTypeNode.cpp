#include "ast/LanguageTypeNode.h"
#include "visitor/Visitor.h"

void tastr::ast::LanguageTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
