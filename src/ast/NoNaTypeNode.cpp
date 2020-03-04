#include "ast/NoNaTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::NoNaTypeNode::accept(tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
