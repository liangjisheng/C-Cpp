// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: person.proto

#ifndef PROTOBUF_INCLUDED_person_2eproto
#define PROTOBUF_INCLUDED_person_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_person_2eproto 

namespace protobuf_person_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_person_2eproto
namespace Test {
class Person;
class PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
class PersonInfo;
class PersonInfoDefaultTypeInternal;
extern PersonInfoDefaultTypeInternal _PersonInfo_default_instance_;
}  // namespace Test
namespace google {
namespace protobuf {
template<> ::Test::Person* Arena::CreateMaybeMessage<::Test::Person>(Arena*);
template<> ::Test::PersonInfo* Arena::CreateMaybeMessage<::Test::PersonInfo>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace Test {

// ===================================================================

class PersonInfo : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Test.PersonInfo) */ {
 public:
  PersonInfo();
  virtual ~PersonInfo();

  PersonInfo(const PersonInfo& from);

  inline PersonInfo& operator=(const PersonInfo& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  PersonInfo(PersonInfo&& from) noexcept
    : PersonInfo() {
    *this = ::std::move(from);
  }

  inline PersonInfo& operator=(PersonInfo&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PersonInfo& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const PersonInfo* internal_default_instance() {
    return reinterpret_cast<const PersonInfo*>(
               &_PersonInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(PersonInfo* other);
  friend void swap(PersonInfo& a, PersonInfo& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline PersonInfo* New() const final {
    return CreateMaybeMessage<PersonInfo>(NULL);
  }

  PersonInfo* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<PersonInfo>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const PersonInfo& from);
  void MergeFrom(const PersonInfo& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PersonInfo* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated int64 phone_num = 3;
  int phone_num_size() const;
  void clear_phone_num();
  static const int kPhoneNumFieldNumber = 3;
  ::google::protobuf::int64 phone_num(int index) const;
  void set_phone_num(int index, ::google::protobuf::int64 value);
  void add_phone_num(::google::protobuf::int64 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
      phone_num() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
      mutable_phone_num();

  // required string name = 1;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // required int64 age = 2;
  bool has_age() const;
  void clear_age();
  static const int kAgeFieldNumber = 2;
  ::google::protobuf::int64 age() const;
  void set_age(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:Test.PersonInfo)
 private:
  void set_has_name();
  void clear_has_name();
  void set_has_age();
  void clear_has_age();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int64 > phone_num_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int64 age_;
  friend struct ::protobuf_person_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Person : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Test.Person) */ {
 public:
  Person();
  virtual ~Person();

  Person(const Person& from);

  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Person(Person&& from) noexcept
    : Person() {
    *this = ::std::move(from);
  }

  inline Person& operator=(Person&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Person& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Person* internal_default_instance() {
    return reinterpret_cast<const Person*>(
               &_Person_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Person* other);
  friend void swap(Person& a, Person& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Person* New() const final {
    return CreateMaybeMessage<Person>(NULL);
  }

  Person* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Person>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Person& from);
  void MergeFrom(const Person& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Person* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .Test.PersonInfo people = 1;
  int people_size() const;
  void clear_people();
  static const int kPeopleFieldNumber = 1;
  ::Test::PersonInfo* mutable_people(int index);
  ::google::protobuf::RepeatedPtrField< ::Test::PersonInfo >*
      mutable_people();
  const ::Test::PersonInfo& people(int index) const;
  ::Test::PersonInfo* add_people();
  const ::google::protobuf::RepeatedPtrField< ::Test::PersonInfo >&
      people() const;

  // @@protoc_insertion_point(class_scope:Test.Person)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::Test::PersonInfo > people_;
  friend struct ::protobuf_person_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PersonInfo

// required string name = 1;
inline bool PersonInfo::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PersonInfo::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PersonInfo::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PersonInfo::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& PersonInfo::name() const {
  // @@protoc_insertion_point(field_get:Test.PersonInfo.name)
  return name_.GetNoArena();
}
inline void PersonInfo::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Test.PersonInfo.name)
}
#if LANG_CXX11
inline void PersonInfo::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Test.PersonInfo.name)
}
#endif
inline void PersonInfo::set_name(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Test.PersonInfo.name)
}
inline void PersonInfo::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Test.PersonInfo.name)
}
inline ::std::string* PersonInfo::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:Test.PersonInfo.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* PersonInfo::release_name() {
  // @@protoc_insertion_point(field_release:Test.PersonInfo.name)
  if (!has_name()) {
    return NULL;
  }
  clear_has_name();
  return name_.ReleaseNonDefaultNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void PersonInfo::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Test.PersonInfo.name)
}

// required int64 age = 2;
inline bool PersonInfo::has_age() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PersonInfo::set_has_age() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PersonInfo::clear_has_age() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PersonInfo::clear_age() {
  age_ = GOOGLE_LONGLONG(0);
  clear_has_age();
}
inline ::google::protobuf::int64 PersonInfo::age() const {
  // @@protoc_insertion_point(field_get:Test.PersonInfo.age)
  return age_;
}
inline void PersonInfo::set_age(::google::protobuf::int64 value) {
  set_has_age();
  age_ = value;
  // @@protoc_insertion_point(field_set:Test.PersonInfo.age)
}

// repeated int64 phone_num = 3;
inline int PersonInfo::phone_num_size() const {
  return phone_num_.size();
}
inline void PersonInfo::clear_phone_num() {
  phone_num_.Clear();
}
inline ::google::protobuf::int64 PersonInfo::phone_num(int index) const {
  // @@protoc_insertion_point(field_get:Test.PersonInfo.phone_num)
  return phone_num_.Get(index);
}
inline void PersonInfo::set_phone_num(int index, ::google::protobuf::int64 value) {
  phone_num_.Set(index, value);
  // @@protoc_insertion_point(field_set:Test.PersonInfo.phone_num)
}
inline void PersonInfo::add_phone_num(::google::protobuf::int64 value) {
  phone_num_.Add(value);
  // @@protoc_insertion_point(field_add:Test.PersonInfo.phone_num)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
PersonInfo::phone_num() const {
  // @@protoc_insertion_point(field_list:Test.PersonInfo.phone_num)
  return phone_num_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
PersonInfo::mutable_phone_num() {
  // @@protoc_insertion_point(field_mutable_list:Test.PersonInfo.phone_num)
  return &phone_num_;
}

// -------------------------------------------------------------------

// Person

// repeated .Test.PersonInfo people = 1;
inline int Person::people_size() const {
  return people_.size();
}
inline void Person::clear_people() {
  people_.Clear();
}
inline ::Test::PersonInfo* Person::mutable_people(int index) {
  // @@protoc_insertion_point(field_mutable:Test.Person.people)
  return people_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::Test::PersonInfo >*
Person::mutable_people() {
  // @@protoc_insertion_point(field_mutable_list:Test.Person.people)
  return &people_;
}
inline const ::Test::PersonInfo& Person::people(int index) const {
  // @@protoc_insertion_point(field_get:Test.Person.people)
  return people_.Get(index);
}
inline ::Test::PersonInfo* Person::add_people() {
  // @@protoc_insertion_point(field_add:Test.Person.people)
  return people_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Test::PersonInfo >&
Person::people() const {
  // @@protoc_insertion_point(field_list:Test.Person.people)
  return people_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_person_2eproto
