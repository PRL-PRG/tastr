#include "ast/KeywordNode.hpp"

#include "visitor/visitor.hpp"

void tastr::ast::KeywordNode::accept(
    tastr::visitor::ConstNodeVisitor& visitor) const {
    visitor.visit(*this);
}

void tastr::ast::KeywordNode::accept(
    tastr::visitor::MutableNodeVisitor& visitor) {
    visitor.visit(*this);
}
