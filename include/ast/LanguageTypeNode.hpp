#ifndef TASTR_AST_LANGUAGE_TYPE_NODE_HPP
#define TASTR_AST_LANGUAGE_TYPE_NODE_HPP

#include "ast/Keyword.hpp"
#include "ast/TypeNode.hpp"

namespace tastr::ast {

class LanguageTypeNode final: public TypeNode {
  public:
    explicit LanguageTypeNode(const Keyword& keyword)
        : TypeNode(), keyword_(keyword) {
    }

    ~LanguageTypeNode() = default;

    LanguageTypeNode(const LanguageTypeNode& node)
        : TypeNode(node), keyword_(node.keyword_) {
    }

    LanguageTypeNode(LanguageTypeNode&& node)
        : TypeNode(std::move(node)), keyword_(std::move(node.keyword_)) {
    }

    LanguageTypeNode& operator=(const LanguageTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_;
        return *this;
    }

    LanguageTypeNode& operator=(LanguageTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<LanguageTypeNode> clone() const {
        return std::unique_ptr<LanguageTypeNode>(this->clone_impl());
    }

    bool is_language_type_node() const override final {
        return true;
    }

    const Keyword& get_keyword() const {
        return keyword_;
    }

  private:
    virtual LanguageTypeNode* clone_impl() const override final {
        return new LanguageTypeNode(*this);
    }

    Keyword keyword_;
};

using LanguageTypeNodePtr = LanguageTypeNode*;
using LanguageTypeNodeUPtr = std::unique_ptr<LanguageTypeNode>;

} // namespace tastr::ast

#endif /* TASTR_AST_LANGUAGE_TYPE_NODE_HPP */
