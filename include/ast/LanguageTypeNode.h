#ifndef TASTR_AST_LANGUAGE_TYPE_H
#define TASTR_AST_LANGUAGE_TYPE_H

#include "TypeNode.h"

namespace tastr::ast {

class LanguageTypeNode final: public TypeNode {
  public:
    LanguageTypeNode(const std::string& identifier)
        : TypeNode(), identifier_(identifier) {
    }

    ~LanguageTypeNode() = default;

    LanguageTypeNode(const LanguageTypeNode& node)
        : TypeNode(node), identifier_(node.identifier_) {
    }

    LanguageTypeNode(LanguageTypeNode&& node)
        : TypeNode(std::move(node)), identifier_(std::move(node.identifier_)) {
    }

    LanguageTypeNode& operator=(const LanguageTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        identifier_ = node.identifier_;
        return *this;
    }

    LanguageTypeNode& operator=(LanguageTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        identifier_ = std::move(node.identifier_);
        return *this;
    }

    void accept(tastr::visitor::Visitor& visitor) const override final;

    std::unique_ptr<LanguageTypeNode> clone() const {
        return std::unique_ptr<LanguageTypeNode>(this->clone_impl());
    }

    bool is_language_type_node() const override final {
        return true;
    }

    const std::string& get_identifier() const {
        return identifier_;
    }

  private:
    virtual LanguageTypeNode* clone_impl() const override final {
        return new LanguageTypeNode(*this);
    };

    std::string identifier_;
};

using LanguageTypeNodePtr = LanguageTypeNode*;
using LanguageTypeNodeUPtr = std::unique_ptr<LanguageTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LANGUAGE_TYPE_H */
