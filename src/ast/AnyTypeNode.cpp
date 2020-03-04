#include "ast/AnyTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::AnyTypeNode::accept(tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
