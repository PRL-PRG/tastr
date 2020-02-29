#include "ast/NoNaTypeNode.h"

#include "visitor/Visitor.h"

void tastr::ast::NoNaTypeNode::accept(tastr::visitor::Visitor& visitor) const {
    visitor.visit(*this);
}
