#include "ast/AnyTypeNode.hpp"

#include "visitor/Visitor.hpp"

void tastr::ast::AnyTypeNode::accept(tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
