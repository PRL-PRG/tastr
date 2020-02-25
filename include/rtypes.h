#ifndef R_TYPES_PARSER_RTYPES_H
#define R_TYPES_PARSER_RTYPES_H

#include "RType.h"

#include <memory>

class RTypeSequence {
  public:
    RTypeSequence() {
    }

    RTypeSequence(std::unique_ptr<RType> type) {
    }

    void push_back(std::unique_ptr<RType> type) {
    }

  private:
};

class RTypeNamedSequence {
  public:
    RTypeNamedSequence() {
    }

    RTypeNamedSequence(const std::string& name, std::unique_ptr<RType> type) {
    }

    void push_back(const std::string& name, std::unique_ptr<RType> type) {
    }

  private:
};

class ScalarRType: public RType {};
class IntegerRType: public ScalarRType {};
class DoubleRType: public ScalarRType {};
class CharacterRType: public ScalarRType {};
class RawRType: public ScalarRType {};
class ComplexRType: public ScalarRType {};
class LogicalRType: public ScalarRType {};
class CompositeRType: public RType {};
class VectorRType: public CompositeRType {
  public:
    explicit VectorRType(std::unique_ptr<RType> value_type)
        : CompositeRType(), value_type_(std::move(value_type)) {
    }

  private:
    std::unique_ptr<RType> value_type_;
};
class NoNaRType: public CompositeRType {
  public:
    explicit NoNaRType(std::unique_ptr<RType> vector_type)
        : CompositeRType(), vector_type_(std::move(vector_type)) {
    }

  private:
    std::unique_ptr<RType> vector_type_;
};
class ListRType: public CompositeRType {
  public:
    explicit ListRType(std::unique_ptr<RTypeSequence> type_sequence)
        : CompositeRType(), type_sequence_(std::move(type_sequence)) {
    }

  private:
    std::unique_ptr<RTypeSequence> type_sequence_;
};
class StructRType: public CompositeRType {
  public:
    explicit StructRType(
        std::unique_ptr<RTypeNamedSequence> named_type_sequence)
        : CompositeRType()
        , named_type_sequence_(std::move(named_type_sequence)) {
    }

  private:
    std::unique_ptr<RTypeNamedSequence> named_type_sequence_;
};
class UnionRType: public CompositeRType {
  public:
    explicit UnionRType(std::unique_ptr<RType> left_type,
                        std::unique_ptr<RType> right_type)
        : CompositeRType()
        , left_type_(std::move(left_type))
        , right_type_(std::move(right_type)) {
    }

  private:
    std::unique_ptr<RType> left_type_;
    std::unique_ptr<RType> right_type_;
};

class FunctionRType: public CompositeRType {
  public:
    explicit FunctionRType(std::unique_ptr<RTypeSequence> parameter_types,
                           std::unique_ptr<RType> return_type)
        : CompositeRType()
        , parameter_types_(std::move(parameter_types))
        , return_type_(std::move(return_type)) {
    }

  private:
    std::unique_ptr<RTypeSequence> parameter_types_;
    std::unique_ptr<RType> return_type_;
};

class GroupRType: public CompositeRType {
  public:
    explicit GroupRType(std::unique_ptr<RType> base_type)
        : CompositeRType(), base_type_(std::move(base_type)) {
    }

  private:
    std::unique_ptr<RType> base_type_;
};

inline std::ostream& operator<<(std::ostream& os, const RType& type) {
    return os;
}

#endif /* R_TYPES_PARSER_RTYPES_H */
