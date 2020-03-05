#include "ast/LanguageTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::LanguageTypeNode::accept(
    tastr::visitor::ConstVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::LanguageTypeNode::accept(
    tastr::visitor::MutableVisitor& visitor) {
    visitor.visit(*this);
}
