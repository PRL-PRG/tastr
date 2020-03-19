#include "ast/LanguageTypeNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::LanguageTypeNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::LanguageTypeNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}

const tastr::ast::Node::Kind tastr::ast::LanguageTypeNode::kind_ =
    tastr::ast::Node::Kind::LanguageType;
