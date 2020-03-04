#include "ast/LanguageTypeNode.hpp"
#include "visitor/Visitor.hpp"

void tastr::ast::LanguageTypeNode::accept(
    tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
