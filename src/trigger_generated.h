// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TRIGGER_H_
#define FLATBUFFERS_GENERATED_TRIGGER_H_

#include "flatbuffers/flatbuffers.h"

struct Trigger;

struct TriggerPacket;

enum TriggerSource {
  TriggerSource_TimestampReset = 0,
  TriggerSource_ExternalSignalRisingEdge = 1,
  TriggerSource_ExternalSignalFallingEdge = 2,
  TriggerSource_ExternalSignalPulse = 3,
  TriggerSource_ExternalGeneratorRisingEdge = 4,
  TriggerSource_ExternalGeneratorFallingEdge = 5,
  TriggerSource_FrameBegin = 6,
  TriggerSource_FrameEnd = 7,
  TriggerSource_ExposureBegin = 8,
  TriggerSource_ExposureEnd = 9,
  TriggerSource_MIN = TriggerSource_TimestampReset,
  TriggerSource_MAX = TriggerSource_ExposureEnd
};

inline const TriggerSource (&EnumValuesTriggerSource())[10] {
  static const TriggerSource values[] = {
    TriggerSource_TimestampReset,
    TriggerSource_ExternalSignalRisingEdge,
    TriggerSource_ExternalSignalFallingEdge,
    TriggerSource_ExternalSignalPulse,
    TriggerSource_ExternalGeneratorRisingEdge,
    TriggerSource_ExternalGeneratorFallingEdge,
    TriggerSource_FrameBegin,
    TriggerSource_FrameEnd,
    TriggerSource_ExposureBegin,
    TriggerSource_ExposureEnd
  };
  return values;
}

inline const char * const *EnumNamesTriggerSource() {
  static const char * const names[] = {
    "TimestampReset",
    "ExternalSignalRisingEdge",
    "ExternalSignalFallingEdge",
    "ExternalSignalPulse",
    "ExternalGeneratorRisingEdge",
    "ExternalGeneratorFallingEdge",
    "FrameBegin",
    "FrameEnd",
    "ExposureBegin",
    "ExposureEnd",
    nullptr
  };
  return names;
}

inline const char *EnumNameTriggerSource(TriggerSource e) {
  if (e < TriggerSource_TimestampReset || e > TriggerSource_ExposureEnd) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesTriggerSource()[index];
}

struct Trigger FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_T = 4,
    VT_SOURCE = 6
  };
  int64_t t() const {
    return GetField<int64_t>(VT_T, 0);
  }
  TriggerSource source() const {
    return static_cast<TriggerSource>(GetField<int8_t>(VT_SOURCE, 0));
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int64_t>(verifier, VT_T) &&
           VerifyField<int8_t>(verifier, VT_SOURCE) &&
           verifier.EndTable();
  }
};

struct TriggerBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_t(int64_t t) {
    fbb_.AddElement<int64_t>(Trigger::VT_T, t, 0);
  }
  void add_source(TriggerSource source) {
    fbb_.AddElement<int8_t>(Trigger::VT_SOURCE, static_cast<int8_t>(source), 0);
  }
  explicit TriggerBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TriggerBuilder &operator=(const TriggerBuilder &);
  flatbuffers::Offset<Trigger> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Trigger>(end);
    return o;
  }
};

inline flatbuffers::Offset<Trigger> CreateTrigger(
    flatbuffers::FlatBufferBuilder &_fbb,
    int64_t t = 0,
    TriggerSource source = TriggerSource_TimestampReset) {
  TriggerBuilder builder_(_fbb);
  builder_.add_t(t);
  builder_.add_source(source);
  return builder_.Finish();
}

struct TriggerPacket FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ELEMENTS = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<Trigger>> *elements() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<Trigger>> *>(VT_ELEMENTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ELEMENTS) &&
           verifier.VerifyVector(elements()) &&
           verifier.VerifyVectorOfTables(elements()) &&
           verifier.EndTable();
  }
};

struct TriggerPacketBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_elements(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Trigger>>> elements) {
    fbb_.AddOffset(TriggerPacket::VT_ELEMENTS, elements);
  }
  explicit TriggerPacketBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  TriggerPacketBuilder &operator=(const TriggerPacketBuilder &);
  flatbuffers::Offset<TriggerPacket> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<TriggerPacket>(end);
    return o;
  }
};

inline flatbuffers::Offset<TriggerPacket> CreateTriggerPacket(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<Trigger>>> elements = 0) {
  TriggerPacketBuilder builder_(_fbb);
  builder_.add_elements(elements);
  return builder_.Finish();
}

inline flatbuffers::Offset<TriggerPacket> CreateTriggerPacketDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<Trigger>> *elements = nullptr) {
  auto elements__ = elements ? _fbb.CreateVector<flatbuffers::Offset<Trigger>>(*elements) : 0;
  return CreateTriggerPacket(
      _fbb,
      elements__);
}

inline const TriggerPacket *GetTriggerPacket(const void *buf) {
  return flatbuffers::GetRoot<TriggerPacket>(buf);
}

inline const TriggerPacket *GetSizePrefixedTriggerPacket(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<TriggerPacket>(buf);
}

inline bool VerifyTriggerPacketBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<TriggerPacket>(nullptr);
}

inline bool VerifySizePrefixedTriggerPacketBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<TriggerPacket>(nullptr);
}

inline void FinishTriggerPacketBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<TriggerPacket> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedTriggerPacketBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<TriggerPacket> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_TRIGGER_H_