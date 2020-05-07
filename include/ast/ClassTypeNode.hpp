#ifndef TASTR_AST_CLASS_TYPE_NODE_HPP
#define TASTR_AST_CLASS_TYPE_NODE_HPP

#include "ast/KeywordNode.hpp"
#include "ast/ParameterNode.hpp"
#include "ast/TypeNode.hpp"

namespace tastr {
namespace ast {

class ClassTypeNode final: public TypeNode {
  public:
    explicit ClassTypeNode(KeywordNodeUPtr keyword,
                           ParameterNodeUPtr parameters)
        : TypeNode()
        , keyword_(std::move(keyword))
        , parameters_(std::move(parameters)) {
    }

    ~ClassTypeNode() = default;

    ClassTypeNode(const ClassTypeNode& node)
        : TypeNode(node)
        , keyword_(node.keyword_->clone())
        , parameters_(node.parameters_->clone()) {
    }

    ClassTypeNode(ClassTypeNode&& node)
        : TypeNode(std::move(node))
        , keyword_(std::move(node.keyword_))
        , parameters_(std::move(node.parameters_)) {
    }

    ClassTypeNode& operator=(const ClassTypeNode& node) {
        if (&node == this) {
            return *this;
        }
        TypeNode::operator=(node);
        keyword_ = node.keyword_->clone();
        parameters_ = node.parameters_->clone();
        return *this;
    }

    ClassTypeNode& operator=(ClassTypeNode&& node) {
        TypeNode::operator=(std::move(node));
        keyword_ = std::move(node.keyword_);
        parameters_ = std::move(node.parameters_);
        return *this;
    }

    void accept(tastr::visitor::ConstNodeVisitor& visitor) const override final;

    void accept(tastr::visitor::MutableNodeVisitor& visitor) override final;

    std::unique_ptr<ClassTypeNode> clone() const {
        return std::unique_ptr<ClassTypeNode>(this->clone_impl());
    }

    Kind get_kind() const override final {
        return kind_;
    }

    const KeywordNode& get_keyword() const {
        return *keyword_.get();
    }

    const ParameterNode& get_parameters() const {
        return *parameters_.get();
    }

  private:
    virtual ClassTypeNode* clone_impl() const override final {
        return new ClassTypeNode(*this);
    };

    KeywordNodeUPtr keyword_;
    ParameterNodeUPtr parameters_;

    static const Kind kind_;
};

using ClassTypeNodePtr = ClassTypeNode*;
using ClassTypeNodeUPtr = std::unique_ptr<ClassTypeNode>;

} // namespace ast
} // namespace tastr

#endif /* TASTR_AST_CLASS_TYPE_NODE_HPP */
